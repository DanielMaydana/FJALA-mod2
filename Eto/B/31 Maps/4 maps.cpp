#include <string>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

struct car_id
{
public:
    string s;
    int id;
};

struct car_id_hash
{
    size_t operator()(const car_id& c) const // override () instead of == operator
    {
        hash<string> h;
        return h(c.s);
    }
};

struct car_id_eq
{
    bool operator()(const car_id& a, const car_id& b) const // override () instead of == operator
    {
        return a.s == b.s && a.id == b.id;
    }
};

int main()
{
    unordered_map<car_id, string, car_id_hash, car_id_eq>cars; // unordered map needs a functions that returns a hash and comparator function (or classes)

    cars[{"111", 1}] = "Romulo Rojas";
    cars[{"222", 2}] = "Pablo Azero";
    cars[{"333", 3}] = "Marcelo";

    for(auto& e : cars)
    {
        cout << e.first.s << "\t" << e.second << "\n";
    }
}