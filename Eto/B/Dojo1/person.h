#ifndef PERSON_H
#define PERSON_H

typedef struct
{
    char* first_name;
    char* last_name;
    size_t year;
} person;

person* create_person(const char* first_n,const char* last_n, size_t year);
void release_person(void*);
void show_person(const void*);
#endif 
