#include <iostream>
#include <string>
using namespace std;

//Polimorfismo
//Virtual es optimo pero cuesta

class Person
{
private:
    string name;
    size_t id;

public:
    Person(const string &name, size_t id) : name{name}, id{id}
    {
    }

    virtual void print() const
    {
        printf("(%lu) %s ", id, name.data());
        // printf("(%lu) %s", id, name.c_str());
    }

    virtual ~Person()
    {
        puts("\n Bye Person");
    }
};

class Student : public Person
{
private:
    size_t score;

public:
    Student(const string &name, size_t id, size_t score)
        : Person{name, id}, score{score}
    {
    }

    virtual void print() const override
    { //Para sobre escribir es mejor y eficiente
        Person::print();
        printf("Score %lu ", score);
    }

    ~Student()
    {
        puts("\n Bye Student");
    }
};

//----------------------------------------------------------------//

struct Animal
{
    virtual ~Animal() {}

    virtual void comunicarse() const = 0; //Es metedo abstracto o METODOS VIRTUALES PUROS(en c++)
                                          /*     virtual void comunicarse()const{
        puts("HOla");
    } */

    virtual void get_altura() const
    {
        puts("Altura");
    }
};

struct Perro : Animal
{
    void comunicarse() const override
    {
        puts("Guaw ");
    }

    void get_altura() const override
    {
        puts("Bajo");
    }
};

struct Vaca : Animal
{
    void comunicarse() const override
    {
        puts("muu");
    }
};

struct Felino : Animal
{
protected:
    Felino() {}
};

struct Gato : Felino
{
};

void hacerAlgo(const Animal &a)
{
    a.comunicarse();
    a.get_altura();
}

int main()
{
    Person p{"Juann perez", 98898};
    p.print();
    puts(" ");

    Student s{"Pedro rojas", 223, 97};
    s.print();

    Person *c = new Student("Omar", 456, 70);
    c->print();
    delete (c);

    Student *h = new Student("Pedro rojas", 223, 97);
    h->print();
    delete h;

    puts("*****");
    Person *e = new Student("pepito", 23, 2222);
    e->print();
    //((Student *)e)->print(); // Esta casteando
    delete e;

    //auto p1= new Perro{};

    // Perro p;
    // Vaca v;

    // hacerAlgo(p);
    // hacerAlgo(v);

    // return 0;
}