#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;

class Person
{
    private:
        char fn[32];
        char ln[32];
        size_t ci;

    public:

        Person() : Person("", "", 0) // the default constructor uses the parameterized constructor with default values
        {
        }

        Person(const char* fn, const char *ln, const size_t ci)
        {
            strcpy(this->fn, fn); // this has ptr syntax but works as a reference 
            strcpy(this->ln, ln);
            this->ci = ci;
        }

        void mostrar() const // a const method can only have calls to other const methods 
        {
            printf("(%lu) %s %s\n", ci, ln, fn);
        }

        void set_fn(const char* fn)
        {
            strcpy(this->fn, fn);
        }

        void set_ln(const char* ln)
        {
            strcpy(this->ln, ln);
        }

        void set_ci(const size_t ci)
        {
            this->ci = ci;
        }

        // const char* get_fn()
        // {

        // }

        // const char* get_ln()
        // {

        // }

};

auto main()->int
{
    Person p; // here we're using the default constructor 
    p.set_fn("John");
    p.set_ln("Theodore");
    p.set_ci(4324333);
    p.mostrar();
    
    // -------------------------------

    Person q{"Leah", "Shapiro", 1933383}; // initialize an object with '{}' always | Most Vexing Parsing Error
    q.mostrar();

    // -------------------------------

    auto w = Person{"Peter", "Hayes", 7864848}; // another way to initialize an object, using 'auto'
    w.mostrar();

    // -------------------------------

    Person *t = new Person{"Robert", "Been", 4314344}; // initialize an object in the heap, using 'new'
    t->mostrar();

    // -------------------------------

    cout << "BRMC";

    return 0;    
}