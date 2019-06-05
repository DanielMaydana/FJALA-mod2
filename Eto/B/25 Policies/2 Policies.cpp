#include <stdio.h>
#include <iostream>

// this way we don't have any virtual, inheritance or polymorphism
template <class SpeakPolicy> // the typename is a beheavior instead of a typical class
struct Animal
{
    SpeakPolicy sp;

    void AnimalSays() const
    {
        sp.speak();
    }
};

struct SpeakDog // doesn't have override! yay!
{
    void speak() const
    {
        puts("Woof!!");
    }
};

struct SpeakCow // doesn't have override! yay!
{
    void speak() const
    {
        puts("Mooo!!");
    }
};

// template<class A>
// void f(const A& a)
template <class SeakPolicy>
void myFunction(const Animal<SeakPolicy> &beast)
{
    beast.AnimalSays();
}

using Dog = Animal<SpeakDog>;
using Cow = Animal<SpeakCow>;

int main()
{
    Dog p;
    Cow v;
    myFunction(p);
    myFunction(v);
}

// To see which functions were created by the compiler:
// nm -C .\main.exe | grep Speak