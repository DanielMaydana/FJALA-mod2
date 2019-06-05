#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

// consecutive printing

void print(int x)
{
    printf("%d", x);
}

void print(const char *x)
{
    printf("%s", x);
}

void print(bool x)
{
    printf("%s", (x ? "true" : "false"));
}

template <class T>
void join(const char *c, const T &t)
{
    print(t);
    printf("\n");
}

template <class T, class... ARGS>
auto join(const char *sep, const T &a, const ARGS &... args) // last step in the recursive execution // LAST DECLARATION
{
    print(a);
    print(sep);
    join(sep, args...);
}

int main()
{
    join(", ", "juan ", "maria ", 24, true, "hola ");
}