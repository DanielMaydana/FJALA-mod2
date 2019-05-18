#include <iostream>
#include <stdio.h>
/* 
    FUNCTION OBJECTS (FUNCTORS)
*/

struct P
{
    // to use an object as a function we just have to overload the operator() 
    void operator()(int a, int b) const
    {
        printf("%d\n", a + b);
    }
};

class accumulator
{
    int &n;

    public: 

    accumulator(int&n) : n{n}
    {
    }

    int operator()  (int a, int b)
    {
        int r = a + b;
        n += r;
        return r;
    }

};

int sum(int a, int b)
{
    return a + b;
}

template<typename PROC> // will USE PROC as a function and as an object 
void f(PROC proc, int a, int b)
{
    auto r = proc(a, b);
    printf("%d\n", r);
}

int main()
{
    // P p;
    // p(10, 15);

    // ------------------

    f(sum, 10, 11);

    int n = 0;
    accumulator acc{n};

    f(acc, 10, 11);
    f(acc, 10, 12);
    // f([](){}, 10, 13);

    printf("%d\n", n);




}