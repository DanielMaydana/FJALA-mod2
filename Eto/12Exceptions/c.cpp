// en niguna parte se hace un throw, como podria agarrar una excepcion???

#include <iostream>
using namespace std;

struct Animal
{
    virtual void hablar() const = 0;
    virtual ~Animal(){}
};

struct Perro : Animal
{
    void hablar() const override
    {
            cout << "guau\n";
    }
};

Animal* getAnimal()
{
    return new Perro{};
}

void p()
{
    cout << "hello\n";
}

struct Wrapper
{
    Animal* a;
    Wrapper(Animal* a)
    :a{a}
    {}
    
    ~Wrapper(){delete a;}
};


int main()
{
    try
    {
        Wrapper w{getAnimal()};
        w.a->hablar();
    }
    catch(...)
    {
        cerr << "error\n"; 
    }

}