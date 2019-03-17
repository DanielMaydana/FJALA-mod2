// g++ b.cpp -o main -Wall -O2 -g0   compila de la forma mas eficiente y es para la etapa de relice 


#include <iostream>
#include <string>
using namespace std;

template<int N>
int factorial()
{
    return N * factorial<N - 1>();
}

template<>
int factorial<1>()
{
    return 1;
}

int main()
{
    cout << factorial<5>() << "\n";
}