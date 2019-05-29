#include <stdio.h>
#include <string>
#include <iostream>
#include <utility>
using namespace std;

class Point3D
{
    int a, b, c;
public:

    ~Point3D()
    {
        puts("bye");
    }

    Point3D(int a, int b, int c) : a{a}, b{b}, c{c}
    { }

    void print() const
    {
        printf("%d\n", a + b + c);
    }
};

template<class T>
struct W
{
    T* pntr;

    ~W()
    {
        delete pntr;
    }

    // overloading -> operator
    T* operator->()
    {
        return pntr;
    }
};

template<typename T, typename ...ARGS>
// W<T> create(const ARGS& ...args)
W<T> create(ARGS&& ...args)
{
    // return W<T>{ new T{args...} };
    return W<T>{ new T{std::forward<ARGS>(args)...} }; // not const for move
}

int main()
{
    auto x = create<Point3D>(10, 15, 14); // SMART POINTER
    // x.pntr->print(); not needed cause we overloaded the -> operator
    x->print();
}