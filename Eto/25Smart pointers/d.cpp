// weak pointer
    // objeto que apunta a un shared_ptr
    // el weak pointer no hace que incremente el contador de referencia y por eso puede llegar a 0 el contador y se destruye a pesar que el weak pointer lo esta apuntando
    // no tiene el operador -> 

#include <iostream>
#include <memory>

using namespace std;

struct Hijo;

struct Padre // esta compuesta de un hijo
{
    shared_ptr<Hijo> hijo;

    ~Padre()
    {
        cout << "struct Padre instance hijo deleted\n";
    }

    void cocinar()
    {
        cout << "cocinando\n";
    }
};

struct Hijo // agrega un padre
{
    weak_ptr<Padre> padre;

    ~Hijo()
    {
        cout << "struct Hijo instance padre deleted\n";
    }
};

int main()
{
    auto p = make_shared<Padre>();
    auto h = make_shared<Hijo>();
    
    p->hijo = h;
    h->padre = p;
    
    h->padre.lock()->cocinar(); // el metodo lock() devuelve un shared pointer y evita que se destruya el objeto

    shared_ptr<string> s;
    weak_ptr<string> ws = s;
    {
        s = make_shared<string>("hello");
        ws = s;
        cout << ws.lock()->c_str()<< "*\n";
        cout << ws.expired() << "exp\n"; // muestra si tiene alguien apuntando, es bueno verificar antes de hacer un lock()
        s.reset();
    }

}