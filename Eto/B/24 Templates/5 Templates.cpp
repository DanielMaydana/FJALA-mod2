#include <iostream>
#include <stdio.h>
using namespace std;

// TEMPLATE SPECIALIZATION
// WITH CLASSES!

template <class T>
class Wrapper
{
    T val;

public:
    Wrapper(const T &x) : val{x}
    {
        std::cout << "wrp cnstr\n";
    }

    const T &get() const
    {
        return val;
    }
};

struct Point
{
    int x, y;

    Point(const int &x, const int &y) : x{x}, y{y}
    {
        std::cout << "pnt cnstr\n";
    }

    ~Point()
    {
        std::cout << "pnt del\n";
    }
};

/* struct A
{
    ~A()
    {
        puts("bye A");
    }

    void say_hi() const // const why??
    {
        puts("Hi from A");
    }
};

struct B : A
{
};
*/
template <>
class Wrapper<Point>
{
    Point p;

public:
    Wrapper(const Point &p) : p{p}
    {
        std::cout << "wrp pnt cnstr\n";
    }

    void print() const
    {
        printf("(%d, %d)\n", p.x, p.y);
    }
};

template <typename T>
class Wrapper<T *> // pointer specialization
{
    T *val;

public:
    Wrapper(T *val) : val{val}
    {
    }

    const T &get() const
    {
        return *val;
    }

    ~Wrapper()
    {
        delete val;
        std::cout << "wrp deleted\n";
    }
};

int main()
{
    Wrapper<int> p{10};
    printf("%d\n", p.get());

    // Wrapper<string> q{"Queens"};
    // printf("%s\n", q.get().data());

    // Wrapper<Point> pnt{Point{5, 25}};
    // pnt.print();

    // Wrapper<Point *> pnt_star{new Point{11, 2}};
    // printf("(%d, %d)\n", pnt_star.get().x, pnt_star.get().y);
    // delete pnt_star;

    /*
    Wrapper<A*> w{new A{}};
    w.get().say_hi();

    Wrapper<B*> w2{new B{}};
    w2.get().say_hi(); */
}