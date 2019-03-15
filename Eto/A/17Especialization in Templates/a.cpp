#include <iostream>
#include <string>
using namespace std;


template<typename T>
void sucesor(const T& n)
{
    cout << (n+1) << "\n";
}

template<> // el compilador busca las especializaciones y si no encuentra utiliza el primer template
void sucesor<string>(const string& s)
{
    cout << s << " no tiene sucesor\n";
}

template<>
void sucesor<char>(const char& s)
{
    cout << s << " es un char\n";
}

int main()
{
    sucesor(12);
    sucesor("hola"s);
    sucesor('x');
}