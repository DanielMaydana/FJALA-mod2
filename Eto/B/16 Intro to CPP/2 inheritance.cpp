#include <string>
using namespace std;

class person
{
    string name;
    size_t id;

  public:
    person(const string &name, size_t id) : name{name}, id{id}
    {
    }

    ~person()
    {
        puts("bye");
    }

    void print() const
    {
        printf("(%lu) is %s", id, name.c_str());
    }
};

class student : public person
{
    size_t score;

  public:
    student(const string &name, size_t id, size_t score) : person{name, id}, score{score}
    {
    }
    ~student()
    {
        puts("bye student");
    }
};

// -------------------------------------------------

int main()
{
    person p{"Eli", 43511222};
    p.print();
    puts("");

    student s{"Nick", 5254245, 100};
    s.print();
    puts("");
}