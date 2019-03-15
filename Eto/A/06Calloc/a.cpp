// string array list

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct StringArrayList
{
    char** items;
    size_t n;
};
using SAL = StringArrayList; // StringArrayList debe existir antes de esta declaracion

void init(SAL* s)
{
    s->items = (char**)malloc(0);  // malloc reserva un espacio de memoria con un numero de bits de memoria, maloc devuelve void* por eso casteamos 
    s->n = 0;
}

char* clone(const char* s)
{
    auto len = strlen(s);
    auto cs = new char[len + 1];
    memcpy(cs, s, len+1);
    return cs;
}

void add(SAL* ss, const char* s)
{
    // ss->items[ss->n] = clone(s);  //esta mal porque agrega elemento en un espacio de memoria 0
    // ss->n++;

    ss->items = (char**) realloc(ss->items, (ss->n+1)* sizeof(char*)); //realloc recibe el vector y el tamano en bits, 
                                                                       // realloc devuelve el puntero a la direccion de memoria 
                                                                       // sizeof de vuelve los bits de variables o tipos de datos
    ss->items[ss->n] = clone(s);
    ss->n++; 
}
void print(const SAL* s)
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
        delete [] s->items[i];
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
