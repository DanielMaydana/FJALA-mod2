#include <iostream> //Library
using namespace std;

struct A
{
    int a;
};

struct B : A
{
};

struct C : A
{
};

struct D : B, C
{
};

int main()
{
    D d;
    d.B::a = 5;
    d.C::a = 4;
    printf("%d", d.B::a);
    printf("%d", d.C::a);
    return 0;
}