// Variadics Templates desde c++11
    // soporta cualquier cantidad de parametros
// nm -C ./main | grep sum   compilar para ver las funciones 
#include <iostream>
using namespace std;

template<typename T, typename U>
auto sum(const T& a, const U& b)
{
    return a + b;
}

template<typename T, typename...PARAMS> // PARAMS es un Parameter Pack
auto sum(const T& n, const PARAMS&...args)
{
    return n + sum(args...);  // args... pack expancion 
}

int main()
{
    cout << sum(2.9, 8.1) << "\n";
    cout << sum(2, 9.5, 1) << "\n";
    cout << sum(3, 8, 15, 4, 2, 1) << "\n";
}