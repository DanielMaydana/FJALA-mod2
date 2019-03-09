#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


int cmp(const void* a, const void* b)
{
    //sabemos que los valores son enteros por eso los casteamos
    auto aa = static_cast<const int*>(a);
    auto bb = static_cast<const int*>(b);
    // cout << *aa << "  " << *bb << "\n"; 
    return *aa - *bb;
}

int cmps(const void* a, const void* b)
{
    auto aa = (const char**) a;
    auto bb = (const char**) b;
    return strcmp(*aa, *bb); // strcmp compara caracter por caracter hasta encontrar uno diferente o nulo
}

int main()
{
    int m[] = {3, 6, 2, 75, 32, 43};

    qsort(m, 6, sizeof(int), cmp); // qsort recibe cmp, la funcion que le dice como ordenar
    for(int n : m) // para cada n de m
        cout << n << "\n";

    const char* ss[] = {"marzo", "abril", "enero"};
    qsort(ss, 3, sizeof(const char*), cmps);
    for(auto i : ss)
        cout << i << "\n";
}