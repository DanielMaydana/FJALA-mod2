#include<stdio.h>
#include<utility>
#include<string.h>
using namespace std;

// SOLUTION
/*
    ParN b{N{"buen dia"}, N{"bonjour"}}; ==>> this is 'const ref&' x2
    We have to implement move equal operator and constructor 
*/
class N;

char* clone (const char* s)
{
    auto len = strlen(s);
    char* aux = new char[len + 1];
    memcpy(aux, s, len + 1);

    return aux;
}

class N
{
    char *aux;
public:
    N(const char *s) : aux{clone(s)}
    {
      // puts("new");
    }

    N(const N& s) : aux {clone(s.aux)}
    {
      // puts("copy");
    }

    N(N&& src) : aux{src.aux} // move constructor, never const!
    {
        src.aux = nullptr; // we put the source in nullptr
      // puts("move");
    }

    N& operator=(const N& src)
    {
        this->~N();
      // puts("=");
        aux = clone(src.aux);
        return *this;
    }

    N& operator=(N&& src) // move equal operator
    {
        this->~N();
      // puts("move =");
        aux = src.aux;
        src.aux = nullptr;
        return *this;
    }

    ~N()
    {
        delete[] aux;
    }

    void print()const
    {
      puts(aux);
    }

};

N factory(const char* s)
{
    N x{s};
    return x;
}

class ParN
{
    N a, b;
public:
    ParN(const N& a, const N& b) : a{a}, b{b}
    {}

    ParN(N&& a, N&& b) : a{move(a)}, b{move(b)}
    {}
};

void interchange(N& a, N&b)
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

    // ParN b{N{"buen dia"}, N{"bonjour"}};

    // /*
    // Cases:
    //     ParN p1{a, b}
    //     ParN p2{N{"hola"}, N{"bye"}}
    //     ParN p2{a, N{"bye"}}
    //     ParN p2{N{"hola"}, b}
    // */

   // -------------------------------

    N a{"Luisito comunica cochabamba"};
    N b{"Y nada quedo despues del examen"};

    for(int i = 0; i < 100'000'001; i++)
    {
        interchange(a, b);
    }

    a.print();
    b.print();
}