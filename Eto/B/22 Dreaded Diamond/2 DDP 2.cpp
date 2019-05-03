/*
    Using virtual makes the compiler to use just the implemented child classes
*/

#include<iostream>
#include<stdio.h>
using namespace std;

class Base {
    public:
    
    virtual ~Base()
    { }

    virtual std::string to_string() const=0;

};

class A : public virtual Base
{
    public:
    std::string to_string() const override
    {
        return "A";
    }
};

class B : public virtual Base
{
    public:
    std::string to_string() const override
    {
        return "B";
    }
};

class C : public virtual A, public virtual B
{

};

int main()
{
    A *a = new C();
    B *b = new C();

    puts(a->to_string().data());
    puts(b->to_string().data());

    delete(a);
    delete(b);
}