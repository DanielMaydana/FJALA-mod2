#include <iostream>
#include <string>
#include <vector>
using namespace std;


class A
{
private:
    string p;
public:
    A(const string& s) : p{s}
    { }
    
    A(A&& src) : p{move(src.p)} // constructor movida que recibe un Rvalue reference
    {
        cout << "move1\n";
    }

    A(string&& s) : p(move(s))
    {
        cout << "move2\n";
    }

    ~A() { }

    const string& get() const
    {
        return p;
    }
};

vector<int> get_list()
{
    vector<int> z;
    for(int i = 0; i < 1000000; i++)
    {
        z.push_back(i * 10);
    }
    return z;
}

int main()
{
    A m{"hello"}; // esta es una cadena tempporal y desaparecera despues de crear el objeto A, el compilador decide hacer una movida
    string n = "2019"; // porque la variable n podria ser usada despues el compilador hace una copia
    // A q{n};
    A q{move(n)}; // si estamos seguros que n no se utilizara otra vez podemos llamar a la movida
    cout << m.get() << "\n";
    cout << q.get() << "\n";

    vector<int> r;
    r = get_list();
}