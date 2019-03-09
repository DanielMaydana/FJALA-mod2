// dynamic cast
#include <iostream>
#include <exception>
using namespace std;


class Base
{
private:
    
public:
    Base() { }
    ~Base() { }

    virtual void dummy()
    {}

};

class Derived : public Base
{
private:
    int a;
public:
    Derived() { }
    ~Derived() { }
};

int main()
{
    try
    {
        Base* pba = new Derived;
        Base* pbb = new Base;
        Derived* pb;

        pb = dynamic_cast<Derived*> (pba);
            cout << pb << "\n";
        if (pb == 0)
        {
            cout << "Null pointer on first type cast\n";
        }

        pb = dynamic_cast<Derived*> (pbb);
        if (pb == 0)
        {
            cout << pb << "\n";
            cout << "Null pointer on second type cast\n";
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what();
    }
    return 0;
}