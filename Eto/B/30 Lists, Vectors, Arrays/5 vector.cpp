#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <memory>
#include <array>
#include <list>
using namespace std;

class Shape
{
public:
    virtual ~Shape()
    {
        puts("bye shape");
    }

    virtual double get_area() const = 0; // abstract always for using polymorphism inside a vector or container
};

struct Circle : public Shape
{
    double r;

public:
    Circle(double r) : r{r}
    {
    }

    virtual double get_area() const override
    {
        return 3.141592 * r * r;
    }
};

struct Square : public Shape
{
    double side;

public:
    Square(double side) : side{side}
    {
    }

    double get_area() const override
    {
        return side * side;
    }
};

int main()
{
    // vector<Shape*> fs; // always use * or & for polymorphism using vectors
    vector<unique_ptr<Shape>> fs; // better to use a smart ptr
    fs.emplace_back(new Circle{4});
    fs.push_back(unique_ptr<Shape>(new Circle{2}));
    fs.push_back(unique_ptr<Shape>(new Square{5}));
    fs.push_back(make_unique<Square>(3.14));

    for (auto &f : fs)
    {
        cout << f->get_area() << "\n";
    }

    // auto p = fs.at(0); // unique ptr dont have copy constructor
    // auto &p = fs.at(0); // ref is an alternative
    auto p = move(fs.at(0)); // or we move it

    puts("\n*****\n");

    for (auto &i : fs) // printing the remaining objects
    {
        if (i)
        {
            cout << i->get_area() << "\n";
        }
    }
}