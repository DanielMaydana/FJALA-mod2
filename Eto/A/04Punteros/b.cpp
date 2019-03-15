#include <iostream>
using namespace std;
size_t size(char* cadena)
{
    size_t count = 0;
    while(cadena[count] != 0)
    {
        count++;
    }
    return count++;
}

void copiar_cadena(char* destino, const char* fuente)
{
    size_t count = 0;
    while(fuente[count] != 0)
    {
        destino[count] = fuente[count];
        count++;
    }
    destino[++count] = 0;
}

void concatenar_cadena(char* destino, const char* fuente)
{
    size_t count = size(destino);
    size_t inicio = 0;
    destino[count++] = ' ';
    while(fuente[inicio] != 0)
    {
        destino[count] = fuente[inicio];
        count++;
        inicio++;
    }
    destino[++count] = 0;
}

void substraing(char* destino, const char* fuente, size_t fin, size_t inicio)
{
    size_t count = 0;
    while(fuente[inicio] != 0)
    {
        destino[count] = fuente[inicio];
        count++;
        inicio++;
    }
    destino[count] = 0;
}

int main()
{
    // const char* c = "fundacion";
    // const char* d = "jala";
    // char cd[30];
    // copiar_cadena(cd, c);
    // cout << cd << "\n";
    // concatenar_cadena(cd, d);
    // cout << cd << "\n";

    auto r = "hoy es lunes 12";
    char rr[10];
    substraing(rr, r, 7, 5);
    cout << rr << "\n";
}