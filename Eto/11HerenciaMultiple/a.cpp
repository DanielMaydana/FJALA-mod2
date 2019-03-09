// Herencia Multiple
    // Clases pueden basarse en mas de una clase
    // ninguna clase es mas importante que otra
    // no hay limite en el numero de clases base

#include <iostream>
using namespace std;

class Animal
{
private:
    
public:
    Animal() { }
    ~Animal() { }

    void comer()
    {
        cout << "como\n";
    }
};


class Vehiculo
{
private:
    
public:
    Vehiculo() { }
    ~Vehiculo() { }

    void acelera()
    {
        cout << "voy mas rapido\n";
    }
};


class Volador
{
private:
    
public:
    Volador() { }
    ~Volador() { }

    void volar()
    {
        cout << "vuelo alto\n";
    }
};


class Murcielago : public Animal, public Volador
{
private:
    
public:
    Murcielago() { }
    ~Murcielago() { }
    void chupar_sangre()
    {
        cout << "yumie\n";
    }
};


class Avion : public Vehiculo, public Volador
{
private:
    
public:
    Avion() { }
    ~Avion() { }

};

int main()
{
    Avion a;
    a.volar();
    a.acelera();
    
    Murcielago m;
    m.volar();
    m.comer();
    m.chupar_sangre();

}