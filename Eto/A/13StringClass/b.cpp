#include <iostream>
#include <string>
using namespace std;
using namespace std::string_literals;






int main()
{
    string a = "hoy";
    a += " es";
    a += " viernes";
    cout << a << "\n";
    cout << a.length() << "\n";  // length devuelve un size_t
    a[0] = 'b';
    a[2] = 'i';
    a.push_back('!');
    a.push_back('!');
    a.push_back('!');
    a.insert(3, " ");
    a.insert(0, "!");

    auto b = a.substr(1, 3);
    cout << b << "\n";

    auto v = a.substr(9);
    cout << v << "\n";

    auto d = "dinosaurio"s; // ya no const char*, ahora es string pero debemos aumenta using namespace

    auto index = d.find("sau"); // si no encuentra devuelve -1 que es un string::npos casteado para soportar unsigned
    if(index == string::npos)
    {
        cout << "no encontrado\n"; 
    }
    else 
    {
        cout << index << "\n";
    }

    


    // try
    // {
        
    //     for(auto i = 0U; i < a.length()+2; i++) 
    //     {
    //         // cout << a.at(i) << "\n";  // el metodo add verifica que siempre este dentro el rango
    //         cout << a[i] << "\n";  // [ ] no incluye la verificacion de at y por eso es mas eficiente
    //     }
        
    // }
    // catch(const exception& e)
    // {
    //     cerr << e.what() << '\n';
    // }
    
}