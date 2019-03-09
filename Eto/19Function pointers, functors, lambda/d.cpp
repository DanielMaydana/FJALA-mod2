// Functors (funtion objects) es porque las funciones no guardan estados
    // son objetos
    // cuya sintaxis permite llamarlos COMO SI fueran funciones

#include <iostream>
using namespace std;

struct Sumador // la clase puede tener estado como descuento
{
    int descuento;

    Sumador() : descuento{4}{}

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

bool is_impar(int n)
{
    return n % 2;
}

template<typename PRED>
void show(const int *a, const size_t n, PRED incoming_f)
{
    for(auto i = 0U; i < n; i++)
    {
        auto& element = a[i];

        if(incoming_f(element)) cout << element << "\n";
    }

    cout << "*********\n";
}

int main()
{
    Sumador s;

    cout << s(10, 15) << "\n"; // se lo llama como si fuera una funcion
    cout << "*********\n";

    int nn[] = {10, 8, 2, 5, 40, 27, 4, 6, 9, 21};

    show(nn, 10, is_impar);

    Range r {10, 30};

    show(nn, 10, r);
    show(nn, 10, Range{2,8});

    show(
        nn,
        10,
        [](int n) -> bool{return n % 2 == 0;}
        // -> para explicitar el tipo de retorno del lambda, si el compilador no reconoce
    );

    cout << "\n";

    int min = 10; 
    int max = 30;

    show(
        nn,
        10,
        [min, max](int n) -> bool{return  n >= min && n <= max;}
    );
}