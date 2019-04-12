#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef void(*PTR_FUNC)(int, int, void*);

void do_something(PTR_FUNC funct, int a, int b, void* c)
{
    puts("hi");
    funct(a, b, c);
    puts("bye\n");
}

// -------------------------------

void addit(int a, int b, void* c)
{
    printf("%d\n", a + b);
    puts((const char*)c);
}

void subst(int a, int b, void* c)
{
    printf("%d\n", a - b);
    // void(*proc)() = c; // C way
    // void(*proc)() = (void(*)())c; // C++ way
    // proc();

    ((void(*)())c)(); // my way
}

// -------------------------------

void sayEnd()
{
    puts("END");
}

int main()
{
    do_something(addit, 4, 5, (char*)"***");
    do_something(subst, 14, 6, (void*)sayEnd);
}