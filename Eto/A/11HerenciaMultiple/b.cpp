// problemas por ambiguedad


#include <iostream>
using namespace std;


struct M
{
    void cantar()
    {
        cout << "lalala\n";
    }
};


struct N
{
    void cantar()
    {
        cout << "una piedra en el camino\n";
    }
};

struct O : M, N
{
    void cantar()
    {
        cout << "los pollitos dicen\n";
    }
};



struct P: M, N
{
    
};


int main()
{
    M m;
    N n;
    O o;

    m.cantar();
    n.cantar();
    o.cantar(); //hasta aca funciona bien por la propiedad hiding

    P p;
    // p.cantar();  // no funciona porque el compilador no sabe a cual metodo llamar
    p.M::cantar();
    p.N::cantar();
}