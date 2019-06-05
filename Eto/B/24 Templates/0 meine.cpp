#include <stdio.h>
#include <iostream>
#include <string>

template <typename T>
class Wrapper
{
    T val;

public:
    Wrapper(const T &val) : val{val}
    {
    }

    const T &get() const
    {
        return *val;
    }
};

template <typename T, typename U>
class Adder
{
    T a;
    U b;

public:
    Adder(const T &a, const U &b) : a{a}, b{b}
    {
    }

    const U &operator()() const
    {
        return Wrapper<U>{a + b};
    }
};

int main()
{
    Adder<int, double> s{2, 3.2};
    std::cout << s() << "\n";
}