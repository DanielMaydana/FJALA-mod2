#include <iostream>
#include <string>
using namespace std;

struct A
{
    int x;
};

struct B
{
    int y;
};

struct Point : A, B
{
    void show()
    {
        printf("(%d, %d\n)", x, y);
    }
};

int main()
{
    Point p;
    p.x = 2;
    p.y = 3;
    p.show();
}