#include <stdio.h> 
#include <cstdlib>

// ARRAYS
// Viven en el stack, son de tamaño fijo
// Se pueden transformar a punteros y viceversa
// Punteros y arrays se manejan de la misma manera

int main() 
{
    // int b[] = {7, 3, 1};
    // const int sizeC = 5;
    // int *c = (int*)malloc(sizeC * sizeof(int));

    // for(int j = 0; j < sizeC; j++)
    // {
    //     c[j] = j;
    //     printf("Dynamic Size Array: %d\n", c[j]);
    // }

    // for(int j = 0; j <sizeC; j++)
    // {
    //     c++;
    //     printf("Dynamic Size Array: %d\n", *c);
    // }

    // -------------------------

    // int d[] = {2, 8, 8, 5};
    // d[4] = 11;
    // d[5] = 22;

    // for(int ii = 0; ii < 6; ii++)
    // {
    //     printf("Wut: %d\n", d[ii]);
    // }

    // -------------------------

    int d[] = {2, 8, 8, 5};
    int *e = d; // puntero al primer elemento del array
    // se transforma automaticamente
    // se aplica aritmetica a 'e', no a 'd'
    for(int i = 0; i < 5; i++)
    {
        printf("Aritmetica de ptr: %d\n", *e);
        e++;
        // e
    }

    int whatever = 32;

    void** m = (void*)malloc(sizeof(void));

    m* = &whatever;

    int* h = (int*)m;

    printf("%p\n", e);
    printf("%p\n", &m);
    // printf("%d\n", (int)(*m));

}

// void showArray(int toShow[3])
// {
//     for(int i = 0; i < 3; ++i)
//     {
//         printf("Whatever %d\n", toShow[i]);
//     }
// }