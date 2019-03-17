#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using namespace std::string_literals;
using namespace std::placeholders;

int sum(int x, int y)
{
    return x + y;
}

void v1(const string& s)
{
    cout << s << " v1\n";
}

void v2(const string& a, const string& b)
{
    cout << a << "\t" << b << " v2\n";
}

void v3(int a, const string& b, int c)
{
    cout << a << "\t" << b << "\t" << c << " p\n";
}

void invertir(string& s)
{
    cout<<":v\n";
    reverse(s.begin(),s.end());//sirve para cadenas vectores y arrays
}

int main()
{
    // function<int(int, int)> func1 = sum;
    // cout << func1(10, 15) << "\tfunc1\n";

    vector<function<void(const string&)>> visitors;
    visitors.push_back(v1);
    visitors.push_back(
            [](auto& s2) {
            cout << "***\t" << s2 << " l1\n";
        }
    );
    // string h="hello world";
    // visitors.push_back(
    //     [&h](auto& s) {
    //         cout << h << ":" << s << " l2\n";
    //     }
    // );
    auto x = bind(v2,"HHHHH",_1);
    // // para ejecutar funciones rapidas, averiguqar que es el barrabaja1,
    // // BIND agarra una funcion y la convierte en lo que necesitamos, esto quiere decir adapta mi funcion a lo que necesito
    visitors.push_back(x);
    // visitors.push_back(bind(v2,_1,"HHHHH"));//remplaza el _1 con lo que se le pasa como parametro
   
    v3(2,"lunes",8);
    auto qq = bind(v3,_1,_3,_2);
    qq(15,25,"martes"s);

    // auto r=bind(v3,10,_1,50);
    // r("mierc");

    // string xs="oliver";
    // invertir(xs);
    // cout<<xs<<"\n";

    // string yy="atinauj";
    // auto inv=bind(invertir,yy);//bind recive copias delos parametros, o guarda una copia, el ref crea un reference wrappe
    // // auto inv=bind(invertir,ref(yy));//bind recive copias delos parametros, o guarda una copia, el ref crea un reference wrapper
    // inv();
    // cout<<yy<<"\n";

    for(auto& e: visitors)
    {
        e("Something ocurred");
    }
    return 0;
}