#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

struct Person
{
    string fn;
    string ln;
};

int main()
{
    Person p[] = {Person{"juan", "perez"}, Person{"Jorge", "Lopez"}, Person{"Omar", "vera"}, Person{"Alvaro", "Peres"}};
    sort(p, p + 4,[] (auto& a, auto& b)
    {
        return tie(a.ln, a.fn) < tie(b.ln, b.fn);
    });
    
    for(auto& i : p)
    {
        cout << i.ln << " " << i.fn << "\n";
    }
}