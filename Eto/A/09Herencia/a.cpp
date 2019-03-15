// Herencia
// en c++ se puede heredar de una o mas clases
// es la base de la reutilizacion de codigo
// es la piedra fundamental del polimorfismo
// en c++ NO hay una gerarquia de classes predefinida
// la herencia puede ser 
    // HERENCIA           BASE                 DERIVADA
    // public      public => protected     public =>protected
    // protected   public => protected     protected => protected 
    // private     public => protected     privado
// polimorfismo
    // dos instancias de una misma clase base reaccionan de manera diferente ante un mismo mensaje
    // se implementa con sobrescritura 


#include <iostream>
using namespace std;

    
class Vehicle
{
private:
    size_t max_speed;
public:
    Vehicle(size_t ms) 
    :max_speed{ms}
    { }

    virtual ~Vehicle() { }

    virtual void print() const
    {
        cout << "Max Speed: " << max_speed << "\n";
    }
};


class Airplane : public Vehicle
{
private:
    size_t max_heigth; 
public:
    Airplane(size_t ms, size_t mh)
    :Vehicle{ms}, max_heigth{mh} 
    { }

    ~Airplane() 
    { }

    void print() const override  //es un metodo sobrescrito de su clase padre
    {
        Vehicle::print();  // :: operador de ambito para llamar un metodo de una clase padre
        cout << "Max Heigth: " << max_heigth << "\n";
    }
};

void show(const Vehicle& a)
{
    a.print();
}

int main()
{
    Vehicle x{150};
    Airplane y{500, 3000};
    // x.print();
    // cout << "******\n";
    // y.print(); // HIDING el compilador oculta los metodos de ka clase base y usa los de la clase hija

    show(x);
    show(y);
    Vehicle* z1 = new Vehicle{25};
    z1->print();
    Airplane* z2 = new Airplane{10, 100};
    z2->print();
    Vehicle* z3 = new Airplane{80, 20};
    z3->print();

    delete z1;
    delete z2;
    delete z3; //llama al destructor de vehiculo y no destruye el objeto completo. a menos que el destructor sea virtual

}