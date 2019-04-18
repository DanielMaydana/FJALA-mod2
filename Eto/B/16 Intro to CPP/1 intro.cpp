/*
    Differences between C and C++
    - function and operator overloading
    - Namespaces (identity container)
    - References (static pointers)
*/
#include <iostream>
using namespace std;

int main()
{
    int a = 4;
    int &b = a;

    b++;

    printf("%d\n", ++a);
    printf("%d\n", b);

    return 0;
}