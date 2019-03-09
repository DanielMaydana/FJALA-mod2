#include <iostream>
using namespace std;

enum class Languaje
{
    SPANISH = 1,
    ENGLISH = 2
};


struct Greeter  //ABC Abstract Base Class
{
    virtual const char* hi() const = 0;
    virtual const char* bye() const = 0;
    virtual ~Greeter(){}
};


struct SpanishGreeter : Greeter
{
    const char* hi() const override
    {
        return "Buenos Dias";
    }

    const char* bye() const override
    {
        return "Hasta Luego";
    }
};

struct EnglishGreeter : Greeter
{
    const char* hi() const override
    {
        return "Good morning";
    }

    const char* bye() const override
    {
        return "Talk to you later";
    }
};


struct GreeterFactory
{
    
    static Greeter* create(Languaje x)
    {
        
        switch (x)
        {
            case Languaje::SPANISH : 
                return new SpanishGreeter();
                // break;
        
            case Languaje::ENGLISH :
                return new EnglishGreeter();
            // default:
                // break;
        }
            return nullptr;
    }
};


int main()
{
    cout << "ingrese 1 Espanol  2 Ingles\n";
    int n;
    cin >> n;
    Languaje Ing = (Languaje) n;
    Greeter* g = GreeterFactory::create(Ing); //create es un metodo estatico
    cout << g->hi() << "\n";
    cout << g->bye() << "\n";
    delete g;  // la documentacion de la libreria deberia avisar como se eliminan los objetos
}