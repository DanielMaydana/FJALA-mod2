#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


struct StringArrayList
{
    char** items;
    size_t n;
};
using SAL = StringArrayList;

void init(SAL* s)
{
    s->items = (char**)malloc(0);
    s->n = 0;
}

char* clone(const char* s)
{
    size_t len = strlen(s)+1;
    char* cs = new char[len];
    memcpy(cs, s, len);
    return cs;
}

void add(SAL* ss, const char* s)
{
    ss->items = (char**) realloc(ss->items, (ss->n+1) * sizeof(char*));
    ss->items[ss->n] = clone(s);
    ss->n++;
}

void print(SAL* s)
{
    for(size_t i = 0; i < s->n; i++)
    {
        cout << s->items[i] << "\n";
    }
}

void release(SAL* s)
{
    for(size_t i = 0; i < s->n; i++)
    {
        delete[] s->items[i];
    }
    free(s->items);
}

int main()
{
    SAL ss;
    init(&ss);
    add(&ss, "hello");
    add(&ss, "hello2");
    add(&ss, "hello3");
    print(&ss);
    release(&ss);
}