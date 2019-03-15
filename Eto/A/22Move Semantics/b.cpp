// cuando una clase implementa constructor de movida los hijo no necesitan implementarlo

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person
{
private:
    char* name;

public:

    Person(const char* n)
    { 
        cout << "Constructor move\n";
        size_t len = strlen(n);
        name = new char[len + 1];
        memcpy(name, n , len+1);
    }

    Person(const Person& p)
    {
        cout << "Constructor copy\n";
        auto len = strlen(p.name);
        name = new char[len+1];
        memcpy(name, p.name, len+1);
    }

    Person(Person&& src) //constructor de movida
    :name{src.name}
    {
        cout << "Constructor move\n";
        src.name = nullptr;
    }

    ~Person() 
    { 
        delete []name;
    }

    Person& operator = (const Person& incoming_p)
    {
        cout << "Constructor =\n";
        delete []name;
        size_t len = strlen(incoming_p.name);
        name = new char[len + 1];
        memcpy(name, incoming_p.name, len+1);
        return *this;
    }

    void show() const{
        cout << name << "\n";
    }
};

class Couple
{
private:
    Person a;
    Person b;

public:
    template<typename P1, typename P2>
    // Couple(const Person& a, const Person& b) 
    Couple(P1&& a, P2&& b) 
    :a{forward<P1>(a)}, b{forward<P2>(b)} // forward elige hacer copia o movida, la caracteristica se llama Perfect Forwarding
    { }

    Couple(Person&& a, Person&& b)
    :a{move(a)}, b{move(b)}
    {
        cout << "C2\n";
    }

    ~Couple() { }

    void show()const
    {
        cout << "Couple \n";
        a.show();
        b.show();
    }
};

int main()
{
    Person p{"Juan Perez"}; cout << "Pers p\n\n";
    Person w{"Mick Jagger"}; cout << "Pers w\n\n";
    
    char* ch1 = "Juaneto";
    Person x{ch1}; cout << "Pers x\n\n";

    Person q{move(p)};
    // w = q; 

    // p.show();
    q.show();
    w.show();

    // Person r = move(q); // move es una funcion estandar que castear a &&
    // r.show();

    // //q.show(); da crash 

    // Person a1{"Adan"};
    // Person a2{"Eva"};

    // cout << "***********\n";

    // Couple a{a1, a2};
    // a.show();

    // Couple b{Person{"Alvaro"}, Person{"Evo"}};
    // b.show();

    // Couple c {Person{"Carlos"}, a2};
    // c.show();
}