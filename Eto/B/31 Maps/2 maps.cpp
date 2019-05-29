#include <string>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class ci
{
public:
    size_t number;
    string city;
};

struct ci_less // could be comparators for many types
{
    bool operator()(const ci& a, const ci& b) const // needs to be constant cause map uses const 
    {
        if(a.number < b.number)
        {
            return true;
        }

        if(b.number < a.number)
        {
            return false;
        }

        return a.city < b.city;
    }
};

int main()
{
    // unordered_map<string, int> ss;
    map<ci, string, ci_less> ps; //ci_less is a class to compare ci overloading operator()

    ps[ci{2, "SCZ"}] = "Roberto Fontanarrosa";
    ps[{1, "LPZ"}] = "Richie Havens";
    ps[{3, "LPZ"}] = "Robert Levon Been";

    for(auto& e : ps)
    {
        cout << e.first.number << e.first.city << "\n";
    }
}