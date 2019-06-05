#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <memory>
#include <array>
#include <list>
#include <set>           // use if we want an ordered set
#include <unordered_set> // use if we don't :P

using namespace std;

template <typename Container>
void show(const Container &c) // same function as in '3 list.cpp' file
{
    for (auto &i : c)
    {
        cout << i << "\n";
    }
}

int main()
{
    unordered_set<string> s;
    s.insert("java");
    s.insert("cobol");
    s.insert("python");
    s.insert("javascript");

    show(s);

    auto i = s.find("javascriptxxx"); // returns an iterator

    printf("it: %s\n", *i);
}