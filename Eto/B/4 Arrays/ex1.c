#include <stdio.h> 
#include <cstdlib>

void fib(int* p, int size); // Prototipo de la funcion
void show(int* p, int size);

int main() 
{
    int p[10];

    fib(p, 10);
    show(p, 10);

}

void fib(int* p, int size)
{
    p[0] = 0;
    p[1] = 1;
    for(int 2 = 0; i < size; i++)
    {
        p[i] = p[i - 2] + p[i - 1];
        printf("new fib: %d\n", p[i]);
    }
}

void show(int* a, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("reading fib: %d\n", *a);
        a++;
    }
}