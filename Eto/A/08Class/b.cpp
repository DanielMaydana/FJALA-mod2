#include <iostream>
#include <cstring>
using namespace std;

class carro
{
private:
    char* description;
    char id[10];
public:
    carro(const char* des, const char* id) 
    { 
        auto len = strlen(des);
        description = new char[len+1];
        memcpy(description, des, len+1);
        strcpy(this->id, id);
    }

    carro(const carro& c)  // constructor copia  c3 es c
    {
        strcpy(id, c.id);
        auto len = strlen(c.description);
        description = new char[len+1];
        memcpy(description, c.description, len + 1);
    }
    ~carro() 
    { 
        delete [] description;
    }

    const char* get_description() const
    {
        return description;
    }

    const char* get_id() const
    {
        return id;
    }

    carro& operator = (const carro& c)
    {
        if(this == &c)
            return *this;  //si estan apuntadno al mismo lugar no tiene sentido hacer una copia
        this->~carro();
        auto len = strlen(c.description);
        description = new char[len + 1];
        memcpy(description, c.description,len+1);
        return *this;

    }
};


int main()
{
    auto c1 = carro{"Peta1976", "123AFHR"};
    // {   // las llaves hacen que los objetos vivan solo en ese ambito y para casos de objetos de objetos muy demandantes
        // carro c2 {"toyota corolla", "736BRS"};
        auto c2 = c1; // si no se tiene constrictor copia, se intenta borrar dos veces el mismo descripcion y genera error
        cout << c1.get_description() << "\n";
        cout << c2.get_id() << "\n";
    // }
    cout << "hoy es lunes\n";

    auto c3 = carro{"lamborghini Huracan 2018", "954GEA"};
    c3 = c2;  // copia, es necesario sobrecargar el operador =

}