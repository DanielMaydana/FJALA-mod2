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

bool ci_less_func(const ci &a, const ci &b) // function doesn't neet const at the end cause it doesn't have this
{
    // tie has implemented the < operator, easier than writing own overridea
    return tie(a.number, a.city) < tie(b.number, b.city); // will order first by number and then by city
}

struct ci_less_func_class
{
    bool operator()(const ci &a, const ci &b) const
    {
        return tie(a.number, a.city) < tie(b.number, b.city);
    }
};

int main()
{
    // map<ci, string, bool (*)(const ci &a, const ci &b)> ps{ci_less_func}; // using a ptr to a function instead of a class comparator
    map<ci, string, ci_less_func_class> ps;

    ps[ci{2, "SCZ"}] = "Roberto Fontanarrosa";
    ps[{1, "LPZ"}] = "Richie Havens";
    ps[{1, "CBBA"}] = "Leah Shapiro";
    ps[{3, "LPZ"}] = "Robert Levon Been";

    for (auto &e : ps)
    {
        cout << e.first.number << e.first.city << "\n";
    }
}