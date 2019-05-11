#include <iostream>

using namespace std;

struct Base
{
    int n;
};

struct DerA : virtual Base
{
};

struct DerB : virtual Base
{
};

struct DerC : DerA, DerB
{
};

int main()
{
    DerC grand_children;
    grand_children.n = 3;

    printf("%d\n", grand_children.n);
}