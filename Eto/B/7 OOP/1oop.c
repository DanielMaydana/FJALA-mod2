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

// --------------------------------------------------

typedef struct
{
    char* marca;
    char* modelo;
    size_t anio;

}Carro;

char* clone_str(const char* s)
{
    size_t len = strlen(s);
    char* cc = (char*)malloc(len + 1);
    memcpy(cc, s, len + 1);
    return cc;
}

void carro_init(Carro* d, const char* marca, const char* modelo, size_t anio)
{
    d->anio = anio;
    d->marca = clone_str(marca);
    d->modelo = clone_str(modelo);
}

void carro_print(const Carro* z)
{
    puts(z->marca);
    puts(z->modelo);
    printf("%lu\n", z->anio);
}

void carro_release(Carro* c)
{
    free(c->marca);
    free(c->modelo);
    c->marca = c->modelo = NULL;
    c->anio = 0;
}

// --------------------------------------------------

int main()
{
    // struct Person p;
    // init(&p, "Omar", "Vera", 1978); // created in the stack
    // show(&p);

    // ----------------------------------------------

    // struct Person* p1 = (struct Person*)malloc(sizeof(struct Person)); // created in the heap
    // init(p1, "Dan", "Boom", 1874);
    // show(p1); // q is already a mem direction, no need for &
    // free(p1); // use always if malloc was previously used

    // ----------------------------------------------

    // struct Person f;
    // init(&f, "Alan", "Wake", 1995);

    // puts((const char*)&f); // shows the first field of 'f'
    // puts(((const char*)&f) + 32); // shows the second field of 'f'

    // ----------------------------------------------

    // Carro c;
    // carro_init(&c, "VW", "Pets", 1967);
    // carro_release(&c);

    // ----------------------------------------------

    Carro* cs = (Carro*)malloc(3*sizeof(Carro)); // Carro created in the heap
    carro_init(cs, "VW", "Peta", 1966); // first Carro
    carro_init(cs + 1, "Lamb", "Dice", 1923); // second Carro
    carro_init(&cs[2], "Computer", "Stones", 1955); // third Carro

    for(Carro* i = cs; i != cs + 3; i++)
    {
        carro_print(i);
    }

    for(Carro* i = cs; i != cs + 3; i++)
    {
        carro_release(i);
    }

    puts("\nAlles gut");
}