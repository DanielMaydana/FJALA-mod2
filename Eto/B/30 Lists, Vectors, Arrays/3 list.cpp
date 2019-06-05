#include <iostream>
#include <string.h>
#include <stdio.h>
#include <array>
#include <list>
using namespace std;

template <typename Container>
void show(const Container &c)
{
    for (auto &i : c)
    {
        cout << i << "\n";
    }
}

int main()
{
    std::list<string> s;

    s.push_back("three");
    s.push_back("four");
    s.push_front("two");
    s.push_front("one");

    auto z = "five"s;

    s.emplace_back(z);

    show(s); //

    // cout << size(s) << "\n";
}