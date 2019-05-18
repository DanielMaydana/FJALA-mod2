#include <iostream>
#include <stdio.h>
using namespace std;

// TEMPLATE SPECIALIZATION
// WITH CLASSES!

template<class T, class U> // multiple typenames (or classes)
struct Q
{
    T a;
    U b;

    // auto sum() const -> decltype(a + b) // decltype calcs the type of return!
    auto sum() const // auto is needed to choose between T or U
    {
        return a + b;
    }
};

template<class T> // partial specialization
struct Q<T, string>
{
    T a;
    string b;

    void print() const
    {
        puts((b + to_string(a)).data());
    }
};

int main()
{
    Q<int, double> q{10, 3.14};
    printf("%f\n", q.sum());

    Q<int, string> q2{5, "Fertita "};
    q2.print();
}