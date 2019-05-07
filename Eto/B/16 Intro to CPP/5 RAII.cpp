#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

class Student
{
    size_t id;
    char *name;

public:
    // there can be only one destructor and it's always public
    // it's called when the initialization reaches the end of its scope
    // RAII: resource acquisition is initialization
    // when reserving memory by hand, always implement:
    // assign operator, copy constructor and destructor
    ~Student()
    {
        printf("bye Student %s\n", this->name);
        free(name);
    }

    Student(size_t id, const char *name) : id{id}
    {
        auto len = strlen(name);
        this->name = (char *)malloc(len + 1);
        memcpy(this->name, name, len + 1);
    }

    Student(const Student &src) : id{src.id} // COPY constructor
    {
        auto len = strlen(src.name);
        name = (char *)malloc(len + 1);
        memcpy(this->name, src.name, len + 1);
    }

    Student &operator=(const Student &src) // ASSIGN ooperator
    {
        if (this == &src)
            return *this; // if we're talking about the same object
        this->~Student(); // if not, free the actual resources
        this->id = src.id;
        auto len = strlen(src.name);
        this->name = (char *)malloc(len + 1); // also realloc
        memcpy(name, src.name, len + 1);

        // the following allows to have something like: 'first = last = null'
        return *this;
    }

    void print() const
    {
        printf("(%lu) %s\n", id, name);
    }
};

class TeamsOfTwo
{
    Student first;
    Student second;

public:
    // pass here for reference '(a , b)'otherwise it gets destroyed inmediatly,
    // we use the copy constructor ':{}, {}' cause we don't have an empty constructor for Student
    TeamsOfTwo(const Student &a, const Student &b) : first{a}, second{b}
    {
    }

    void print()
    {
        first.print();
        second.print();
    }
};

int main()
{
    Student x{4, "Robert Levon"};
    TeamsOfTwo g{x, Student{6, "Trent Reznor"}};
    g.print();
}