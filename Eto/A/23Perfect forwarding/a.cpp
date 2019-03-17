#include <iostream>
using namespace std;

int suma(int a, int b)
{
    return a + b;
}

// template <typename...ARGS>
// auto suma(ARGS...args)
// {
//     auto result;
//     return result + args...;
// }

template<typename PROC, typename...ARGS>
auto invoke(PROC p, ARGS&&...args) // ARGS&& para que edite el valor por referencia
{
    // return p(args...); // es mejor utilizar forward porque alguno podria necesitar copia y otro movida
    return p(forward<ARGS>(args)...);
}


int inc(int& n)
{
    n++;
    return n;
}

int main()
{
    auto r = invoke(suma, 4, 3);
    cout << r << "\n";

    int n = 8;
    invoke(inc, n);
    cout << n << "\n";
}