#include "types.h"
#include "config.h"
#include "debug.h"
#include "alloc-inl.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <dirent.h>
#include <ctype.h>
#include <fcntl.h>
#include <termios.h>
#include <dlfcn.h>
#include <sched.h>

#include <sys/wait.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/file.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "generator.h"

static u8 *in_bitmap; /* Input bitmap                     */

static s32 shm_id;     /* ID of the SHM region             */
static u8 *trace_bits; /* SHM with instrumentation bitmap  */

static u8 virgin_bits[MAP_SIZE], /* Regions yet untouched by fuzzing */
    virgin_tmout[MAP_SIZE],      /* Bits we haven't seen in tmouts   */
    virgin_crash[MAP_SIZE];      /* Bits we haven't seen in crashes  */

static s32 forksrv_pid, /* PID of the fork server           */
    child_pid = -1;     /* PID of the fuzzed program        */

u64 mem_limit = MEM_LIMIT;            /* Memory cap for child (MB)        */
static u32 exec_tmout = EXEC_TIMEOUT; /* Configurable exec timeout (ms)   */

static s32 out_fd, /* Persistent fd for out_file       */
    dev_null_fd,
    fsrv_ctl_fd, /* Fork server control pipe (write) */
    fsrv_st_fd,
    coverage_fd; /* Fork server status pipe (read)   */

static volatile u8 stop_soon, /* Ctrl-C pressed?                  */
    clear_screen = 1,         /* Window resized?                  */
    child_timed_out,          /* Traced process timed out?        */
    term_too_small;           /* terminal dimensions too small    */

static u8 uses_asan,
    skip_requested,
    kill_signal,
    bitmap_changed = 1; /* Time to update bitmap?           */

static u64 slowest_exec_ms; /* Slowest testcase non hang in ms  */

enum
{
    DUMB,
    GUIDE_MUTATE
};

// fuzz 的状态
typedef struct GlobalState
{
    int fuzz_stage;                //当前fuzz处于的阶段
    int cur_guide_idx;             //当前变异的是第几个样本，仅在guide_mutate下使用
    time_t start_no_new_bits_time; //未出现新路径开始的时间
    int total_execs;               //总共执行次数
    int total_samples;             //总共的样本个数
    int crash_counts;              //样本崩溃次数
    double coverage;               //覆盖率
} GlobalState;

GlobalState global_state;

enum
{
    /* 00 */ FAULT_NONE,
    /* 01 */ FAULT_TMOUT,
    /* 02 */ FAULT_CRASH,
    /* 03 */ FAULT_ERROR,
    /* 04 */ FAULT_NOINST,
    /* 05 */ FAULT_NOBITS
};

/* Destructively classify execution counts in a trace. This is used as a
   preprocessing step for any newly acquired traces. Called on every exec,
   must be fast. */

static const u8 count_class_lookup8[256] = {

    [0] = 0,
    [1] = 1,
    [2] = 2,
    [3] = 4,
    [4 ... 7] = 8,
    [8 ... 15] = 16,
    [16 ... 31] = 32,
    [32 ... 127] = 64,
    [128 ... 255] = 128

};

static u16 count_class_lookup16[65536];

static void init_count_class16(void)
{

    u32 b1, b2;

    for (b1 = 0; b1 < 256; b1++)
        for (b2 = 0; b2 < 256; b2++)
            count_class_lookup16[(b1 << 8) + b2] =
                (count_class_lookup8[b1] << 8) |
                count_class_lookup8[b2];
}

#ifdef WORD_SIZE_64

static inline void classify_counts(u64 *mem)
{

    u32 i = MAP_SIZE >> 3;

    while (i--)
    {

        /* Optimize for sparse bitmaps. */

        if (unlikely(*mem))
        {

            u16 *mem16 = (u16 *)mem;

            mem16[0] = count_class_lookup16[mem16[0]];
            mem16[1] = count_class_lookup16[mem16[1]];
            mem16[2] = count_class_lookup16[mem16[2]];
            mem16[3] = count_class_lookup16[mem16[3]];
        }

        mem++;
    }
}

#else

static inline void classify_counts(u32 *mem)
{

    u32 i = MAP_SIZE >> 2;

    while (i--)
    {

        /* Optimize for sparse bitmaps. */

        if (unlikely(*mem))
        {

            u16 *mem16 = (u16 *)mem;

            mem16[0] = count_class_lookup16[mem16[0]];
            mem16[1] = count_class_lookup16[mem16[1]];
        }

        mem++;
    }
}

#endif /* ^WORD_SIZE_64 */

/* Get rid of shared memory (atexit handler). */
static void remove_shm(void)
{
    shmctl(shm_id, IPC_RMID, NULL);
}

/* Configure shared memory. */
static void setup_shm(void)
{
    u8 *shm_str;

    if (!in_bitmap)
        memset(virgin_bits, 255, MAP_SIZE);

    memset(virgin_tmout, 255, MAP_SIZE);
    memset(virgin_crash, 255, MAP_SIZE);

    shm_id = shmget(IPC_PRIVATE, MAP_SIZE, IPC_CREAT | IPC_EXCL | 0600);
    if (shm_id < 0)
        PFATAL("shmget() failed");
    atexit(remove_shm);
    shm_str = alloc_printf("%d", shm_id);
    setenv(SHM_ENV_VAR, shm_str, 1);
    ck_free(shm_str);
    trace_bits = shmat(shm_id, NULL, 0);
    if (trace_bits == (void *)-1)
        PFATAL("shmat() failed");
}

/* Handle stop signal (Ctrl-C, etc). */

static void handle_stop_sig(int sig)
{

    stop_soon = 1;

    if (child_pid > 0)
        kill(child_pid, SIGKILL);
    if (forksrv_pid > 0)
        kill(forksrv_pid, SIGKILL);
}

/* Handle skip request (SIGUSR1). */

static void handle_skipreq(int sig)
{
    skip_requested = 1;
}

/* Handle timeout (SIGALRM). */

static void handle_timeout(int sig)
{

    if (child_pid > 0)
    {

        child_timed_out = 1;
        kill(child_pid, SIGKILL);
    }
    else if (child_pid == -1 && forksrv_pid > 0)
    {

        child_timed_out = 1;
        kill(forksrv_pid, SIGKILL);
    }
}

/* Handle screen resize (SIGWINCH). */

static void handle_resize(int sig)
{
    clear_screen = 1;
}

/* Set up signal handlers. More complicated that needs to be, because libc on
   Solaris doesn't resume interrupted reads(), sets SA_RESETHAND when you call
   siginterrupt(), and does other unnecessary things. */
static void setup_signal_handlers(void)
{

    struct sigaction sa;

    sa.sa_handler = NULL;
    sa.sa_flags = SA_RESTART;
    sa.sa_sigaction = NULL;

    sigemptyset(&sa.sa_mask);

    /* Various ways of saying "stop". */

    sa.sa_handler = handle_stop_sig;
    sigaction(SIGHUP, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    /* Exec timeout notifications. */

    sa.sa_handler = handle_timeout;
    sigaction(SIGALRM, &sa, NULL);

    /* Window resize */

    sa.sa_handler = handle_resize;
    sigaction(SIGWINCH, &sa, NULL);

    /* SIGUSR1: skip entry */

    sa.sa_handler = handle_skipreq;
    sigaction(SIGUSR1, &sa, NULL);

    /* Things we don't care about. */

    sa.sa_handler = SIG_IGN;
    sigaction(SIGTSTP, &sa, NULL);
    sigaction(SIGPIPE, &sa, NULL);
}

char url[0x200] = {0};
char rdp[0x200] = {0};
char user_data_path[0x1000] = {0};
int server_port;
int rdp_port;
char *output_dir;
char *node_name;

char *chrome_path;
/*初始化插桩到程序内部的forkserver*/
static void init_forkserver()
{
    static struct itimerval it;
    //服务端管道和客户端管道
    int st_pipe[2], ctl_pipe[2];
    int status;
    s32 rlen;

    if (pipe(st_pipe) || pipe(ctl_pipe))
        PFATAL("pipe() failed");
    forksrv_pid = fork();
    if (forksrv_pid < 0)
        PFATAL("fork() failed");
    //子进程
    if (!forksrv_pid)
    {
        struct rlimit r;

        /* Umpf. On OpenBSD, the default fd limit for root users is set to
       soft 128. Let's try to fix that... */
        if (!getrlimit(RLIMIT_NOFILE, &r) && r.rlim_cur < FORKSRV_FD + 2)
        {
            r.rlim_cur = FORKSRV_FD + 2;
            setrlimit(RLIMIT_NOFILE, &r); /* Ignore errors */
        }

        /* Dumping cores is slow and can lead to anomalies if SIGKILL is delivered
       before the dump is complete. */
        r.rlim_max = r.rlim_cur = 0;
        setrlimit(RLIMIT_CORE, &r); /* Ignore errors */
        /* Isolate the process and configure standard descriptors. If out_file is
       specified, stdin is /dev/null; otherwise, out_fd is cloned instead. */
        setsid();
        //将程序的输出重定向到文件中
        dup2(out_fd, 1);
        dup2(out_fd, 2);

        //关闭标准输入
        dup2(dev_null_fd, 0);
        /* Set up control and status pipes, close the unneeded original fds. */

        if (dup2(ctl_pipe[0], FORKSRV_FD) < 0)
            PFATAL("dup2() failed");
        if (dup2(st_pipe[1], FORKSRV_FD + 1) < 0)
            PFATAL("dup2() failed");

        close(ctl_pipe[0]);
        close(ctl_pipe[1]);
        close(st_pipe[0]);
        close(st_pipe[1]);
        close(dev_null_fd);
        close(out_fd);

        /* This should improve performance a bit, since it stops the linker from
       doing extra work post-fork(). */

        if (!getenv("LD_BIND_LAZY"))
            setenv("LD_BIND_NOW", "1", 0);
        /* Set sane defaults for ASAN if nothing else specified. */

        setenv("ASAN_OPTIONS", "abort_on_error=1:"
                               "detect_leaks=0:"
                               "symbolize=0:"
                               "allocator_may_return_null=1",
               0);

        /* MSAN is tricky, because it doesn't support abort_on_error=1 at this
       point. So, we do this in a very hacky way. */

        setenv("MSAN_OPTIONS", "exit_code=" STRINGIFY(MSAN_ERROR) ":"
                                                                  "symbolize=0:"
                                                                  "abort_on_error=1:"
                                                                  "allocator_may_return_null=1:"
                                                                  "msan_track_origins=0",
               0);
        sprintf(url, "http://127.0.0.1:%d", server_port);
        sprintf(user_data_path, "--user-data-dir=%s/%s/userdata", output_dir, node_name);
        sprintf(rdp,"--remote-debugging-port=%d",rdp_port);

        //char *argv[] = {"./chrome", "--no-sandbox","--enable-logging", user_data_path, "--headless", "--disable-gpu",rdp , url, NULL};
        char *argv[] = {"./chrome", "--no-sandbox", "--enable-logging", user_data_path, url, NULL};
        execv(chrome_path, argv);
        /* Use a distinctive bitmap signature to tell the parent about execv()
       falling through. */
        *(u32 *)trace_bits = EXEC_FAIL_SIG;
        exit(0);
    }

    /* Close the unneeded endpoints. */
    close(ctl_pipe[0]);
    close(st_pipe[1]);

    fsrv_ctl_fd = ctl_pipe[1];
    fsrv_st_fd = st_pipe[0];
    /* Wait for the fork server to come up, but don't wait too long. */

    it.it_value.tv_sec = ((exec_tmout * FORK_WAIT_MULT) / 1000);
    it.it_value.tv_usec = ((exec_tmout * FORK_WAIT_MULT) % 1000) * 1000;
    //等待fork_server
    setitimer(ITIMER_REAL, &it, NULL);
    rlen = read(fsrv_st_fd, &status, 4);
    //取消计时
    it.it_value.tv_sec = 0;
    it.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &it, NULL);

    if (rlen == 4)
    {
        OKF("All right - fork server is up.");
        return;
    }
    if (child_timed_out)
        FATAL("Timeout while initializing fork server (adjusting -t may help)");

    if (waitpid(forksrv_pid, &status, 0) <= 0)
        PFATAL("waitpid() failed");

    FATAL("Fork server crashed with signal %d", WTERMSIG(status));
    if (*(u32 *)trace_bits == EXEC_FAIL_SIG)
        FATAL("Unable to execute target application");
    FATAL("Fork server handshake failed");
}

/* Execute target application, monitoring for timeouts. Return status
   information. The called program will update trace_bits[]. */

static u8 run_target(u32 timeout)
{

    static struct itimerval it;
    static u32 prev_timed_out = 0;
    static u64 exec_ms = 0;

    int status = 0;
    u32 tb4;

    child_timed_out = 0;

    /* After this memset, trace_bits[] are effectively volatile, so we
     must prevent any earlier operations from venturing into that
     territory. */
    memset(trace_bits, 0, MAP_SIZE);
    MEM_BARRIER();

    s32 res;
    /* In non-dumb mode, we have the fork server up and running, so simply
       tell it to have at it, and then read back PID. */
    if ((res = write(fsrv_ctl_fd, &prev_timed_out, 4)) != 4)
    {
        if (stop_soon)
            return 0;
        RPFATAL(res, "Unable to request new process from fork server (OOM?)");
    }

    if ((res = read(fsrv_st_fd, &child_pid, 4)) != 4)
    {
        if (stop_soon)
            return 0;
        RPFATAL(res, "Unable to request new process from fork server (OOM?)");
    }

    if (child_pid <= 0)
        FATAL("Fork server is misbehaving (OOM?)");

    /* Configure timeout, as requested by user, then wait for child to terminate. */

    it.it_value.tv_sec = (timeout / 1000);
    it.it_value.tv_usec = (timeout % 1000) * 1000;

    setitimer(ITIMER_REAL, &it, NULL);

    /* The SIGALRM handler simply kills the child_pid and sets child_timed_out. */
    if ((res = read(fsrv_st_fd, &status, 4)) != 4)
    {

        if (stop_soon)
            return 0;
        RPFATAL(res, "Unable to communicate with fork server (OOM?)");
    }

    if (!WIFSTOPPED(status))
        child_pid = 0;

    getitimer(ITIMER_REAL, &it);
    exec_ms = (u64)timeout - (it.it_value.tv_sec * 1000 +
                              it.it_value.tv_usec / 1000);

    it.it_value.tv_sec = 0;
    it.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &it, NULL);

    ++global_state.total_execs;

    /* Any subsequent operations on trace_bits must not be moved by the
     compiler below this point. Past this location, trace_bits[] behave
     very normally and do not have to be treated as volatile. */

    MEM_BARRIER();

    tb4 = *(u32 *)trace_bits;

#ifdef WORD_SIZE_64
    classify_counts((u64 *)trace_bits);
#else
    classify_counts((u32 *)trace_bits);
#endif /* ^WORD_SIZE_64 */

    prev_timed_out = child_timed_out;

    /* Report outcome to caller. */

    if (WIFSIGNALED(status) && !stop_soon)
    {

        kill_signal = WTERMSIG(status);

        if (child_timed_out && kill_signal == SIGKILL)
            return FAULT_TMOUT;

        return FAULT_CRASH;
    }

    /* A somewhat nasty hack for MSAN, which doesn't support abort_on_error and
     must use a special exit code. */

    if (uses_asan && WEXITSTATUS(status) == MSAN_ERROR)
    {
        kill_signal = 0;
        return FAULT_CRASH;
    }

    /* It makes sense to account for the slowest units only if the testcase was run
  under the user defined timeout. */
    if (!(timeout > exec_tmout) && (slowest_exec_ms < exec_ms))
    {
        slowest_exec_ms = exec_ms;
    }

    return FAULT_NONE;
}

/* Check if the current execution path brings anything new to the table.
   Update virgin bits to reflect the finds. Returns 1 if the only change is
   the hit-count for a particular tuple; 2 if there are new tuples seen.
   Updates the map, so subsequent calls will always return 0.

   This function is called after every exec() on a fairly large buffer, so
   it needs to be fast. We do this in 32-bit and 64-bit flavors. */

static inline u8 has_new_bits(u8 *virgin_map)
{

#ifdef WORD_SIZE_64

    u64 *current = (u64 *)trace_bits;
    u64 *virgin = (u64 *)virgin_map;

    u32 i = (MAP_SIZE >> 3);

#else

    u32 *current = (u32 *)trace_bits;
    u32 *virgin = (u32 *)virgin_map;

    u32 i = (MAP_SIZE >> 2);

#endif /* ^WORD_SIZE_64 */

    u8 ret = 0;

    while (i--)
    {

        /* Optimize for (*current & *virgin) == 0 - i.e., no bits in current bitmap
       that have not been already cleared from the virgin map - since this will
       almost always be the case. */

        if (unlikely(*current) && unlikely(*current & *virgin))
        {

            if (likely(ret < 2))
            {

                u8 *cur = (u8 *)current;
                u8 *vir = (u8 *)virgin;

                /* Looks like we have not found any new bytes yet; see if any non-zero
           bytes in current[] are pristine in virgin[]. */

#ifdef WORD_SIZE_64

                if ((cur[0] && vir[0] == 0xff) || (cur[1] && vir[1] == 0xff) ||
                    (cur[2] && vir[2] == 0xff) || (cur[3] && vir[3] == 0xff) ||
                    (cur[4] && vir[4] == 0xff) || (cur[5] && vir[5] == 0xff) ||
                    (cur[6] && vir[6] == 0xff) || (cur[7] && vir[7] == 0xff))
                    ret = 2;
                else
                    ret = 1;

#else

                if ((cur[0] && vir[0] == 0xff) || (cur[1] && vir[1] == 0xff) ||
                    (cur[2] && vir[2] == 0xff) || (cur[3] && vir[3] == 0xff))
                    ret = 2;
                else
                    ret = 1;

#endif /* ^WORD_SIZE_64 */
            }

            *virgin &= ~*current;
        }

        current++;
        virgin++;
    }

    if (ret && virgin_map == virgin_bits)
        bitmap_changed = 1;

    return ret;
}

#define FF(_b) (0xff << ((_b) << 3))

/* Count the number of bits set in the provided bitmap. Used for the status
   screen several times every second, does not have to be fast. */

static u32 count_bits(u8 *mem)
{

    u32 *ptr = (u32 *)mem;
    u32 i = (MAP_SIZE >> 2);
    u32 ret = 0;

    while (i--)
    {

        u32 v = *(ptr++);

        /* This gets called on the inverse, virgin bitmap; optimize for sparse
       data. */

        if (v == 0xffffffff)
        {
            ret += 32;
            continue;
        }

        v -= ((v >> 1) & 0x55555555);
        v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
        ret += (((v + (v >> 4)) & 0xF0F0F0F) * 0x01010101) >> 24;
    }

    return ret;
}

/* Count the number of non-255 bytes set in the bitmap. Used strictly for the
   status screen, several calls per second or so. */

static u32 count_non_255_bytes(u8 *mem)
{

    u32 *ptr = (u32 *)mem;
    u32 i = (MAP_SIZE >> 2);
    u32 ret = 0;

    while (i--)
    {

        u32 v = *(ptr++);

        /* This is called on the virgin bitmap, so optimize for the most likely
       case. */

        if (v == 0xffffffff)
            continue;
        if ((v & FF(0)) != FF(0))
            ret++;
        if ((v & FF(1)) != FF(1))
            ret++;
        if ((v & FF(2)) != FF(2))
            ret++;
        if ((v & FF(3)) != FF(3))
            ret++;
    }

    return ret;
}

#define bSTG bSTART cGRA

void check_core_pattern()
{
    /* This is Linux specific, but I don't think there's anything equivalent on
     *BSD, so we can just let it slide for now. */

    s32 fd = open("/proc/sys/kernel/core_pattern", O_RDONLY);
    u8 fchar;

    if (fd < 0)
        return;

    ACTF("Checking core_pattern...");

    if (read(fd, &fchar, 1) == 1 && fchar == '|')
    {

        SAYF("\n" cLRD "[-] " cRST
             "Hmm, your system is configured to send core dump notifications to an\n"
             "    external utility. This will cause issues: there will be an extended delay\n"
             "    between stumbling upon a crash and having this information relayed to the\n"
             "    fuzzer via the standard waitpid() API.\n\n"

             "    To avoid having crashes misinterpreted as timeouts, please log in as root\n"
             "    and temporarily modify /proc/sys/kernel/core_pattern, like so:\n\n"

             "    echo core >/proc/sys/kernel/core_pattern\n");

        if (!getenv("AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES"))
            FATAL("Pipe at the beginning of 'core_pattern'");
    }

    close(fd);
}

char buf[0x100] = {0};
int state_fd = -1;

void init_dirs()
{
    u8 *tmp = NULL;
    mkdir(output_dir, 0700);
    tmp = alloc_printf("%s/%s", output_dir, node_name);
    int stat = mkdir(tmp, 0700);
    ck_free(tmp);

    if (stat)
    {
        if (errno != EEXIST)
            PFATAL("Unable to create '%s'", output_dir);
        tmp = alloc_printf("%s/%s/state", output_dir, node_name);
        state_fd = open(tmp, O_RDWR);
        ck_free(tmp);
        if (state_fd < 0)
        {
            PFATAL("Unable to open state file");
        }
    }
    else
    {
        /*tmp = alloc_printf("%s/%s", output_dir, node_name);
        if (mkdir(tmp, 0700))
            PFATAL("Unable to create '%s'", tmp);
        ck_free(tmp);*/

        tmp = alloc_printf("%s/%s/samples", output_dir, node_name);
        if (mkdir(tmp, 0700))
            PFATAL("Unable to create '%s'", tmp);
        ck_free(tmp);
        tmp = alloc_printf("%s/%s/www", output_dir, node_name);
        if (mkdir(tmp, 0700))
            PFATAL("Unable to create '%s'", tmp);
        ck_free(tmp);
        tmp = alloc_printf("%s/%s/crashes", output_dir, node_name);
        if (mkdir(tmp, 0700))
            PFATAL("Unable to create '%s'", tmp);
        ck_free(tmp);
    }

    /* Generally useful file descriptors. */
    dev_null_fd = open("/dev/null", O_RDWR);
    if (dev_null_fd < 0)
        PFATAL("Unable to open /dev/null");

    tmp = alloc_printf("%s/%s/apprun_log.txt", output_dir, node_name);
    out_fd = open(tmp, O_RDWR | O_CREAT | O_APPEND, 0777);
    ck_free(tmp);
    if (out_fd < 0)
        PFATAL("Unable to creat out_fd");
    tmp = alloc_printf("%s/%s/coverage.txt", output_dir, node_name);
    coverage_fd = open(tmp, O_RDWR | O_CREAT | O_APPEND, 0777);
    ck_free(tmp);
    if (coverage_fd < 0)
        PFATAL("Unable to creat coverage_fd");
}

void init_state()
{
    if (state_fd != -1)
    {
        read(state_fd, &global_state, sizeof(GlobalState));
        global_state.start_no_new_bits_time = -1;
        read(state_fd, virgin_bits, MAP_SIZE);
    }
    else
    {
        u8 *tmp = alloc_printf("%s/%s/state", output_dir, node_name);
        state_fd = open(tmp, O_RDWR | O_CREAT, 0777);
        ck_free(tmp);
        if (state_fd < 0)
        {
            PFATAL("Unable to create state file");
        }
        global_state.fuzz_stage = DUMB;
        global_state.cur_guide_idx = 0;
        global_state.start_no_new_bits_time = -1;
        global_state.total_execs = 0;
        global_state.total_samples = 0;
        global_state.crash_counts = 0;
        global_state.coverage = 0.0;
    }
}

u8 new_bits;
//写锁
pthread_rwlock_t rwlock;

void dumb_one()
{
    new_bits = 0;

    sprintf(buf, "mv %s/%s/www/index.html %s/%s/www/index%d.html", output_dir, node_name, output_dir, node_name, global_state.total_execs);
    system(buf);

    sprintf(buf, "%s/%s/samples/%d.obj", output_dir, node_name, ++global_state.total_samples);
    u8 *tmp = alloc_printf("%s/%s/www/index.html", output_dir, node_name);
    generate_one(buf, tmp);
    ck_free(tmp);

    tmp = alloc_printf("current index:%d\n", global_state.total_execs + 1);
    write(out_fd,tmp,strlen(tmp));
    ck_free(tmp);
    
    if (run_target(40000) == FAULT_CRASH)
    {
        ++global_state.crash_counts;
        sprintf(buf, "cp %s/%s/www/index.html %s/%s/crashes/poc%d.html", output_dir, node_name, output_dir, node_name, global_state.crash_counts);
        system(buf);
    }
    pthread_rwlock_wrlock(&rwlock);
    new_bits = has_new_bits(virgin_bits);
    pthread_rwlock_unlock(&rwlock);

    if (new_bits == 2)
    {
        //出现新路径后，下一次需要重新计时
        global_state.start_no_new_bits_time = -1;
    }
    else
    {
        if (global_state.start_no_new_bits_time == -1) //开始计时
            global_state.start_no_new_bits_time = time(NULL);
        // 6分钟没有出现新路径，则进入覆盖率引导变异模式
        if (time(NULL) - global_state.start_no_new_bits_time > 360)
        {
            global_state.fuzz_stage = GUIDE_MUTATE;
        }
    }
}

void guide_mutate_one()
{
    //所有样本都已经遍历一次
    if (global_state.cur_guide_idx >= global_state.total_samples)
    {
        if (r_bool())
        {
            //进入dumb模式
            global_state.fuzz_stage = DUMB;
            global_state.start_no_new_bits_time = -1;
            return;
        }
        else
        {
            //回到起始点
            global_state.cur_guide_idx = 0;
        }
    }
    new_bits = 0;

    sprintf(buf, "mv %s/%s/www/index.html %s/%s/www/index%d.html", output_dir, node_name, output_dir, node_name, global_state.total_execs);
    system(buf);

    ++global_state.cur_guide_idx;
    sprintf(buf, "%s/%s/samples/%d.obj", output_dir, node_name, global_state.cur_guide_idx);
    u8 *tmp = alloc_printf("%s/%s/www/index.html", output_dir, node_name);
    mutate_one(buf, tmp);
    ck_free(tmp);

    tmp = alloc_printf("current index:%d\n", global_state.total_execs + 1);
    write(out_fd,tmp,strlen(tmp));
    ck_free(tmp);

    if (run_target(40000) == FAULT_CRASH)
    {
        ++global_state.crash_counts;
        sprintf(buf, "cp %s/%s/www/index.html %s/%s/crashes/poc%d.html", output_dir, node_name, output_dir, node_name, global_state.crash_counts);
        system(buf);
    }
    pthread_rwlock_wrlock(&rwlock);
    new_bits = has_new_bits(virgin_bits);
    pthread_rwlock_unlock(&rwlock);

    if (new_bits == 2) //新路径，保留变异后的样本
    {
        sprintf(buf, "mv %s/%s/samples/%d.obj.mutate %s/%s/samples/%d.obj", output_dir, node_name, global_state.cur_guide_idx, output_dir, node_name, global_state.cur_guide_idx);
        system(buf);
        global_state.start_no_new_bits_time = -1;
    }
    else //未发现新路径，删除变异后的样本
    {
        if (global_state.start_no_new_bits_time == -1)
        {
            global_state.start_no_new_bits_time = time(NULL);
        }
        sprintf(buf, "rm %s/%s/samples/%d.obj.mutate", output_dir, node_name, global_state.cur_guide_idx);
        system(buf);
    }
}

size_t start = 0;

void show_info()
{
    u32 t_bytes, t_bits;
    pthread_rwlock_rdlock(&rwlock);
    SAYF(TERM_CLEAR CURSOR_HIDE);
    SAYF(TERM_HOME);
    size_t end = time(NULL) - start;

    SAYF("###############DOM FUZZ LOOP 1.0########################\t\n");
    SAYF("# System Run Time: %ds\t\n",end);

    if (global_state.fuzz_stage == DUMB)
        SAYF("# Fuzz Mode: DUMB\t\n");
    else
        SAYF("# Fuzz Mode: GUIDE_MUTATE\tCurrent mutate index:%d\t\n", global_state.cur_guide_idx);
    SAYF("# New cov last %ld sec ago\t\n", global_state.start_no_new_bits_time == -1 ? 0 : (time(NULL) - global_state.start_no_new_bits_time));
    SAYF("# Total_execs: %d\tCrash_counts: %d\t\n", global_state.total_execs, global_state.crash_counts);
    SAYF("# Total_samples: %d\t", global_state.total_samples);
    t_bytes = count_non_255_bytes(virgin_bits);
    /* Compute some mildly useful bitmap stats. */
    t_bits = (MAP_SIZE << 3) - count_bits(virgin_bits);
    //覆盖率统计
    u8 *tmp = alloc_printf("time:%ds cov:%d\n", end,t_bits);
    write(coverage_fd, tmp, strlen(tmp));
    ck_free(tmp);

    SAYF("Count coverage: %0.04f\t\n", t_bytes ? (((double)t_bits) / t_bytes) : 0);
    SAYF("# new bits: %d\t\n", new_bits);
    SAYF("########################################################\t\n");
    lseek(state_fd, 0L, SEEK_SET);
    write(state_fd, &global_state, sizeof(GlobalState));
    if (bitmap_changed)
    {
        write(state_fd, virgin_bits, MAP_SIZE);
    }
    pthread_rwlock_unlock(&rwlock);
}

u8 tmp_virgin_bits[MAP_SIZE];

void *sync_bitmap(void *arg)
{
    char pathname[0x1000];
    DIR *dir;
    struct dirent *stdir;
    while (1)
    {
        // printf("syncing bitmap...\n");
        if ((dir = opendir(output_dir)) == 0)
        {
            printf("open %s failed!\n", output_dir);
            return -1;
        }

        while (1)
        {
            if ((stdir = readdir(dir)) == 0)
                break;
            if (stdir->d_type == 4) //文件夹
            {
                if (!strcmp(stdir->d_name, ".") || !strcmp(stdir->d_name, ".."))
                {
                    continue;
                }
                // printf("dir name=%s\n", stdir->d_name);
                if (strcmp(stdir->d_name, node_name))
                { //合并其他节点的覆盖率
                    sprintf(pathname, "%s/%s/state", output_dir, stdir->d_name);
                    int f = open(pathname, O_RDONLY);
                    if (f < 0)
                    {
                        //perror("sync bitmap error!");
                        puts("sync bitmap error!");
                        continue;
                    }
                    lseek(f, 0, sizeof(GlobalState));
                    memset(tmp_virgin_bits,0xFF,MAP_SIZE);
                    if (read(f, tmp_virgin_bits, MAP_SIZE) != MAP_SIZE)
                    {
                        close(f);
                        //perror("read bitmap error!");
                        puts("read bitmap error!");
                        continue;
                    }
                    pthread_rwlock_wrlock(&rwlock);
                    for (int i = 0; i < MAP_SIZE; i++)
                    {
                        virgin_bits[i] &= tmp_virgin_bits[i];
                    }
                    pthread_rwlock_unlock(&rwlock);
                    close(f);
                }
            }
        }
        closedir(dir);
        sleep(5);
    }
    return NULL;
}

void http_server()
{
    int pid = fork();
    if (pid == 0)
    {
        char cmdline[0x1000] = {0};
        sprintf(cmdline, "#!/bin/sh\ncd %s/%s/www\npython -m SimpleHTTPServer %d\n", output_dir, node_name, server_port);
        char path[0x100];
        sprintf(path, "%s/%s/run_server.sh", output_dir, node_name);
        int f = open(path, O_RDWR | O_CREAT | O_TRUNC, 0777);
        write(f, cmdline, strlen(cmdline) + 1);
        close(f);
        system(path);
        exit(0);
    }
}

pthread_t t1;

int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        printf("usage: %s output_dir node_name server_port chrome_path rdp_port\n", argv[0]);
        exit(0);
    }
    output_dir = argv[1];
    node_name = argv[2];
    server_port = atoi(argv[3]);
    chrome_path = argv[4];
    rdp_port = atoi(argv[5]);
    start = time(NULL);

    pthread_rwlock_init(&rwlock, NULL);

    check_core_pattern();
    //初始化输出文件夹
    init_dirs();
    //开启http服务器
    http_server();
    //注册信号处理
    setup_signal_handlers();
    //初始化共享内存
    setup_shm();
    //初始化状态
    init_state();
    //初始化归类器
    init_count_class16();
    init_forkserver();
    init_generator();

    pthread_create(&t1, NULL, sync_bitmap, NULL); //多进程fuzz，同步bitmap

    while (!stop_soon)
    {
        show_info();
        switch (global_state.fuzz_stage)
        {
        case DUMB:
            dumb_one();
            break;
        case GUIDE_MUTATE:
            guide_mutate_one();
            break;
        }
    }

    pthread_rwlock_destroy(&rwlock);
    /*init_generator();
    for (int i = 0; i < 10000; i++)
    {
        generate_one("1.obj");
        mutate_one("1.obj");
        printf("%d\n",i);
    }*/
    return 0;
}
