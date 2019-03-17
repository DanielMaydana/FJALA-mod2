<<<<<<< HEAD
#include<iostream>
using namespace std;

int sum(int a, int b){
    return a + b;
}

int sub(int x, int y){
    return x - y;
=======
// Functors (funtion objects) es porque las funciones no guardan estados
    // son objetos
    // cuya sintaxis permite llamarlos COMO SI fueran funciones

#include <iostream>
using namespace std;

struct Sumador // la clase puede tener estado como descuento
{
    int descuento;

    Sumador() :descuento{4}{}

    // ~Sumador() { }

    int operator()(int a, int b) const // para que sea functor se debe sobrecargar el operador ()
    {
        cout << "sumador \n";
        return a + b - descuento;
    }
};

struct Range
{
    int min, max;
    
    bool operator()(int n) const
    {
        return n >= min && n <= max;
    }
};

bool is_impar(int& n)
{
    return n % 2;
}

template<typename PRED>
void show(const int *a, const size_t n, PRED is_odd)
{
    for(auto i = 0U; i < n; i++)
    {
        auto e = a[i];
        if(is_odd(e)) cout << e << "\n";
    }

    cout << "* * * * * * * * *\n";
>>>>>>> 1035ed4a6ea73219e55b97ee698e7ae9222e53d1
}

int main()
{
<<<<<<< HEAD
    int(*ptr_to_func)(int, int) = sum;

    cout << ptr_to_func(3, 4) << "\n";

=======
    Sumador s;
    cout << s(10, 15) << "\n* * * * * * * * *\n"; // se lo llama como si fuera una funcion

    int nn[] = {10, 8, 2, 5, 40, 27, 4, 6, 9, 21};

    show(nn, 10, is_impar);

    Range r {10, 30};

    show(nn, 10, r);
    show(nn, 10,Range{2,8});

    show(nn, 10, [](int n)->bool
    {
        return n % 2 == 0;
    });
    cout << "\n";

    int min = 10; 
    int max = 30;
    show(nn, 10, [min, max](int n)
        {
            return  n >= min && n <= max;
        });
>>>>>>> 1035ed4a6ea73219e55b97ee698e7ae9222e53d1
}