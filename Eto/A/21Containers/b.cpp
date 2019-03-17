// las listas son eficientes si se agrega al inicio o al final, y eliminar elementos al medio
// es ineficiente si se agregan elementos al medio 
// es una lista doblemente enlazada

#include <iostream>
#include <list> 
#include <string>
using namespace std;


template<typename T>
void print(const T& x)
{
    for(auto& i : x)
    {
        cout << i << "\n";
    }
}

template<typename T, typename PRED>
void erase_items(list<T>& e, PRED p)
{
    for(auto i = e.begin(); i != e.end(); /*Nothing*/)
    {
        if(p(*i))
        {
            i = e.erase(i);
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    list<string> dias = {"martes", "miercoles", "jueves", "viernes", "sabado"};
    dias.push_back("domingo");
    dias.push_front("lunes");
    print(dias);
    cout << dias.size() << "\n";
    erase_items(dias, [](auto& x)
    {
        return x[0] == 'm';
    });
    print(dias);
}