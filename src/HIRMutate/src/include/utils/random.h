#ifndef HM_RANDOM_H
#define HM_RANDOM_H

#include <random>
#include <vector>
#include <set>

#define CHOICE(ARR) (ARR[Random::selector(sizeof(ARR) / sizeof(ARR[0]))])
#define CHOICE_W(ARR, WEIGHT) (ARR[Random::selector(sizeof(ARR) / sizeof(ARR[0]), WEIGHT)])
#define CHOICE_OBJ(vec) (vec[Random::selector(vec.size())])
#define CHOICE_OBJ_PTR(vec) (vec->at(Random::selector(vec->size())))

using std::set;
using std::string;
using std::vector;

namespace HIRMutate
{
    class Random
    {
    private:
        static int unrandom_fd;
    public:
        static void init();
        static void close_fd();
        static unsigned int my_rand();
        static bool gbool();
        static int selector(int num);
        static int selector(int num, vector<int> &w);
        static int range(int low, int high);
        static const string &choice_set(set<string> &s, vector<int> *w = nullptr);
        static string range_s(int low, int high);
        static string gstring();
        static string gchar();
        static string integer();
        static string signed_integer();
        static string hex_digit();
        static string hex_digits(int num);
        static string hex_byte();
        static string float01();
        static double float01_f();
        static string number();
        static string signed_number();
        static string selectors(int n);
    };
}

#endif