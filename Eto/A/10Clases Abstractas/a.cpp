// Clases abstractas 
    // es una clase que tiene 1 o mas metodos abstractos
    // obliga a implementar los metodos abstractos en cada clase hija
    // no se puede instanciar, solo las hijas
    // pure virtual method

#include <iostream>
using namespace std;


class Animal
{
private:
    
public:
    Animal() { }
    virtual ~Animal() { } //siempre que se temgas metodos virtuales el destructor es virtual

    virtual void comunicarse() const = 0;  //metodo virtual
};


class Vaca : public Animal
{
private:
    
public:
    Vaca() { }
    ~Vaca() { }

    void comunicarse() const override
    {
        cout << "muuu\n";
    }
};


class Dog : public Animal
{
private:
    
public:
    Dog() { }
    ~Dog() { }
    void comunicarse() const override
    {
        cout << "guau\n";
    }
};

int main()
{
    Animal* e = new Vaca(); // el polimorfismo funciona con punteros
    e->comunicarse();
    delete e;
    e = new Dog();
    e->comunicarse();
    delete e;
}