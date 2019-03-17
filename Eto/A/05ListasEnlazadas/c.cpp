// linked list

#include <iostream>
using namespace std;


struct ILLItem
{
    int value;
    ILLItem* next;
};


struct ILL
{
    ILLItem* first;
    ILLItem* last;
};

void init(ILL* x)
{
    x->first = x->last = nullptr;
}

void add(ILL* x, int n)
{
    auto item = new ILLItem{n, nullptr};
    if(x->first == nullptr)
    {
        x->first = x->last = item;
        return;
    }
    else
    {
        x->last->next = item;
        x->last = item;
    }
}

void print(const ILL* x)
{
    auto aux = x->first;
    while(aux)
    {
        cout << aux->value << "\n";
        aux = aux->next;
    }
}

void relese(ILL* x)
{
    auto aux = x->first;
    while(aux)
    {
        auto next = aux->next;
        delete aux;
        aux = next;
    }
}

int main()
{
    ILL x;
    init (&x);
    add(&x, 85);
    add(&x, 18);
    add(&x, 14);
    add(&x, 6);
    print(&x);
    relese(&x);

    SLL s;
    init(&s);
    add_tail(&s,"hello");
    add_head(&s, "world");
    add_tail(&s,"today");
    add_head(&s, "is");
    add_head(&s, "thursday");
    print(&x);
    relese(&x);

}
