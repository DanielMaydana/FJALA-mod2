#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void print_if(const int* p, size_t n, int(*funct)(int))
{
    for(size_t i = 0; i < n; i++)
    {
        if(funct(p[i])) printf("%d\n", p[i]);
    }
    puts("---------------------------");
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

    int(*f_ptr)(int);

    f_ptr = verifyIfEven;
    print_if(x, x_n, verifyIfEven);

    f_ptr = greaterThan20;
    print_if(x, x_n, greaterThan20);
}