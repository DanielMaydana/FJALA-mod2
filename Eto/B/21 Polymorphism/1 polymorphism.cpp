#include <iostream> 
#include <string>
using namespace std;


//Polimorfismo
//Virtual es optimo pero cuesta

    /* class person
    {
    private:
        string name;
        size_t id;
    public:
        person(const string &name, size_t id): name{name}, id{id}{

        }

        virtual void print()const{
            printf("(%lu) %s ", id, name.data());
        // printf("(%lu) %s", id, name.c_str());
        }

        virtual ~person(){
            puts("\n Bye person");
        }
    }; */

    /* class student : public person
    {
    private:
        size_t score;
    public:
        student(const string &name, size_t id, size_t score):person{name, id},score{score}
        {
        };

        virtual void print()const override{ //Para sobre escribir es mejor y eficiente
            person::print();
            printf("Score %lu ", score);
        }

        ~student(){
            puts("\n Bye Student");
        }
    };  */


//----------------------------------------------------------------//

struct Animal
{
    virtual ~Animal(){}

    virtual void comunicarse()const=0; //Es metedo abstracto o METODOS VIRTUALES PUROS(en c++)
/*     virtual void comunicarse()const{
        puts("HOla");
    } */

    virtual void get_altura()const{
        puts("Altura");
    }
};


struct Perro:Animal 
{
    void comunicarse()const override{
        puts("Guaw ");
    } 

    void get_altura()const override{
        puts("Bajo");
    }
};

struct Vaca:Animal 
{
    void comunicarse()const override{
        puts("muu");
    }
};

struct Felino:Animal 
{
    protected:
        Felino(){}
};

struct Gato:Felino 
{

};

void hacerAlgo(const Animal &a){
   a.comunicarse(); 
   a.get_altura();
}





int main()
{   
/*     person p{"Juann perez", 98898};
    p.print();
    puts(" ");

    student s{"Pedro rojas", 223, 97};
    s.print();

    person *c= new student("Omar", 456,70);
    c->print();
    delete(c);


    student *s= new student("Pedro rojas", 223, 97);
    s->print();
    delete s;

    puts("*****");
    person *e= new student("pepito", 23,2222);

    e->print();
    //((student *)e)->print(); // Esta casteando
    delete e;
*/

    //auto p1= new Perro{};

    Perro p;
    Vaca v;
    
    hacerAlgo(p);
    hacerAlgo(v);

    
    return 0;
}