#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

class point
{
    int x;
    int y;

public:
    point(int x = 0, int y = 0) : x{x}, y{y} // same as empty constructor with 'x = 0, y = 0'
    {
    }

    ~point()
    {
        printf("[%d, %d] pnt deleted\n", x, y);
    }

    void print_pnt() const
    {
        printf("(%d, %d)\n", x, y);
    }

    void set_values(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int main()
{
    point p{6, 8};
    p.print_pnt();

    point *q = new point(3, 9); // new creates a point*
    q->print_pnt();
    delete (q); // always when new was used

    // ---------------------------------------------

    // different 'new' operators: new and new[]
    point *pnt_array = new point[3]; // new[] needs an empty constructor
    pnt_array[0].set_values(11, 22);
    pnt_array[1].set_values(23, 12);
    pnt_array[2].set_values(37, 41);

    for (size_t i = 0; i < 2; i++)
    {
        pnt_array[i].print_pnt();
    }

    for (size_t i = 0; i < 2; i++)
    {
        pnt_array[i].print_pnt();
    }

    delete[](pnt_array); // freed with delete[] beacaus we used new[]
}