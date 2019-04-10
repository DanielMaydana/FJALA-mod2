#include "person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



person* create_person(const char* first_n,const char* last_n, size_t year)
{
    size_t name_len = strlen(first_n);
    size_t last_len = strlen(last_n);

    person* per = (person*)malloc((sizeof(person) + name_len + last_len + 2));

    char* fn = (char*)(per + 1);
    char* ln = fn + name_len + 1;

    memcpy(fn, first_n, name_len+1);
    memcpy(ln, last_n, last_len+1);

    per->first_name = fn;
    per->last_name = ln;
    per->year = year;

    return per;


}
void release_person(void* p)
{
    free(p);
}
void show_person(const void* p)
{
    if (p==NULL) {
        puts("no existe");
        return;
    }
    person* per=(person*)p;
    printf("%s, %s (%lu)\n",per->first_name, per->last_name, per->year);
}