#include <stdio.h>

typedef struct
{
    char* first_name;
    char* last_name;
    size_t year;
} person;



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
    
    int p = 97875567;
    void* peter = bst_find(&b, &p);
    show_person((person*) peter);

    puts("******");

    bst_iterate(&b, show_int, show_person);
    bst_release(&b);


}