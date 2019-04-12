#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// FUNCTION POINTERS
// Uses: Events, Behaviour Injection, Callbacks

typedef int (*PTR_FUNC)(int, int);

int sum(int a, int b)
{
    return a + b;
}

int max(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    // int(*ptrf)(int, int); // int[return type] (*ptr)[variable name] (int, int)[types of parameters]
    PTR_FUNC ptrf;
    ptrf = sum; // this ptr can store the address to any dunction with the same signature
    printf("%d\n", ptrf(18, 45));

    ptrf = max;
    printf("%d\n", ptrf(1, 200));
}