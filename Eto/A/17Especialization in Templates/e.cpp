// especializacion parcial

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

template<class A, class B, class C>
struct X
{
    A a;
    B b;
    C c;

    void print()const
    {
        cout << a << "\n";
        cout << b << "\n";
        cout << c << "\n";
    }
};

template <class P> // es parcial porque todavia tiene un class P
struct X <int, int, P>
{
    int a;
    int b;
    P c;

    void print()const
    {
        cout << a + b << "\n";
        cout << c << "\n";
    }
};

template <>
struct X <string, string, string>
{
    string a,b,c;

    void show() const
    {
        cout << a << " " << b << " " << c << " \n";
    }
};


int main()
{
    X<int, string, double> x{10, "hola", 3.15};
    x.print();

    X<int, int, int> z{15, 20, 25};
    z.print();

    X<string, string, string> y{"hola", "mundo", "loco"};
    y.show();
}