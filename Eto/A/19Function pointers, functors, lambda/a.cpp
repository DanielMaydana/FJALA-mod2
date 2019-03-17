// Funtion Pointers
    // almacenan una direccion de memoria
    // en lugar de apuntar a un dato apuntan a una funcion
    // la sintaxis de los punteros a funciones especifican la signatura de la funcion apuntada

    // Usos
        // polimorfismo "ad hoc" primitivo

#include <iostream>
using namespace std;

int suma(int a, int b)
{
    return a + b;
}

int resta(int x, int y)
{
    return x - y;
}

int main()
{
    int (*q)(int, int); // esta es la signatura 
    q = suma; // antes de hacer esta asignacion esta apuntando a nada y puede ocacionar crash
    cout << q(18, 17) << "\n";
    q = resta;
    cout << q(24, 5) << "\n";

    int (*p)(int, int);
    p = suma;
    cout << p(9, 8) + q(6, 5) << "\n";
}