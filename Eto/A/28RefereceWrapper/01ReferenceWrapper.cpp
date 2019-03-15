#include<iostream>
#include<vector>
#include<string>
#include<functional> // reference_wrapper

using namespace std;

struct nombre_completo{

    string nombre;
    string apellido;
};

template<typename T, typename PRED>
auto get_if(const T& c, PRED func){

    vector<reference_wrapper <const typename T::value_type>> r;
    for(auto& e : c)
    {
        if(func(e)) r.push_back(ref(e)); // explicitar 'ref' por que a veces se lo pasa como copia
    }

    return r;
}

int main(){

    vector<nombre_completo> nombres;
    nombres.push_back({"Juan", "Perez"});
    nombres.push_back({"Ariel", "Perez"});
    nombres.push_back({"Jorge", "Lopez"});
    nombres.push_back({"Rojas", "Rojas"});
    nombres.push_back({"Daniela", "Marcia"});

    auto f = get_if(
        nombres,
        [](auto& n){return n.apellido == "Perez";}
    );

    for(auto & e : f){

        cout << e.get().nombre << "\t" << e.get().apellido << "\n";
    }
}