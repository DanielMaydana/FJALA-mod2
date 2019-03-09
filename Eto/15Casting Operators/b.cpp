#include <iostream>
#include <typeinfo>  // para el bad_cast
using namespace std;



struct X
{
    virtual~X(){}  // porque es virtual??
};


struct Y : X
{
    int* n;
    Y(int p)
    :n{new int {p}}
    {}

    ~Y()
    {
        cout << "Bye " << *n << "\n";
        delete n; 
    } 

    void show()const
    {
        cout << *n << "\n";
    }
};


void print (const X& x)
{
    try
    {
        auto y = dynamic_cast<const Y&>(x);  //con referencias que no se pueden castear bota una excepcion
        y.show();
    }
    catch(const bad_cast& e)
    {
        cout << "it is not Y\n";
    }
}

int main()
{
    // genera crush es mejor utilizar dinamic cast
    // X* x = new X();
    // static_cast<Y*>(x)->show();
    // delete x;

    //utilizar  
    X* x = new X();
    auto y = dynamic_cast<Y*>(x);
    if(y)
        y->show();
    else
        cout << "cannot dynamic_cast x to y\n";

    print (*x);

    delete x;

}

