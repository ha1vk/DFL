#include "random.h"
#include "assert.h"
#include <unistd.h>
#include <fcntl.h>

int HIRMutate::Random::unrandom_fd = -1;

void HIRMutate::Random::init()
{
    if (unrandom_fd == -1)
    {
        unrandom_fd = open("/dev/urandom", O_RDONLY);
        if (unrandom_fd == -1)
        {
            puts("Random::init() Error!");
            abort();
        }
        atexit(close_fd);
    }
}

void HIRMutate::Random::close_fd() {
    close(unrandom_fd);
}

unsigned int HIRMutate::Random::my_rand()
{
    unsigned int x = 0;
    if (read(unrandom_fd, &x, sizeof(unsigned int)) != 4)
    {
        puts("Random::my_rand() Error!");
        abort();
    }
    return x;
}

bool HIRMutate::Random::gbool()
{
    return range(0, 1);
}

int HIRMutate::Random::selector(int num)
{
    assert(num != 0);
    return range(0, num - 1);
}

int HIRMutate::Random::selector(int num, vector<int> &w)
{
    vector<int> p = w;
    register int len = p.size();
    //生成前缀和数组
    for (int i = 1; i < len; ++i)
        p[i] += p[i - 1];
    //1~p.back()的随机数
    int i = my_rand() % p.back() + 1;
    return lower_bound(p.begin(), p.end(), i) - p.begin();
}

int HIRMutate::Random::range(int low, int high)
{
    return (my_rand() % (high - low + 1)) + low;
}

const string &HIRMutate::Random::choice_set(set<string> &s, vector<int> *w)
{
    int sel;
    int len = s.size();
    set<string>::iterator it = s.begin();
    if (w != nullptr)
    {
        sel = selector(len, *w);
    }
    else
    {
        sel = selector(len);
    }
    for (int i = 0; i < sel; i++)
    {
        it++;
    }
    return *it;
}

string HIRMutate::Random::range_s(int low, int high)
{
    int ans = range(low, high);
    char buf[20];
    sprintf(buf, "%d", ans);
    return buf;
}
string HIRMutate::Random::gstring()
{
    static const int arr[] = {0, 1, 2, 4, 8, 10, 15, 16, 20, 31, 32, 40, 63, 64, 100, 200, 400, 800, 1600, 3200};
    int size = CHOICE(arr);
    string ans = "";
    for (int i = 0; i < size; i++)
    {
        ans.insert(ans.end(), 'A');
    }
    return ans;
}

string HIRMutate::Random::gchar()
{
    static const char *arr[] = {"0", "1", "A", " ", ""};
    return CHOICE(arr);
}

string HIRMutate::Random::integer()
{
    int c = selector(7);
    int64_t v = 0;
    char ans[0x30];
    switch (c)
    {
    case 0:
    case 1:
        v = 0;
        break;
    case 2:
        v = 1;
        break;
    case 3:
        v = range(0, 16);
        break;
    case 4:
        v = range(0, 100);
        break;
    case 5:
        v = range(0, 1000);
        break;
    default: //一些临界值
        int c2 = selector(8);
        switch (c2)
        {
        case 0:
            v = 0x10000;
            break;
        case 1:
            v = 0x10001;
            break;
        case 2:
            v = 0xffff;
            break;
        case 3:
            v = 0x8000;
            break;
        case 4:
            v = 0x100000000;
            break;
        case 5:
            v = 0xffffffff;
            break;
        case 6:
            v = 0x80000000;
            break;
        default:
            v = range(0, 50000);
            break;
        }
    }
    sprintf(ans, "%ld", v);
    return ans;
}
string HIRMutate::Random::signed_integer()
{
    if (gbool())
    {
        return integer();
    }
    else
    {
        return "-" + integer();
    }
}
string HIRMutate::Random::hex_digit()
{
    static const char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char c = CHOICE(arr);
    char ans[2] = {0};
    sprintf(ans, "%c", c);
    return ans;
}
string HIRMutate::Random::hex_digits(int num)
{
    string ans = "";
    for (int i = 0; i < num; i++)
    {
        ans += hex_digit();
    }
    return ans;
}
string HIRMutate::Random::hex_byte()
{
    string ans = "";
    ans.insert(ans.end(), range(0, 255));
    return ans;
}

string HIRMutate::Random::float01()
{
    char ans[0x10];
    if (gbool())
    {
        sprintf(ans, "%d", gbool());
    }
    else
    {
        sprintf(ans, "%.2f", (double)(my_rand() % 666) / 666);
    }
    return ans;
}

double HIRMutate::Random::float01_f()
{
    double ans;
    if (gbool())
    {
        ans = gbool();
    }
    else
    {
        ans = (double)(my_rand() % 666) / 666;
    }
    return ans;
}

string HIRMutate::Random::number()
{
    if (gbool())
    {
        return float01();
    }
    else
    {
        return integer();
    }
}

string HIRMutate::Random::signed_number()
{
    if (gbool())
    {
        return number();
    }
    else
    {
        return "-" + number();
    }
}
string HIRMutate::Random::selectors(int n)
{
    string bits = "";
    for (int i = 0; i < n; i++)
    {
        bits.insert(bits.end(), gbool());
    }
    return bits;
}
