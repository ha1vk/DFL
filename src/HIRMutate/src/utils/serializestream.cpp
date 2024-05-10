#include "serializestream.h"
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

HIRMutate::SerializeStream::SerializeStream(int capacity)
{
    this->capacity = capacity;
    this->pos = 0;
    this->buf = (unsigned char *)malloc(capacity);
    this->delta = 0x200000;
    assert(buf != nullptr);
}

HIRMutate::SerializeStream::~SerializeStream()
{
    free(buf);
    buf = nullptr;
}

void HIRMutate::SerializeStream::check_capacity(int len)
{
    if (pos + len >= capacity)
    {
        unsigned char *new_buf = (unsigned char *)malloc(capacity + delta);
        memcpy(new_buf, buf, capacity);
        this->capacity += delta;
        free(buf);
        buf = new_buf;
    }
}

void HIRMutate::SerializeStream::write_byte(unsigned char byte)
{
    check_capacity(1);
    buf[pos++] = byte;
}

void HIRMutate::SerializeStream::write_int(int x)
{
    check_capacity(sizeof(int));
    int *p = (int *)(buf + pos);
    *p = x;
    pos += sizeof(int);
}

void HIRMutate::SerializeStream::write_long(long x)
{
    check_capacity(sizeof(long));
    long *p = (long *)(buf + pos);
    *p = x;
    pos += sizeof(long);
}

void HIRMutate::SerializeStream::write_string(const string &s)
{
    int len = s.length();
    write_int(len);
    check_capacity(len);
    for (int i = 0; i < len; i++)
    {
        write_byte(s[i]);
    }
}

void HIRMutate::SerializeStream::write_to_file(const string &path)
{
    int fd = open(path.c_str(), O_RDWR | O_CREAT, 0777);
    if (fd < 0)
    {
        printf("[SerializeStream] open file path error!\n");
        abort();
    }
    write(fd, buf, pos);
    close(fd);
}