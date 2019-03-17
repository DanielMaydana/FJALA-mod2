// sirve para evitar polimorfismo
// visit(f, variant) 

#include <iostream>
#include <map>
#include <memory>
#include <variant>
using namespace std;

struct automovil
{
    void mover()
    {
        cout << "automovil se mueve\n";
    }
};

struct avion
{
    void mover()
    {
        cout << "avion se mueve\n";
    }
}; 

struct barco
{
    void mover()
    {
        cout << "barco se mueve\n";
    }
}; 

using vehiculo = variant<automovil, avion, barco>; // puede ser un solo tippo de esos

int main()
{
    map<string, vehiculo> vs;
    vs["1453GEE"] = automovil{};
    vs["8946ERM"] = avion{};
    vs["9275ICD"] = barco{};

    get<avion>(vs["8946ERM"]).mover();
    // get<avion>(vs["9275ICD"]).mover(); // trata de sacar un tipo de dato que no es y bota un excepcion bad_variant_access

    for(auto& e : vs)
    {
        cout << e.first << " ";
        visit(//necesita ser auto porque llama a finciones para cada tipo
            [](auto& p){p.mover();},
            e.second
        );
    }
}
