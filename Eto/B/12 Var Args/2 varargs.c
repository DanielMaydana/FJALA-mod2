#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void my_print(const char* s, ...)
{
    va_list args;
    va_start(args, s);

    while(*s) // each character of the const char*
    {
        switch(*s)
        {
            case 'I': 
                printf("%d", va_arg(args, int));
                break;
            case 'S':
                printf("%s", va_arg(args, char*));
                break;
        }
        s++;
    }
}

int main()
{
    int p = 4; int q = 6;
    const char* n = "num";

    my_print("ISIS", p, n, q, "hola");
}