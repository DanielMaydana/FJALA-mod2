#include <stdio.h> 
#include <cstdlib>

int maxx(int p, int q)
{
    if( p > q) return p;
    return q;
}

int divide(int a, int b, int* res2) // no se llama paso por 'referencia', si no copia de 'direccion de mem'
{
    if(b == 0) return 0;
    *res2 = a / b;
    return 1;
}

int calcSize(const char* inChar)
{
    const char* orig = inChar;

    while(*inChar) inChar++;

    return inChar - orig - 1;
}

int main() 
{
    // int a = 7;
    // int b = 20;
    // int res = maxx(a, b);
    // printf("Res: %d\n", res);

    // --------------

    // int c = 96;
    // // int d = 0;
    // int d = 4;
    // int res2;

    // if(!dividir(c, d, &res2)) puts("Divide by zero");
    // else printf("Res: %d\n", res2);

    // --------------

    // char h[] = {'h', 'o', 'l', 'a', '\0'};
    // puts(h); // '\0' is the char terminator

    // char j[] = "whatever"; // lives in the stack
    // puts(j);

    // const char* jj = "whatevers" ; // the pointer lives in the stack and the pointed char in the heap
    // puts(jj);

    // // jj[2] = 'e'; // can't modify information in the heap (without mem functions)
    // // puts(jj);

    // --------------

    const char* p = "september";
    char* q = "november";
    
    int res = calcSize(q);

    printf("Res: %d\n", res);

    puts("Alles gut");

}
