#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

constexpr size_t MAX = 16;

class Ztring
{
    char *chars;
    char sso[MAX];
    size_t len;

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
    Ztring(const char *s = "") : len{strlen(s)}
    {
        set_string(s);
    }

    Ztring(const Ztring &src) : len{src.len}
    {
        set_string(src.data());
    }

    const char *data() const
    {
        return len < MAX ? sso : chars;
    }

    ~Ztring()
    {
        if (len >= MAX)
        {
            free(chars);
        }
    }

    Ztring &operator=(const Ztring &src)
    {
        if (this == &src)
            return *this;

        this->~Ztring();
        len = src.len;
        set_string(src.data());
        return *this;
    }

    Ztring operator+(const Ztring &src) const //este const dice que el this no cambia
    {
        auto nlen = len + src.len;
        Ztring ns;
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

    Ztring &operator+=(const Ztring &src) //este const dice que el this no cambia
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
    Ztring s = "hola";
    puts(s.data());

    Ztring r = "antonio jose de sucre";
    puts(r.data());

    auto p = r;
    puts(p.data());

    auto x = s;
    puts(x.data());

    p = "segmentation";
    puts(p.data());
    Ztring q = "fault";

    auto result = p + " " + q;
    puts(result.data());

    Ztring concatenar = "today";
    concatenar += " is123";
    concatenar += " tuesday";
    concatenar += " asdfg";
    puts(concatenar.data());
}