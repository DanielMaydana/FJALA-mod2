#include <iostream>
#include <string>
#include <tuple>
using namespace std;


void show(const tuple<string, string, int>& s)
{
    cout << get<0>(s) << "\n"; // el indice tiene que ser conocido en tiempo de compilacion
    cout << get<1>(s) << "\n";
    cout << get<2>(s) << "\n";
}


int main()
{
    tuple<string, string, int> p {"Ozzy", "Osbure", 1948};
    auto p2 = make_tuple("jim"s, "morrison"s, 1942);

    show(p);
    show(p2);
}