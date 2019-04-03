#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// function(n, ...) [n] number of parameters, [...] the multiple parameters
// macros are entities that are processed by the post processor

int addition(size_t n, ...)
{
    va_list args; // macro
    va_start(args, n); //[n] is the name of the last parameter before the [...] // macro
    int res = 0;

    for(size_t i = 0; i < n; i++)
    {
        res += va_arg(args, int); // macro
    }

    va_end(args); // macro

    return res;
}

int main()
{
    int r = addition(7, 1, 2, 3, 4, 5, 6, 7);
    int s = addition(3, 1, 2, 3);

    printf("%d %d\n", s, r);
}