#include <stdio.h>
#include <array>
using namespace std;

// All containers from the std lib have iterators

template <unsigned int N>   // arays can't have negative indexes
void show(array<int, N> &c) // would only receive int array with 5 spaces
// void show(const array<int, N>& c) // will show any array
{
    //The compiler doesnt know what's N, we need to put typename when we declare the iterator type
    typename array<int, N>::iterator i = c.begin();
    // auto i = c.begin();

    for (auto p = i; p != c.end(); p++)
    {
        printf("%d\n", (*p)++); // *p returns a int&!! we can change its value!!
    }
}

int main()
{
    array<int, 5> a; // int a[5]
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    a[3] = 40;
    a[4] = 50;

    show(a);

    // printf("%d\n", a[4]); // *p returns a int&!! we can change its value!!
}