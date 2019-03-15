// unordered set
    // los elementos se encuentran en una tabla hash
    // es una tabla que ocupa mucho espacio
    // las tablas hash estan divididas en slots que son normalmente 7
    // existe una funcion hash transforma los elementos a numero ej h(8) = 8  8 mod 7 = 1 entonces ocupa el slot 1
    // insert O(1) + rehash
    // find O(1)
    // erase O(1)

#include <iostream>
#include <tuple>
#include <unordered_set>
#include <string>

using namespace std;





int main()
{
    unordered_set<string> ms;
    ms.insert("january");
    ms.insert("february");
    ms.insert("april");
    ms.insert("may");
    ms.insert("june");

    for(auto& e : ms)
        cout << e << "\n";

    ms.erase("april");

    for(auto& e : ms)
        cout << e << "\n";

    unordered_set<string>::iterator it = ms.find("may");

    if(it == ms.end())
        cerr << "not found\n";
    else
        cerr << *it << "\n";

}