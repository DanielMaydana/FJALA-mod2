#include <iostream>
#include <stdio.h>

using namespace std;

class Base
{
public:
    virtual ~Base()
    {
    }

    virtual string to_string() const = 0;
};

class IComparable : public virtual Base
{
public:
    virtual int compare_to(const Base &b) const = 0;
};

class Integer : public virtual IComparable, public virtual Base
{
    int n;

public:
    Integer(int n) : n{n}
    {
    }

    string to_string() const override
    {
        return std::to_string(n);
    }

    int compare_to(const Base &b) const override
    {
        auto &e = dynamic_cast<const Integer &>(b);
        return n - e.n;
    }
};

int main()
{
    Base *b = new Integer{22};
    IComparable *c = new Integer{12};

    puts(b->to_string().c_str());
    printf("%d\n", c->compare_to(*b));
}