// templates
    // Paradigma: programacion generica
        // tener tipos de datos y valores parametrizables
        // turing complite
            // c++ esta evolucionando por este lado

    // ventajas
        // codigo reusable
        // no polimorfismo, entonces mejor rendimiento porque no necesita buscar en tabla (vtable)
        // mejor rendimeinto que con tipos abstractos 
    
    // desventajas
        // mensajes de error inentendibles (se solucionara en el standar 20 con los conceptos)
        // tiempo de compilacion lento
        // no hay separacion .h y .cpp, todo se debe implementar en el .h
        // los binarios son mas grandes

    // el compilador no genera codigo al encontrar el template, despues caundo encuentra 
        // una llamada al template genera codigo para el tipo de dato encontrado
    // y si encuentra otra llamada con otro tipo de dato genera otro codigo 


// para ver el codigo generado por el compilador en los template se puede utilizar:
// nm -C main(nombre del ejecutable) | grep sum

#include <iostream>
#include <string>
using namespace std;  

struct MyInt
{
    int n;

    MyInt operator + (const MyInt& p) const
    {
        return MyInt{n + p.n};
    }
};

template<typename T>
T sum(T x, T y)
{
    return x + y;
}


int main()
{
    cout << sum(6, 8) << "\n";
    cout << sum(3.25, 8.59) << "\n";
    cout << sum<string>("hello ", "world") << "\n";  // con clases es necesario pasarle el tipo de dato
    cout << sum(MyInt{8}, MyInt{25}).n << "\n";

}


