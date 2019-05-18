#include <stdio.h>
#include <iostream>
using namespace std;

template<typename T>
struct deleter
{
    void release(T* x)
    {
        delete x;
    }
};

template<>
struct deleter<char>
{
    void release(char* x) // it's not necessary to have the same signature in the specialization
    {
        free(x);
    }
};

template<typename T, typename Deleter = deleter<T>>
struct W
{
    T* val;
    ~W()
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
    W<A> a{new A{}};

    // --------------------------

    char *aux = (char*) malloc(5);
    strcpy(aux, "Hello");

    W<char> b {aux};
    puts(b.val);
}