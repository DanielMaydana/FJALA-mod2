#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <array>
#include <iterator>
#include <list>

#include <algorithm>

class Point
{
    int x, y;

public:
    Point(int x, int y) : x{x}, y{y}
    {
    }

    void show() const
    {
        std::cout << x << ", " << y << "\n";
    }

    friend bool operator==(const Point &a, const Point &b);
};

bool operator==(const Point &a, const Point &b)
{
    return ((a.x == b.x) && (a.y == b.y));
}

int main()
{
    std::vector<Point> ps;
    ps.emplace_back(5, 4);
    ps.emplace_back(9, 3);
    ps.emplace_back(2, 3);
    ps.emplace_back(1, 9);

    ps.emplace_back(Point{3, 333}); // would use copy

    // for(auto i = ps.begin(); i != ps.end(); ++i)
    // {
    //     i->show();
    // }

    Point x1 = Point{5, 4};

    auto index = std::find(std::begin(ps), std::end(ps), x1);

    printf("index: %d\n", *index);
}