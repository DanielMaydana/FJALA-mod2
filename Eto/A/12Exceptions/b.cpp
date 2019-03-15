#include <iostream>
using namespace std;

void p()
{
    cout << "hello method p\n";
    throw 5;
}

struct A
{
    A()
    {
        cout << "instance of struct A created\n";
    }

    ~A()
    {
        cout << "instance of struct A deleted\n";
    }
};

int main()
{
    try
    {
        A a;  // al ser variable stack se eliminara sola al salir del scope
        p();
    }
    catch(int n)
    {
        cerr << "error " << n << "\n";
    }
}
