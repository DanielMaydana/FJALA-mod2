#include <string>
using namespace std;

class Person
{
    string name;
    size_t id;

public:
    Person(const string &name, size_t id) : name{name}, id{id}
    {
    }

    ~Person()
    {
        puts("Bye Person");
    }

    void print() const
    {
        printf("(%d) %s", id, name.c_str());
    }
};

class Student : public Person
{
    size_t score;

public:
    Student(const string &name, size_t id, size_t score) : Person{name, id}, score{score}
    {
    }

    ~Student()
    {
        puts("Bye Student");
    }
};

// -------------------------------------------------

int main()
{
    Person p{"Robert", 7233};
    p.print();
    puts("");

    Student s{"Jimmy", 5411, 100};
    s.print();
    puts("");
}