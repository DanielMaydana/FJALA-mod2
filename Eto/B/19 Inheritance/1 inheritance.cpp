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
        puts("bye Person");
    }

    void print() const
    {
        printf("(%lu) is %s", id, name.c_str());
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
        puts("bye Student");
    }

    void print() // HIDING
    {
        Person::print();
        printf(" with a score of %lu", score);
    }
};

// -------------------------------------------------

int main()
{
    // Person p{"Eli", 43511222};
    // p.print();
    // puts("");

    // Student s{"Nick", 5254245, 100};
    // s.print();
    // puts("");

    Person *e = new Student{"Mordecai", 42442, 78};
    e->print();
}