#include <stdio.h>
#define XMIN(a, b) (a < b ? a : b)

// int xmin(int a, int b)
// {
//     return a < b ? a: b;
// }

int main()
{
    int p = 16;
    int q = 25;
    int r = XMIN(p, q);
    printf("%d\n", r);
}