// cuando la clave es un objeto se debe implementar una funcion he hashseo y una funcion de comparacion 

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct key
{
    int id1;
    int id2;
};

struct key_hash  // para acomodar los elementos en la tabla
{
    size_t operator() (const key& e) const
    {
        return e.id1 * 31 + e.id2;
    }
};


struct key_eq // para comparar
{
    bool operator() (const key& a, const key& b) const
    {
        return a.id1 == b.id1 && a.id2 == b.id2;
        // return 0;
    }
};

int main()
{
    unordered_map<key, string, key_hash, key_eq> s;
    s[key{10, 15}] = "veinte y cinco";
    s[key{2, 8}] = "diez";
    s[key{4, 7}] = "once";
    s[key{18, 2}] = "veinte";

    for(auto& e : s)
    {
        cout << e.first.id1 << "\t" << e.first.id2 << "\t" << e.second << "\n"; 
    }

    auto it = s.find(key{2, 8});
    if(it != s.end())
        cout << it->second << "\n";
}