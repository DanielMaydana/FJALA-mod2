// SETS  
    // esta implementado como un arbol binario de busqueda balanceado
    // unordered_set viene con una tabla HASH


#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<string> s;
    s.insert("java");
    s.insert("c++");
    s.insert("rust");
    s.insert("swift");
    s.insert("python");
    s.insert("c#");

    // for(auto i = s.begin(); i != s.end(); ++i)
    for(auto& x : s)
    {
        // cout << *i << "\n";
        cout << x << "\n";
    }
    s.erase("swift");

    for(auto& x : s)
    {
        cout << x << "\n";
    }

    auto it = s.find("python");
    if(it != s.end())
    {
        cout << "found and Kelled: " << *it << "\n";
        s.erase(it);
    }
    else
    {
        cerr << "not found\n";
    }
}