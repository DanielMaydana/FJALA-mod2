#include <stdio.h>
#include <string.h>
#include <iostream>
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
    }
};

template <>
struct deleter<FILE>
{
    void release(FILE *f) // it's not necessary to have the same signature in the specialization
    {
        fclose(f);
        puts("closing FILE");
    }
};

// struct file_deleter
// {
//     void release(FILE *f)
//     {
//         fclose(f);
//         puts("THAT'S ALL FOLKS");
//     }
// };

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

int main()
{

    // char *aux = (char *)malloc(5);
    // strcpy(aux, "He55o");

    // Wrapper<char> b{aux};
    // puts(b.val);

    FILE *f = fopen("h.txt", "w");
    fprintf(f, "Hola");

    Wrapper<FILE> wf{f};
}