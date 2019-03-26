#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[32];
    char lastname[32];
    size_t birthYear;
};

typedef struct
{
    char marca[32];
    char model[32];
    size_t year;
} Car;

void init(struct Person* h, const char* n, const char* ln, size_t y)
{
    strcpy(h->name, n);
    strcpy(h->lastname, ln);
    h->birthYear = y; // Not needed with primitives
}

void show(struct Person* s)
{
    puts(s->name);
    puts(s->lastname);
    printf("%lu", s->birthYear);
}

int main()
{
    // struct Person p;
    // init(&p, "Omar", "Vera", 1978); // created in the stack
    // show(&p);

    // -----------------------

    // struct Person* p1 = (struct Person*)malloc(sizeof(struct Person)); // created in the heap
    // init(p1, "Dan", "Boom", 1874);
    // show(p1); // q is already a mem direction, no need for &
    // free(p1); // use always if malloc was previously used

    // -----------------------

    struct Person f;
    init(&f, "Alan", "Wake", 1995);

    puts((const char*)&f); // shows the first field of 'f'
    puts(((const char*)&f) + 32); // shows the second field of 'f'

    puts("\nAlles gut");
}