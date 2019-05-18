#include<iostream>
#include <stdio.h>
using namespace std;

// not very used
// the calc is done in compile-time
template<int N>
void star()
{
    for (int i = 0; i < N; i++)
    {
        printf("*");
    }
    puts("");
}

constexpr int p = 7;

int main()
{
    // prints 6 stars
    star<p>(); // '6' needs to be known in compile time

}