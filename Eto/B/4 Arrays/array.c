#include <stdio.h> 
#include <cstdlib>

int main() 
{
    // Viven en el stack, son de tamaño fijo
    // Se pueden transformar a punteros y viceversa
    // Punteros y arrays se manejan de la misma manera

    int b[] = {7, 3, 1};


    const int sizeC = 5;

    int *c = (int*)malloc(sizeC * sizeof(int));

    for(int j = 0; j < sizeC; j++)
    {
        c[j] = j;
        printf("Dynamic Size Array: %d\n", c[j]);
    }

    for(int j = 0; j <sizeC; j++)
    {
        c++;
        printf("Dynamic Size Array: %d\n", *c);
    }

    // -------------------------

    int d[] = {2, 8, 8, 5};
    d[4] = 11;
    d[5] = 22;

    for(int ii = 0; ii < 6; ii++)
    {
        printf("Wut: %d\n", d[ii]);
    }

    // -------------------------

    int *e = d; // puntero al primer elemento del array
    // se transforma automaticamente
    // se aplica aritmetica a 'e', no a 'd'
    for(int i = 0; i < 5; i++)
    {
        printf("Aritmetica de ptr: %d\n", *e);
        e++;
        // e
    }

}

// void showArray(int toShow[3])
// {
//     for(int i = 0; i < 3; ++i)
//     {
//         printf("Whatever %d\n", toShow[i]);
//     }
// }