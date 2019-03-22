#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// changes the size of memory reserved with malloc

void par_impar(int n, const char** s)
{
    *s = n%2 ? "odd" : "even";
}

int main()
{
    // int* reserved = (int*)malloc(5*sizeof(int));

    // reserved[0] = 9;
    // reserved[1] = 333;
    // reserved[2] = 81;
    // reserved[3] = 888;
    // reserved[4] = 343;

    // reserved = (int*)realloc(reserved, 6 * sizeof(int)); // Always cast

    // ---------------------

    // const char* x;
    // par_impar(12, &x);
    // puts(x);

    // ---------------------

    int** list = (int**)malloc(2 * sizeof(int*));

    list[0] = (int*)malloc(2*sizeof(int));
    list[1] = (int*)malloc(2*sizeof(int));

    list[0][0] = 1;
    list[0][1] = 8;
    list[1][0] = 3;
    list[1][1] = 9;

    free(list[0]);
    free(list[1]);

    puts("All OK");
}