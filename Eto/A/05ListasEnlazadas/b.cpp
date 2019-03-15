// struct 
    // puede tener varios campos adentro
    // cada campo tiene su nombre
    // los campos pueden ser de diferente tipo

// Clases
    // puede tener varios atriburtos dentro 
    // cada atributo tiene nombre
    // cada atributo puede ser diferente tipo

#include <iostream>
#include <cstring>
using namespace std;

struct Persona
{
    char nombre[32];   // campos
    char apellido[32];
    size_t ci;
};


// class Persona2
// {
// private:
//     char nombre[32];  // atributos
//     char apellido[32];
//     size_t ci;
// public:
//     Persona2() { }
//     ~Persona2() { }
// };
void init(Persona* p, const char* n, const char* a, size_t ci)
{
    strcpy((*p).nombre, n); //no tiene tamano de cadena, eso lo hace peligroso
    strcpy(p->apellido, a);
    (*p).ci = ci;
}

void print(const Persona* p)
{
    cout << p->nombre << " " << p->apellido << " " << p->ci << " \n";
}

int main()
{
    Persona p;
    init(&p,"Ivan", "Rios", 123456);
    print(&p);

    Persona* h = new Persona{};
    init(h, "jose maria", "leyes", 245634);
    print(h);
    delete h;
}
