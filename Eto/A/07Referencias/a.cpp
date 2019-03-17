// referencias
    // son "como" punteros con restricciones
    // tiene sintaxis simplificada
    // sirve para hacer paso de parametros por referencia
    // el compilador las entiende como punteros 
    // restricciones:
        // se inicializan al crearse, no como un puntero int* x
        // la referencias son inmutables, siempre se refiere al mismo elemento
        // no existe aritmetica de referencias
        // no existen referencias nulas


#include <iostream>
using namespace std;

void factorial(int n, int* r)
{
    int s = 1;
    
    for(int i = 2; i <= n; i++)
    {
        s *= i;
    }
    *r = s;
}

void factorial2(int n, int& r)
{
    r = 1;
    
    for(int i = 2; i <= n; i++)
    {
        r *= i;
    }
}

int main()
{
    int f;
    factorial(6, &f);
    cout << f << "\n";

    int g;
    factorial2(6, g);
    cout << g << "\n";

    int p = 25;
    int q = 40;
    int& rp = p;
    rp = q;
    rp++;
    cout << p << "\n";
    cout << q << "\n";
    auto rq = q;
    auto rs = rp;
    auto& rr = rq;


}