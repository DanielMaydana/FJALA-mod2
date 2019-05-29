#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <array>
#include <list>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int x, int y) : x{x}, y{y}
    { }

    void show() const
    {
        cout << x << ", " << y << "\n";
    }
};

int main()
{
    vector<Point>ps;
    ps.emplace_back(5, 4);
    ps.emplace_back(9, 3);
    ps.emplace_back(2, 3);
    ps.emplace_back(1, 9);

    ps.emplace_back(Point(33, 333)); // would use copy

    for(auto i = ps.begin(); i != ps.end(); ++i)
    {
        i->show();
    }
}