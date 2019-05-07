#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

class Student
{
    size_t id;
    char *name;

public:
    ~Student()
    {
        printf("Bye %s student\n", this->name);
        free(name);
    }

    Student(size_t id, const char *name) : id{id} // reg constructor
    {
        auto len = strlen(name);
        this->name = (char *)malloc(len + 1);
        memcpy(this->name, name, len + 1);

        printf("Regular constructor %s\n", name);
    }

    Student(const Student &src) : id{src.id} // copy constructor
    {
        auto len = strlen(src.name);
        this->name = (char *)malloc(len + 1);
        memcpy(this->name, src.name, len + 1);

        printf("Copy constructor %s\n", name);
    }

    Student &operator=(const Student &src)
    {
        if (this == &src)
            return *this;
        this->~Student();
        this->id = src.id;
        auto len = strlen(src.name);
        this->name = (char *)malloc(len + 1);
        memcpy(this->name, src.name, len + 1);

        printf("Asign operator %s\n", name);

        return *this;
    }

    void print()
    {
        printf("(%d) %s\n", id, name);
    }
};

class TeamsOfTwo
{
    Student first;
    Student second;

public:
    TeamsOfTwo(const Student &first, const Student &second)
        : first{first}, second{second}
    {
    }
};

int main()
{
    Student c{78, "David Gilmour"};

    TeamsOfTwo team1{c, Student{80, "Roger Waters"}};
}