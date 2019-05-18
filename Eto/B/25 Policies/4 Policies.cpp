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

struct file_deleter
{
    void release(FILE* f)
    {
        fclose(f);
        puts("THAT'S ALL FOLKS");
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
    FILE *f = fopen("h.txt", "w");
    fprintf(f, "Hola");
    W<FILE, file_deleter> wf{f}; 
}