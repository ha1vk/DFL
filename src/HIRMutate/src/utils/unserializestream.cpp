#include "unserializestream.h"
#include <fcntl.h>
#include <unistd.h>
#include "document_html.h"
#include "function.h"

HIRMutate::UnSerializeStream::UnSerializeStream(const char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        printf("[UnSerializeStream] open file path error!\n");
        abort();
    }
    size = lseek(fd, 0L, SEEK_END);
    lseek(fd, 0L, SEEK_SET);
    buf = (unsigned char *)malloc(size);
    if (!buf)
    {
        printf("[UnSerializeStream] malloc memory error!\n");
        abort();
    }
    pos = 0;
    read(fd, buf, size);
    close(fd);
}
HIRMutate::UnSerializeStream::~UnSerializeStream()
{
    if (buf)
    {
        free(buf);
        buf = nullptr;
    }
}

unsigned char HIRMutate::UnSerializeStream::read_byte()
{
    return buf[pos++];
}

char HIRMutate::UnSerializeStream::read_char()
{
    return (char)buf[pos++];
}

int HIRMutate::UnSerializeStream::read_int()
{
    int *p = (int *)(buf + pos);
    pos += sizeof(int);
    return *p;
}

long HIRMutate::UnSerializeStream::read_long()
{
    long *p = (long *)(buf + pos);
    pos += sizeof(long);
    return *p;
}
string HIRMutate::UnSerializeStream::read_string()
{
    int len = read_int();
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans.insert(ans.end(), read_char());
    }
    return ans;
}
string HIRMutate::UnSerializeStream::peek()
{
    int len = read_int();
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans.insert(ans.end(), read_char());
    }
    pos -= len;
    pos -= sizeof(int);
    return ans;
}

void HIRMutate::UnSerializeStream::skip_string()
{
    int len = read_int();
    pos += len;
}

void HIRMutate::UnSerializeStream::read_obj_ref(size_t ptr_addr, Document *global_document)
{
    std::pair<string, int> &p = global_document->weak_reference_objs[ptr_addr];
    p.first = read_string();
    /*if (p.first == "SVGMaskElement") {
        int a = 1/0;
    }*/
    p.second = read_int();
}

void HIRMutate::UnSerializeStream::read_obj_ref_in_js_context(size_t ptr_addr, Function *function)
{
    std::pair<string, int> &p = function->weak_reference_objs[ptr_addr];
    p.first = read_string();
    p.second = read_int();
}