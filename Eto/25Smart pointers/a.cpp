// es un objeto que implementa o sobrecarga * y ->
    // unique_ptr
    // shared_ptr
    // weak_ptr

    // auto_ptr fue deprecado y reemplazado por unique_ptr

#include <iostream>
#include <memory>

using namespace std;

struct N
{
    int n;

    N(int n) : n{n}
    {}

    ~N()
    {
        cout << "\nstruct N deleted\n";
    }
};

int main()
{
    // N* p = new N{16};
    // cout << p->n << "\n";
    // delete p;  // en ciertas condiciones podria no llegar  a esta linea y dejar memory leaks 

    unique_ptr<N> p {new N{16}};  // p es una variable de stack y por RAII se libera
    cout << p->n << "\n";
    cout << (*p).n << "**\n";

    unique_ptr<N> p2 = move(p);

    // N* pp = p.get(); // recupera el puntero a N y ya no es un puntero
    // cout << pp->n << "\n";
    // cout << p.get();
    // cout << "\n";
    // cout << p2.get();

    int i = 25;

    auto q = make_unique<N>(i);  //pasa los parametros al constructor que tiene que estar escrito
    cout << q->n << " the int inside N\n";

    auto r = move(q);  // no se podria hacer una copia solo una  movida
    cout << r->n << " \n";
    cout << q.get() << "\n";

}