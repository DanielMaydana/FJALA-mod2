#include<iostream>
#include <stdio.h>
using namespace std;

template<class T> // T is unique for this declaration
struct linked_list_node
{
    T elem;
    linked_list_node<T>* next;
};

template<class T>
class linked_list
{
    linked_list_node<T> *first;
    linked_list_node<T> *last;
public:
    linked_list() : first{nullptr}, last{nullptr}
    {}

    void add(const T& x)
    {
        auto nn = new linked_list_node<T>{x, nullptr};

        if(first == nullptr)
        {
            first = last = nn;
            return;
        }
        last->next = nn;
        last = nn;
    }

    void iterate(void (*fun)(const T&))
    {
        auto aux = first;
        while(aux)
        {
            fun(aux->elem);
            aux = aux->next;
        }
    }

    ~linked_list()
    {
        auto aux = first;
        while(aux)
        {
            auto next = aux->next;
            delete aux;
            aux = next;
        }
    }
};

void show_i(const int& e)
{
    printf("%d\n", e);
}

void show_s(const string& e)
{
    puts(e.data());
}

int main()
{
    linked_list<int> x;
    x.add(10);
    x.add(20);
    x.add(50);

    linked_list<string> y;
    y.add("hello ");
    y.add("world ");
    y.add("bye ");

    x.iterate(show_i);
    y.iterate(show_s);
}