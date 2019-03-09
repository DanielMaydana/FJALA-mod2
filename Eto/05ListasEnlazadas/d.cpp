#include <iostream>
#include <cstring>
using namespace std;

struct SLLItem
{
    char* value;
    SLLItem* next;

    SLLItem(const char* p_value)
    :next{nullptr}
    {
    size_t size = strlen(p_value)+1;
    value = new char[size];
    memcpy(value, p_value, size);
    }
};

struct SLL
{
    SLLItem* first;
    SLLItem* last;
};

void init(SLL* s)
{
    s->first= nullptr;
    s->last = nullptr;
}

void add_tail(SLL* s, const char* text)
 {
    // size_t size = strlen(text)+1;
    // char* new_text = new char[size];
    // memcpy(new_text, text, size);
    SLLItem* new_item = new SLLItem{text};
    if(s->first)
    {
        s->last->next = new_item;
        s->last = new_item;
        return;
    }
    else
    {
        s->first = s->last = new_item;
    }
 }

void add_head(SLL* s, const char* text)
{
    // size_t size = strlen(text)+1;
    // char* new_text = new char[size];
    // memcpy(new_text, text, size);
    SLLItem* new_item = new SLLItem{text};
    if(s->first)
    {
        new_item->next = s->first;
        s->first = new_item;
        return;
    }
    else
    {
        s->first = s->last = new_item;
    }
}

void print(const SLL* x)
{
    auto aux = x->first;
    while(aux)
    {
        cout << aux->value << "\n";
        aux = aux->next;
    }
}

void relese(SLL* x)
{
    auto aux = x->first;
    while(aux)
    {
        auto next = aux->next;
        delete[] aux->value;
        delete aux;
        aux = next;
    }
}

int main()
{
    SLL s;
    init(&s);
    add_tail(&s,"hello");
    add_head(&s, "world");
    add_tail(&s,"today");
    add_head(&s, "is");
    add_head(&s, "thursday");
    relese(&s);
    print(&s);
}