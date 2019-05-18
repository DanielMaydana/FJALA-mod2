#include<stdio.h>
#include<iostream>
/* 
    Policies is a way to 
*/


struct Animal 
{
    virtual ~Animal()
    {}

    virtual void speak() const = 0;
};

struct Cow : Animal
{
    virtual void speak() const override
    {
        puts("Muuu"); 
    }
};

struct Dog : Animal
{
    virtual void speak() const override
    {
        puts("Woof"); 
    }
};

void f(const Animal& a)
{
    a.speak();
}

int main()
{
    Dog p;
    Cow v;
    f(p);
    f(v);
}