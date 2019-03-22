#include <stdio.h> 
#include <cstdlib>

int comparar(const char* a, const char* b)
{
    for(;;a++, b++)
    {
        if(*a != *b) return (*a - *b);
        if(*a == 0)  return 0;
    }
}

int main()
{
    const char* j = "abb";
    const char* jj = "abd";

    int wut = comparar(j, jj);

    printf("Res: %d\n", wut);
}
