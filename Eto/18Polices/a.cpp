// Polices   son politicas que no tinenen sintaxis especifica
    //  comportamiento que se inyecta a una clase template, 
    // se especifican al momento de instanciar una clase template 
    // se pasa a traves de un tipo parametrizado

#include <iostream>
using namespace std;

template <typename H> // tiene la politica H
struct Animal
{
    H h; // se esta instanciando la politica
    void habla() const
    {
        cout << "metodo habla animal struct\n";
        h.habla();
    }
};



struct PerroPolicy
{
    void habla() const 
    {
        cout << "guau\n"; 
    }
};


struct VacaPolicy
{
    void habla() const 
    {
        cout << "muuu\n"; 
    }
};


// using Perro = Animal<PerroPolicy>; //perro es un animal que utiliza la politica de perro
// using Vaca = Animal<VacaPolicy>;

template <typename P>
void hablar(const Animal<P>& p)
{
    cout << "metodo hablar template\n";
    p.habla();
}

int main()
{
    // Perro p;
    // Vaca w;
    Animal<PerroPolicy> p;
    Animal<VacaPolicy> w;

    // hablar(p);
    // hablar(w);
    
    p.habla();
    w.habla();

}

