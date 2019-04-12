#include "person.h"
#include "bst.h"
#include <stdlib.h>
#include <string.h>

// ------------COMPARATOR------------

int cmp_int(const void *a, const void *b)
{
    return *((int*) b) - *((int*) a);
}

int cmp_string(const void *a, const void *b)
{
    return strcmp (((char*) a) , ((char*) b));
}

// ------------REALEASE------------

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

char* create_string(const char* str)
{
    size_t len = strlen(str) +1;
    char* new_str = (char*)malloc(len);    
    memcpy(new_str,str,len);
    return new_str;
}

void show_int(const void* b)
{
    printf("%d\n", *((int*)b));
}

//-------------------------MAIN-------------------------

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
    
    int p = 348234455;
    void* peter = bst_find(&b, &p);
    show_person((person*) peter);

    puts("***********");

    bst_iterate(&b, show_int, show_person);
    bst_release(&b);

    // ----------------------------------

    // bst b_str;
    // bst_init(&b_str, cmp_string, free, free);

    // bst_add(&b_str, create_string("boys"), create_string("muchachos"));
    // bst_add(&b_str, create_string("kits"), create_string("nose"));
    // bst_add(&b_str, create_string("black"), create_string("negro"));
    // void* kit = bst_find(&b_str,"bys");
}