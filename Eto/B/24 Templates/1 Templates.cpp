#include<iostream>
#include <stdio.h>
using namespace std;
/*
    TEMPLATES

    All implementation has to be in the h file
*/

// int sum(int a, int b)
// {
//     return (a + b);
// }

// int sum(double a, double b) 
// {
//     return a + b;
// }

struct U
{
    int n;
};

U operator+(const U& a, const U& b) // overload not override
{
    return U{a.n + b.n};
}

// Instead of overloading the same function we parameterize the type of data
// The code is generated not when the templated is defined, but when the function is called (*here) 
// template<typename T> // 'typename' can also be 'class' 
template<class T>
T sum(T a, T b)
{
    return a + b; // works as long as the logic works for all the T types 
}

int main()
{
    auto p = sum(6,8); // (*here)
    printf("%d\n", p);

    auto q = sum(1.22, 3.14); // (*here)
    printf("%f\n", q);
 
    // when using <string> we state the type and the template does not infere
    auto x = sum<string>("hello ", "world"); 
    puts(x.data());

    auto u = sum(U{6}, U{5});
    printf("%d\n", u.n);
}