#include <iostream>
#include <stdio.h>
using namespace std;

// TEMPLATE SPECIALIZATION
template<class T>
void f(T n)
{
    // implementation of the template isn't appropiate for 
    // doubles so it needs an specialization
    printf("%d\n", n); 
}

template<> // total specialization, there's no typename left
void f<double>(double p) // specialiation for doubles
{
    printf("%f\n", p);
}

void f(double p)
{
    puts("here");
}

int main()
{
    f(2);
    f(5.2);
}