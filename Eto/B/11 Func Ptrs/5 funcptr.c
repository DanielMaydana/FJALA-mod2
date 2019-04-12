#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int c_func(const void* a, const void* b)
{
    const int* aa = (const int*) a;
    const int* bb = (const int*) b;
    
    return *aa - *bb;
}

int main()
{
    // qsort
    int p[] = {3, 1, 2, 9, 12};
    size_t p_size = 5;

    qsort(p, p_size, sizeof(int), c_func); // injecting behavior to qsort with c_func

    for(size_t i = 0; i < p_size; i++ )
    {
        printf("%d\t", p[i]);
    }

}