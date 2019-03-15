// cadenas strings

// aritmeticas de punteros
    // operaciones disponibles: - + ++ --

#include <iostream>
using namespace std;

size_t calq_length(const char* cadena)
{
    const char* copy = cadena;
    // size_t count = 0;
    while(*cadena)
    {
        cadena++;
    }
    return cadena - copy;
}

int main()
{
    const char* q = "hello world"; // el compilador coloca la cadena en el area de memoria de solo lectura
                                    // colocando el const evita cometer errores y tratar de modificar
    cout << q << "\n";

    char s[] = "hola mundo"; // el array de caracteres esta en el stack
    cout << s << "\n";
    s[0] = 'c';
    cout << s << "\n";
    // q[1] = 'o'; // provoca un segmentacion fould porque no se puede editar la memoria de solo lectura 
    // q[5] = 'w';    
    // cout << q << "\n";

    cout << calq_length(q) << "\n";
    cout << calq_length(s) << "\n";

}