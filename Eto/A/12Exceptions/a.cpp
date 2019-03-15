#include <iostream>
using namespace std;

void c()  // lanza el error de texto o unsigned long number, el primero que ocurra
{
    throw "hello";
    cout << "prueba\n";  // al encontrar throw sale de este ambito y no ejecuta esta linea
    throw 1UL;
}

void b()
{
    cout << "b\n";
    // throw true;
    // int* c = nullptr;
    // *c = 40;
    int d = 14, b = 0;
    int e = d/b;
    cout << e << "variable e\n";
}

void a()
{
    c();
    cout << "a\n";
}

int main()
{
    try
    {    
        b();
    }
    catch(const char* s)
    {
        cerr << s <<"\n";
    }
    catch(size_t p)
    {
        cerr << "error " << p << "\n";
    }
    catch(...)
    {
        cerr << "Unknown error\n";
    }
}