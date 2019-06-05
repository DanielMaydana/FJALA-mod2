#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
struct deleter
{
    void release(T *x)
    {
        delete x;
    }
};

template <>
struct deleter<char>
{
    void release(char *x) // it's not necessary to have the same signature in the specialization
    {
        free(x);
        std::cout << "bye char\n";
    }
};

template <typename T, typename Deleter = deleter<T>>
struct Wrapper
{
    T *val;

    ~Wrapper()
    {
        Deleter d;
        d.release(val); // we use the same name function for the original and its specialization
        // delete val;
        // we're supposing all 'val' are created with 'new'
        // it's not true for all cases
    }
};

struct A
{
    A()
    {
        puts("HI");
    }

    ~A()
    {
        puts("BYE");
    }
};

int main()
{
    // Wrapper<A> a{new A{}};

    // --------------------------

    char *aux = (char *)malloc(5);
    strcpy(aux, "He55o");

    Wrapper<char> b{aux};
    puts(b.val);
}