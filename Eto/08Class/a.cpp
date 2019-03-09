// RAII Resourse Acquisition Is Initialization
// consiste en que cuando se crea un objeto se asignan recursos, cuando el objeto es eliminado devuelve los recursos

#include <iostream>
#include <cstring>
using namespace std;



class curso
{
private:
    char nombre[16];
    size_t alumnos;

public:
    curso(const char* n, size_t al)
    {
        strcpy(nombre, n);
        alumnos = al;
    }

    ~curso() //normalmente es publico
    { 
        cout << "adios\n";
    }

    void mostrar() const // metodo constante, no modifica los atributos de la clase, es mejor empezar desde el principio con const
    {
        cout << nombre << " " << alumnos << "\n";
    }
};

int main()
{
    curso c{"dev27", 18};
    c.mostrar();

    curso* d = new curso{"dev27h", 17};  // no se debe usar malloc con objetos porque no va al constructor
    d->mostrar();
    delete d; // llama al destructor, libera la memoria 
}