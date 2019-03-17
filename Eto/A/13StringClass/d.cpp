#include <iostream>
#include <cstring>
#include <string>
#include <string_view> // no es duanha del string, solo lo apunta y no lo construye ni destruye
using namespace std;
using namespace std::string_literals;


int main()
{
    auto dm = "Despeche Mode"s;
    
    for(string::iterator i = dm.begin(); i != dm.end(); ++i)  // ++i es mas eficiente que i++ 
    {
        cout << *i << "\n";
    }

    for(string::reverse_iterator i = dm.rbegin(); i != dm.rend(); ++i)
    {
        cout << *i << "\n";
    }

    for(auto k : dm)  // auto es char
    {
        cout << k << "\n";
    }

    //para obtener el const char* para trabajar con funciones escritas en c
    char aux[100];
    strcpy(aux, dm.data());  // data es igual a c_str()
    strcat(aux, " Rocks!!!");
    cout << aux << "\n";
    
}