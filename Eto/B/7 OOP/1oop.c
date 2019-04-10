#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* brand;
    char* model;
    size_t year;

}Car;

char* clone_str(const char* s)
{
    size_t len = strlen(s);
    char* cc = (char*)malloc(len + 1);
    memcpy(cc, s, len + 1);
    return cc;
}

void carro_init(Car* d, const char* brand, const char* model, size_t year)
{
    d->year = year;
    d->brand = clone_str(brand);
    d->model = clone_str(model);
}

void carro_print(const Car* z)
{
    printf("%s, %s - %lu\n", z->brand, z->model, z->year);
}

void carro_release(Car* c)
{
    free(c->brand);
    free(c->model);
    c->brand = c->model = NULL;
    c->year = 0;
}

// --------------------------------------------------

struct Person 
{
    char name[32];
    char lastn[32];
    size_t year;
    float fx;
};

void init_pers(struct Person* p, const char* n, const char* ln, size_t y)
{
    strcpy(p->name, n);
    strcpy(p->lastn, ln);
    p->year = y;
}

void show_pers(struct Person* p)
{
    printf("%s, %s - %lu\n", p->name, p->lastn, p->year);
}

int main()
{
    // struct Person p;
    // init_pers(&p, "Omar", "Vera", 1978); // created in the stack
    // show_pers(&p);

    // ----------------------------------------------

    // struct Person* p_heap = (Person*)malloc(sizeof(struct Person)); // created in the heap
    // init_pers(p_heap, "Daniel", "Boom", 1874);
    // show_pers(p_heap); // q is already a mem direction, no need for &
    // free(p_heap); // always if malloc was previously used

    // ----------------------------------------------

    struct Person f;
    init_pers(&f, "Alan", "Wake", 1995);

    printf("%d\n", sizeof(Person)); // 32[const char*] + 32[const char*] + 4[size_t] = 68 bytes

    printf("First field: %s\n", (const char*)&f ); // shows the first field of 'f'
    printf("Second field: %s\n", ((const char*)&f) + 32 ); // shows the second field of 'f'
    printf("Third field: %lu\n", *((size_t*)(((char*) &f) + 64)) ); // ASK: why use (((char*) &f) + 64)

    // ----------------------------------------------

    // Car c; // no need for writing 'struct' as we used an alias
    // carro_init(&c, "VW", "Peta", 1967);
    // carro_release(&c);

    // ----------------------------------------------

    // Car* cs = (Car*)malloc(3*sizeof(Car)); // Car created in the heap

    // carro_init(cs, "VW", "Peta", 1966); // first Car
    // carro_init(cs + 1, "Toyota", "Offroad", 1923); // second Car
    // carro_init(&cs[2], "BMW", "FancyCar", 1955); // third Car

    // for(Car* i = cs; i != cs + 3; i++)
    // {
    //     carro_print(i);
    // }

    // for(Car* i = cs; i != cs + 3; i++)
    // {
    //     carro_release(i);
    // }

    // ----------------------------------------------

    puts("\nAlles gut");
}