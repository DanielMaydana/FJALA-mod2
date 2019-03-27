// STRING ARRAY LIST
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct strarrlist
{
    char** items;
    size_t n;
};

typedef strarrlist sal;

void sal_init(sal* s)
{
    s->items = (char**)malloc(0); // returns a valid ptr
    s->n = 0;
}

char* clone_str(const char* s)
{
    size_t len = strlen(s);
    char* r = (char*)malloc(len + 1);
    memcpy(r, s, len + 1);
    return r;
}

void sal_add(sal* ss, const char* s)
{
    char* cc = clone_str(s); //returns a char* in the heap
    ss->items = (char**)realloc(ss->items, sizeof(char*)*(ss->n + 1));
    ss->items[ss->n + 1] = cc;
}

void sal_print(const sal* ss)
{
    for(size_t i = 0; i < (ss->n); i++)
    {
        puts(ss->items[i]);
    }
}

void sal_release(sal* ss)
{
    for(size_t i = 0; i < ss->n )
    free(ss->items);
}

int main()
{
    sal x;
    sal_init(&x);
    sal_add(&x, "BRMC");
    sal_add(&x, "QOTSA");
    sal_print(&x);

    puts("Oll Korrekt");
}