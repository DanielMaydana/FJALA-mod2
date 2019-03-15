#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;

void z()
{
    throw 65;
}
// false es como si no hubiera no except, sirve para cambiar a true en tiempo de compilacion con templates
void y() noexcept (false)  
{
    cout << "function y called\n";
    z();
}

int main()
{
    try
    {
        y();
    }
    catch(int n)
    {
        cerr << n << " Errores \n";
    }
}