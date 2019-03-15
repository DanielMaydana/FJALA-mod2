#include <iostream>
using namespace std;


class Singleton2
{
private:

    Singleton2() 
    { 
        cout << "Create \n";
    }
    
public:
    ~Singleton2() 
    { 
        cout << "adios\n";
    }

    void hi() const
    {
        cout << "Hoy es jueves\n";
    }

    static Singleton2& instance()
    {
        static Singleton2 s;  // s se crea en una area de memoria global, las proximas ejecusiones no se ejecuta esta linea 
        return s;
    }
};

int main()
{
    Singleton2::instance().hi();
    Singleton2::instance().hi();
    // int* p = new int[200000];
}