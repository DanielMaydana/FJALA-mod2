#include <stdio.h>
#include <string.h>
using namespace std;
// PROBLEM
char *clone(const char *s)
{
    auto len = strlen(s);
    char *aux = new char[len + 1];
    memcpy(aux, s, len + 1);

    return aux;
}

class N
{
    char *aux;

public:
    N(const char *s) : aux{clone(s)}
    {
        puts("new");
    }

    N(const N &s) : aux{clone(s.aux)}
    {
        puts("copy");
    }

    N &operator=(const N &src)
    {
        puts("=");

        this->~N();
        aux = clone(src.aux);
        return *this;
    }

    ~N()
    {
        delete[] aux;
    }

    void print() const
    {
        puts(aux);
    }
};

N factory(const char *s)
{
    N x{s};
    return x;
}

class ParN
{
    N a, b;

public:
    ParN(const N &a, const N &b) : a{a}, b{b}
    {
    }
};

int main()
{
    N a{""};
    a = factory("Hello World");

    ParN b{N{"buen dia"}, N{"bonjour"}};
}