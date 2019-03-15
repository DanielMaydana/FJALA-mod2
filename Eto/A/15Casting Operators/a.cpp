// Casting Operators

#include <iostream>
using namespace std;


struct A
{
    virtual ~A() {} // porque es un destructor virtual??
};


struct B : A
{
    void m() const
    {
        cout << "Hello const \n";
    }

    void m()
    {
        cout << "Hello \n";
    }
};


void invoque(long long m)
{
    B* b = reinterpret_cast<B*>(m); // convierte en entero una direccion de memoria, en el numero de memoria donde esta el puntero  
    b->m();
}


int main()
{
    int p = (int) 12.45;
    // auto p = static_cast<int>(12.45);
    cout << p << "   p \n";

    A* a = new B(); 
    cout << a << "\n";

    const B* ca = static_cast<B*>(a); 
    // B* ca = static_cast<B*>(a); 
    cout << ca << "\n";
    ca->m();

    // ((B*)a)->m();
    ca = (const B*)a;
    cout << ca << "\n";
    ca->m();

    auto nca = (B*)ca;
    const_cast<B*>(ca)->m(); // quita el const 

    nca->m();

    long long cb = (long long)ca;
    cout << ca << " ca \n";
    cout << cb << " cb \n";
    invoque (cb);
}