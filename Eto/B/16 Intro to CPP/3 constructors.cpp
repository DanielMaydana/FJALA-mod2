#include <cstdio>
#include <cstring>
#include <cstdlib>

class Student
{
    size_t id;
    char *name;

  public:
    Student(size_t id, const char *name)
        : id{id}
    {
        auto len = strlen(name);
        this->name = (char *)malloc(len + 1);
        memcpy(this->name, name, len + 1);
    }

    void print() const
    {
        printf("(%lu) %s\n", id, name);
    }

    ~Student()
    {
        printf("chau %s\n", name);
        free(name);
    }

    //constructor de copia
    Student(const Student &src)
        : id{src.id}
    {
        auto len = strlen(src.name);
        name = (char *)malloc(len + 1);
        memcpy(name, src.name, len + 1);
    }

    Student &operator=(const Student &src)
    {
        if (this == &src)
            return *this; // en caso de ser iguales r=r
        this->~Student(); // dentro de la clase se puede llamasr asi no fuera
        id = src.id;
        //luego hacemos lo mismo
        auto len = strlen(src.name);
        name = (char *)malloc(len + 1);
        memcpy(name, src.name, len + 1);
        return *this;
    }
};
class grupos_a_2
{
    Student a;
    Student b;

  public:
    grupos_a_2(const Student &a, const Student &b)
        : a{a}, b{b}
    {
    }
    void print() const
    {
        puts("Integrates:");
        printf("-");
        a.print();
        printf("-");
        b.print();
    }
};

int main()
{
    Student x{4, "favio salinas"};
    grupos_a_2 g{x, Student{6, "maria mercedes"}};
    g.print();
}