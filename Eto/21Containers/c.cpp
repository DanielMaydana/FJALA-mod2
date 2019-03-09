// es un array en el heap

#include <iostream>
#include <vector> 
#include <string>
using namespace std;


struct X
{
    ~X()
    {
        cout << "bye\n";
    }
};



int main()
{
    vector<int> n = {6, 7, 2, 7, 9, 3, 1};
    n.push_back(17);
    n.push_back(9);
    cout << n[5] << "\n";  //no verifica si el vector es de el tamamho solicitado
    cout << n.at(2) << "\n"; //verifica que es un indice valido y si no devuelve una excepcion


    // vector<X> x1 = {X{}, X{}, X{}};  // el vector almacen una copia de los objetos
    vector<X*> x2 = {new X(), new X(), new X()}; // es util utilizar punteros para polimorfismo, pero es recomendable no utilizr punteros

    for(auto& i : x2)
        delete i;
}