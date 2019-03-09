#include <iostream>
using namespace std;

void es_par(const char** x, int n)
{
    if(n % 2 == 0)
        *x = "par";
    else
        *x = "impar";
}

int main()
{
    const char* s = NULL; // null se transforma en 0 durante la compilacion
    // int* r = nullptr;   // es de un tipo de dato nullptr_t y es una palabra reservada

    es_par(&s, 64);
    cout << s << "\n";

}