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

static s32 child_pid = -1; /* PID of the fuzzed program        */

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

// fuzz 的状态
typedef struct GlobalState
{
    int total_execs;   //总共执行次数
    int total_samples; //总共的样本个数
    int crash_counts;  //样本崩溃次数
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

/* Handle stop signal (Ctrl-C, etc). */

static void handle_stop_sig(int sig)
{

    stop_soon = 1;

    if (child_pid > 0)
        kill(child_pid, SIGKILL);
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

static int test_one(u32 timeout)
{
    static struct itimerval it;
    int status;

    child_pid = fork();
    if (child_pid < 0)
        PFATAL("fork() failed");
    //子进程
    if (!child_pid)
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

        // close(dev_null_fd);
        // close(out_fd);

        /* This should improve performance a bit, since it stops the linker from
       doing extra work post-fork(). */

        if (!getenv("LD_BIND_LAZY"))
            setenv("LD_BIND_NOW", "1", 0);
        /* Set sane defaults for ASAN if nothing else specified. */

        setenv("ASAN_OPTIONS", "abort_on_error=1:"
                               "detect_leaks=0:"
                               "symbolize=0:"
                               "detect_odr_violation=0:"
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

        char *argv[] = {"./chrome", "--enable-logging", user_data_path, url, NULL};
        execv(chrome_path, argv);
        exit(0);
    }

    it.it_value.tv_sec = (timeout / 1000);
    it.it_value.tv_usec = (timeout % 1000) * 1000;

    setitimer(ITIMER_REAL, &it, NULL);

    if (wait(&status) <= 0)
        PFATAL("wait() failed");
    if (WIFSIGNALED(status))
    {
        printf("Child process received singal %d\n", WTERMSIG(status));
    }
    return 0;
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
        global_state.total_execs = 0;
        global_state.total_samples = 0;
        global_state.crash_counts = 0;
    }
}

void dumb_one()
{
    if (global_state.total_samples)
    {
        sprintf(buf, "mv %s/%s/www/index.html %s/%s/www/index%d.html", output_dir, node_name, output_dir, node_name, global_state.total_samples);
        system(buf);
    }

    sprintf(buf, "%s/%s/samples/%d.obj", output_dir, node_name, ++global_state.total_samples);
    u8 *tmp = alloc_printf("%s/%s/www/index.html", output_dir, node_name);
    generate_one(buf, tmp);
    ck_free(tmp);

    tmp = alloc_printf("current index:%d\n", global_state.total_samples);
    write(out_fd,tmp,strlen(tmp));
    ck_free(tmp);

    if (test_one(40000) == FAULT_CRASH)
    {
        ++global_state.crash_counts;
        sprintf(buf, "cp %s/%s/www/index.html %s/%s/crashes/poc%d.html", output_dir, node_name, output_dir, node_name, global_state.crash_counts);
        system(buf);
    }
}

size_t start = 0;

void show_info()
{
    SAYF(TERM_CLEAR CURSOR_HIDE);
    SAYF(TERM_HOME);
    size_t end = time(NULL) - start;

    SAYF("###############DOM FUZZ LOOP 1.0########################\t\n");
    SAYF("# System Run Time: %ds\t\n", end);

    SAYF("# Fuzz Mode: DUMB\t\n");
    SAYF("# Total_execs: %d\tCrash_counts: %d\t\n", global_state.total_execs, global_state.crash_counts);
    SAYF("# Total_samples: %d\t", global_state.total_samples);

    SAYF("########################################################\t\n");
    lseek(state_fd, 0L, SEEK_SET);
    write(state_fd, &global_state, sizeof(GlobalState));
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

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("usage: %s output_dir node_name server_port chrome_path\n", argv[0]);
        exit(0);
    }
    output_dir = argv[1];
    node_name = argv[2];
    server_port = atoi(argv[3]);
    chrome_path = argv[4];
    start = time(NULL);

    check_core_pattern();
    //初始化输出文件夹
    init_dirs();
    //开启http服务器
    http_server();
    //注册信号处理
    setup_signal_handlers();
    //初始化状态
    init_state();
    init_generator();

    while (!stop_soon)
    {
        dumb_one();
    }
    return 0;
}
