#include <iostream>
#include <tuple>
#include <set>

using namespace std;


struct mypair
{
    int x, y;
};

struct my_pair_comparator
{
    bool operator() (const mypair& a, const mypair& b) const
    {
        return tie(a.x, a.y) < tie(b.x, b.y); //compara los x y luego los compara creando una tupla de referencias
    }
};

// sobrecargamos el ostream para imprimir un objeto mypair
ostream& operator << (ostream& os, const mypair& e)
{
    os << "(" << e.x << ", " << e.y << ")";
    return os;
}

bool c2(const mypair&a, const mypair& b)
{
    return tie(a.y, a.x) < tie(b.y, b.x);
}

int main()
{
    using ctype = bool(*)(const mypair&, const mypair&);
    // set<mypair, my_pair_comparator> mps; // los set necesitan un metodo que le diga como ordenar 
    // set<mypair, decltype(c2)> mps{c2}; // decltype determina el tipo de dato y lo utiliza en tiempo de compilacion
    set<mypair, ctype> mps{c2};
    mps.insert(mypair{6, 5});
    mps.insert(mypair{8, 2});
    mps.insert(mypair{4, 9});
    mps.insert(mypair{6, 6});
    for(auto& e : mps)
        cout << e << "\n";
}