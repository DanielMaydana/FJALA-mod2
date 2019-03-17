#include <iostream>
#include <vector>
#include "file_lists.h"
using namespace std;

class person
{
private:
    string m_name;
    int m_id;

public:
    person(const string& name, const int& id) : m_name{name}, m_id{id}
    { }
    ~person() { }
};

int main()
{
    file_lists<person> p { "people"};

    auto list = p.get_new_list();
    // p.push_back(list, person { "adela", "zamudio", 1992 });
    // p.push_back(list, person { "armando", "chirveches", 1923 });

    // auto list2 = p.get_new_list();
    // list2.push_back(person { "peter", "gabriel", 2002 });
    // list2.push_back(person { "phil", "collings", 1938 });

    // auto list3 = p.get_list(list2);
    // list3.push_back(person { "kylie", "minogue", 1954 });

    // list1.iterate([](const person& x)
    // {
    //     cout << x << endl;
    // });

    // list2.iterate([](const person& x)
    // {
    //     cout << x << endl;
    // });
}