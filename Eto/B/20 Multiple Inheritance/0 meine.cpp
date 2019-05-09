#include <iostream>
#include <string>
using namespace std;

struct A
{
    A()
    {
        puts("A constructed");
    }

    int x;
};

struct B
{
    B()
    {
        puts("B constructed");
    }

    int y;
};

struct Point : A, B
{
    Point()
    {
        puts("Pnt constructed");
    }

    void show()
    {
        printf("(%d, %d)\n", x, y);
    }
};

int main()
{
    Point p;
    p.x = 2;
    p.y = 3;
    p.show();
}