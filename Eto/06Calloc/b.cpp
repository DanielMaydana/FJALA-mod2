#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio> 
using namespace std;

struct StringBuilder
{
    char** items;
    size_t n;
};

void init(StringBuilder* sb)
{
    sb->items = (char**)malloc(0);
    sb->n = 0;
}

char* clone(const char* s)
{
    size_t len = strlen(s)+1;
    char* copy = new char[len];
    memcpy(copy, s, len);
    return copy;
}

void add(StringBuilder* sb, const char* s)
{
    sb->items = (char**) realloc(sb->items, ((sb->n + 1) * sizeof(char*)));
    sb->items[sb->n] = clone(s);
    sb->n++;
}

void add(StringBuilder* sb, int n)
{
    char aux[10];
    sprintf(aux, "%d", n);
    sb->items = (char**) realloc(sb->items, ((sb->n + 1) * sizeof(char*)));
    sb->items[sb->n] = clone(aux);
    sb->n++;
}

void add_line(StringBuilder* sb, const char* s)
{
    char aux[20];
    strcpy (aux, s);
    strcat(aux, "\n");
    sb->items = (char**) realloc(sb->items, ((sb->n + 1) * sizeof(char*)));
    sb->items[sb->n] = clone(aux);
    sb->n++;
}

size_t get_length (const StringBuilder* sb)
{
    return sb->n;
}

void print(StringBuilder* s)
{
    for(size_t i = 0; i < s->n; i++)
    {
        cout << s->items[i] << "\n";
    }
}

const char* get_string(const StringBuilder* sb)
{
    char aux[300];
    for(size_t i = 0; i < sb->n; i++)
    {
        strcat(aux, sb->items[i]);
    }
    return clone(aux);
    // return aux;
}

void release(StringBuilder* sb)
{
    for(size_t i = 0; i < sb->n; i++)
    {
        delete [] sb->items[i];
    }
    free(sb->items);
}

int main()
{
    StringBuilder sb;
    init(&sb);
    add(&sb, "one");
    add(&sb, "two");
    add(&sb, "tree");
    print(&sb);
    cout << get_length(&sb) << " Elemets in List\n";
    add(&sb, 4);
    add(&sb, 5);
    add(&sb, 6);
    print(&sb);
    cout << get_length(&sb) << " Elemets in List\n";
    add_line(&sb, "seven");
    add_line(&sb, "eigth");
    add(&sb, "nine");
    add(&sb, "ten");
    print(&sb);
    cout << get_length(&sb) << " Elemets in List\n";   
    const char* gs = get_string(&sb);
    cout << gs << "\n"; 
    delete gs;
}