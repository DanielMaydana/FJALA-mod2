#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

constexpr size_t MAX = 16;

class ztring
{
    char *chars;
    char sso[MAX];
    size_t len;

  public:
    ztring(const char *s = "") : len{strlen(s)}
    {
        set_string(s);
    }

    ztring(const ztring &src) : len{src.len}
    {
        set_string(src.data());
    }

  private:
    void set_string(const char *s)
    {

        if (len >= MAX)
        {
            chars = (char *)malloc(len + 1);
            memcpy(chars, s, len + 1);
        }
        else
        {
            memcpy(sso, s, len + 1);
        }
    }

  public:
    const char *data() const
    {
        return len < MAX ? sso : chars;
    }

    ~ztring()
    {
        if (len >= MAX)
        {
            free(chars);
        }
    }

    ztring &operator=(const ztring &src)
    {
        if (this == &src)
            return *this;

        this->~ztring();
        len = src.len;
        set_string(src.data());
        return *this;
    }

    ztring operator+(const ztring &src) const //este const dice que el this no cambia
    {
        auto nlen = len + src.len;
        ztring ns;
        ns.len = nlen;

        if (nlen >= MAX)
        {
            ns.chars = (char *)malloc(nlen + 1);
        }

        char *str = nlen < MAX ? ns.sso : ns.chars;
        memcpy(str, data(), len);
        memcpy(str + len, src.data(), src.len + 1);

        return ns;
    }

    ztring &operator+=(const ztring &src) //este const dice que el this no cambia
    {
        auto nlen = len + src.len;

        if (len >= MAX)
        {
            chars = (char *)realloc(chars, nlen + 1);
            memcpy(chars + len, src.data(), src.len + 1);
            len = nlen;
            return *this;
        }

        if (nlen >= MAX)
        {
            chars = (char *)malloc(nlen + 1);
            memcpy(chars, data(), len);
            memcpy(chars + len, src.data(), src.len + 1);
            len = nlen;
            return *this;
        }
        memcpy(sso + len, src.data(), src.len + 1);
        len = nlen;
        return *this;
    }
};

int main()
{
    ztring s = "hola";
    puts(s.data());
    ztring r = "antonio jose de sucre";
    puts(r.data());
    auto p = r;
    puts(p.data());
    auto x = s;
    puts(x.data());
    p = "segmentation";
    puts(p.data());
    ztring q = "fault";
    auto result = p + " " + q;
    puts(result.data());
    ztring concatenar = "today";
    concatenar += " is123";
    concatenar += " tuesday";
    concatenar += " asdfg";
    puts(concatenar.data());
}