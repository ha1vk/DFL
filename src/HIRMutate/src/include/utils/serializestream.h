#ifndef HM_SERIALIZE_STREAM_H
#define HM_SERIALIZE_STREAM_H

#include <string>
using std::string;
#include "uncopyable.h"

namespace HIRMutate
{
    class SerializeStream : public uncopyable
    {
    private:
        //容量
        int capacity;
        //当前位置
        int pos;
        //数据区
        unsigned char *buf;
        int delta;

    public:
        SerializeStream(int capacity = 0x200000);
        ~SerializeStream();
        void check_capacity(int len);
        void write_byte(unsigned char byte);
        void write_int(int x);
        void write_long(long x);
        void write_string(const string &s);
        void write_to_file(const string &path);
    };
}
#endif