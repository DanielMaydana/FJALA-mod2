// MAPS
    // elementos estan guardados como pares (clave - valor)
    // se recuperan a partie de las claves
    // no hay claves repetidas

    // map -> es un arbol binario de busqueda
    // unordered_map -> es una tabla hash

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> dpm;
    dpm.insert(pair<string, int>{"enero", 31});
    dpm.insert(make_pair("febrero", 28));
    dpm["marzo"] = 31; //busca la clave [] si no la encuentra la crea
    dpm["abril"] = 30;
    dpm["mayo"] = 31;

    dpm.insert(make_pair("febrero", 29)); // ignora esta instruccion

    dpm["febrero"] = 99;
    for(auto& e : dpm)
    {
        cout << e.first << "\t" << e.second << "\n";
    }

    auto it = dpm.find("abril");
    if(it == dpm.end())
        cerr << "not fund\n";
    else    
        cout << it->second << "\n";
}