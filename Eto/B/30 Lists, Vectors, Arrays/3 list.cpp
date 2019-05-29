#include <iostream>
#include <string.h>
#include <stdio.h>
#include <array>
#include <list>
using namespace std;

template<typename Container> 
void show(const Container& c) 
{
    for(auto& i : c)
    {
        cout << i << "\n";
    }
}

int main()
{
    std::list<string> s;

    s.push_back("two");
    s.push_back("three");
    s.push_front("four");
    s.push_back("one");

    auto z = "five"s;

    s.emplace_back("z");

    show(s); //

    // cout << size(s) << "\n";
}