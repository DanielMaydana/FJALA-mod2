// exception 
    // bad_alloc  cuando no es posible asignar memoria con new
    // bad_cast  cuando no se puede castear 
    // out_of_range cuando se quiere acceder a un valor mas alla del tamanho 

#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;


class Ex : public exception
{
private:
    int errorcode;
    char msg[100];

public:
    Ex(int ec)
    :errorcode{ec}
    { 
        strcpy(msg, "Error ");
        char aux[10];
        sprintf(aux, "%d", errorcode);
        strcat(msg, aux);
    }
    
    ~Ex() { }

    // siempre sobrescribir este metodo, nonexcept dice que no va botar excepciones en este metodo
    const char* what() const noexcept override
    {
        return msg;
    }
};

int main()
{
    
    try
    {
        throw Ex{58};
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
}