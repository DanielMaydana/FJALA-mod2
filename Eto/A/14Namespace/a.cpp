// namespaces

// una agrupacion logica de identificadores
// sirve para evitar name crushes, cuando se definen varias veces el mismo nombre de funcion por ejemplo

#include <iostream>
// using namespace std;
using std::cout;


namespace funcs
{
    void f()
    {
        cout << "hello\n";
    }

    void g()
    {
        cout << "2018\n";
    }
}

void g()
{
    cout << "2017\n";
}

// using namespace funcs;
int main()
{
    funcs::f();
    funcs::g();
    g();
}


