#ifndef HM_UNSERIALIZE_STREAM_H
#define HM_UNSERIALIZE_STREAM_H

#include <string>
using std::string;
#include "uncopyable.h"

namespace HIRMutate
{
    class Document;
    class Function;
    class UnSerializeStream : public uncopyable
    {
    private:
        //当前位置

        //大小
        int size;
        //数据区
        unsigned char *buf;

    public:
        int pos;
        UnSerializeStream(const char *path);
        ~UnSerializeStream();
        unsigned char read_byte();
        char read_char();
        int read_int();
        long read_long();
        string read_string();
        string peek();
        void skip_string();
        void read_obj_ref(size_t ptr_addr, Document *global_document);
        void read_obj_ref_in_js_context(size_t ptr_addr, Function *function);
    };
}
#endif