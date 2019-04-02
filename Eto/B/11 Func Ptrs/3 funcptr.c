#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void flash(void(*func)(int))
{
    for(size_t i = 0; i < 100; i++) // % progress
    {
        for(size_t j = 0; j < 10000000; j++ )
        {
            void* p = malloc(10000000); // just because
            free(p);
        }
        func(i);
    }
}

void show_progress(int n)
{
    printf("%d\n", n);
}

int main()
{
    flash(show_progress);
}