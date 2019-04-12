#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef int(*PTR_FUNC)(int);

void print_if(const int* p, size_t n, PTR_FUNC funct)
{
    for(size_t i = 0; i < n; i++)
    {
        if(funct(p[i])) printf("%d\n", p[i]);
    }
    puts("------");
}

int verifyIfEven(int n)
{
    return n%2 == 0;
}

int greaterThan20(int n)
{
    return n > 20;
}

int main()
{
    int x[] = {6, 45, 22, 11, 2};
    size_t x_n = 5;

    // int(*f_ptr)(int);
    PTR_FUNC f_ptr;

    f_ptr = verifyIfEven;
    print_if(x, x_n, f_ptr);

    f_ptr = greaterThan20;
    print_if(x, x_n, f_ptr);
}