#include "person.h"
#include "bst.h"
#include <stdlib.h>

int cmp_int(const void *a, const void *b)
{
    return 0;
}
void release_int(void *b)
{
    free(b);
}

int* create_int(int n)
{
    int* new_n = (int*)malloc(sizeof(int));
    *new_n = n;
    return new_n;
}



int main()
{
    bst b;
    bst_init(&b, cmp_int, release_int, release_person);

    bst_add(&b, create_int(58483475), create_person("juan", "perez", 1923));
    bst_add(&b, create_int(58576344), create_person("jose", "lopez", 1980));
    bst_add(&b, create_int(67913378), create_person("miguel", "cervantes", 1642));
    bst_add(&b, create_int(34854455), create_person("louis", "pasteur", 1755));
    bst_add(&b, create_int(65464521), create_person("isaac", "newton", 1623));
    bst_add(&b, create_int(12390484), create_person("albert", "einstein", 1889));
    bst_add(&b, create_int(78685894), create_person("stephen", "hawkings", 1953));
    bst_add(&b, create_int(97875567), create_person("peter", "gabriel", 1952));
    show_person(b.root->value);
    /*
    int p = 97875567;
    void* peter = bst_find(&b, &p);
    show_person((person*) peter);

    puts("******");

    bst_iterate(&b, show_int, show_person);
    bst_release(&b); */
}