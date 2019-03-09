#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


struct ph
{
    size_t operator()(int* e) const
    {
        return *e;
    }
};

struct pe
{
    bool operator()(int* a, int* b) const
    {
        return *a == *b;
    }
};

int main()
{
    unordered_map<int*, string, ph, pe> p;
    p[new int{10}] = "diez";
    p[new int{11}] = "once";
    p[new int{14}] = "catorce";
    p[new int{0}] = "cero";

    int pivot = 0;
    auto i3 = p.find(&pivot);
    cout << i3->second << "*\n";
}