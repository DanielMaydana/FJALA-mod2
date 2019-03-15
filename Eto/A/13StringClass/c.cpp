#include <iostream>
#include <string>
#include <string_view> // no es duanha del string, solo lo apunta y no lo construye ni destruye
using namespace std;
using namespace std::string_literals;



class Persona
{
private:
    string p;
public:
    Persona(string_view sv) // evita crear una copia de la cadena, incluye char*, solo copia el puntero
    :p{sv}
    { }

    ~Persona() { }

    void print() const
    {
        cout << p << "\n";
    }
};

int main()
{
    Persona p{"Jorge Lopez"};
    Persona g{"Jose Suarez"s};
    p.print();
    g.print();
}