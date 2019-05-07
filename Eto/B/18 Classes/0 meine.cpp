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
        if (MAX <= len)
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
        return MAX < len ? chars : sso;
    }

    Ztring(const char *s = "") : len{strlen(s)}
    {
        set_string(s);
    }

    Ztring(const Ztring &src) : len{src.len}
    {
        set_string(src.data);
    }
};

int main()
{
    Ztring s = "hola";
    puts(s.data());

    Ztring r = "antonio jose de sucre";
    puts(r.data());
}