#include <iostream>
#include <cstring>
#include <stdio.h>
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

int main()
{
    Student p{33, "Josh Homme"};
    p.print();

    auto q = p; // COPY
    q.print();

    Student r{666, "Romulo Rojas"};
    r = q; // ASSIGN
    r.print();
}