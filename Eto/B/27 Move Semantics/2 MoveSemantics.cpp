#include <stdio.h>
#include <utility>
#include <string.h>
#include <iostream>
using namespace std;

// SOLUTION
/*
    PairN b{N{"buen dia"}, N{"bonjour"}}; ==>> this is 'const ref&' x2
    We have to implement move equal operator and constructor 
*/
class N;

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

    N(N &&src) : aux{src.aux} // move constructor, never const!
    {
        puts("move");

        src.aux = nullptr; // we put the source in nullptr
    }

    N &operator=(const N &src)
    {
        puts("=");

        this->~N();
        aux = clone(src.aux);
        return *this;
    }

    N &operator=(N &&src) // move equal operator
    {
        if (this != &src)
        {
            puts("move =");

            this->~N();
            aux = src.aux;
            src.aux = nullptr;
        }
        return *this;
    }

    ~N()
    {
        printf("~N *|%s|*\n", aux);

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

class PairN
{
    N a, b;

public:
    PairN(const N &a, const N &b) : a{a}, b{b}
    {
    }

    PairN(N &&a, N &&b) : a{move(a)}, b{move(b)}
    {
    }
};

void interchange(N &a, N &b)
{
    // wrong way:
    // N aux = a;
    // a = b;
    // b = aux;

    N aux = move(a);
    a = move(b);
    b = move(aux);
}

int main()
{
    // N a{""};
    // a = factory("Hello World");

    // PairN b{N{"buen dia"}, N{"bonjour"}};

    // /*
    // Cases:
    //     PairN p1{a, b}
    //     PairN p2{N{"hola"}, N{"bye"}}
    //     PairN p2{a, N{"bye"}}
    //     PairN p2{N{"hola"}, b}
    // */

    // -------------------------------

    N a{"BRMC"};

    N b = std::move(a);
    b.print();

    puts("\n***END***\n");

    // N b{"Y nada quedo despues del examen"};

    // for (int i = 0; i < 100'000'001; i++)
    // {
    //     interchange(a, b);
    // }

    // b.print();
}