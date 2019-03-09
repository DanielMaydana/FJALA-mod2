// el calculo de fact lo hace el compilador y no crea codigo, solo guarda el resultado del calculo


#include <iostream>
#include <string>
using namespace std;

template<int N>
struct fact
{
    static const int value = N * fact<N-1>::value;  // que es :: o que significa??? es fact en su value??
};

template<>
struct fact<1>
{
    static const int value = 1;
};

int main()
{
    cout << fact<5>::value << "\n";
}