#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct{
    void** elems;
    size_t n;

}ptrarraylist;

void ptr_init(ptrarraylist* p){

    p->elems = (void**)malloc(0);
    p->n = 0;
}

void ptr_add(ptrarraylist* p, void* e)
{
    p->elems = (void**)realloc(p->elems, (p->n + 1)*sizeof(void*));
    p->elems[p->n++] = e;
    // p->n++; 
}

int main()
{
    ptrarraylist f;
    int n1st = 11;
    int n2nd = 18;
    int n3rd = 31;

    ptr_init(&f);
    ptr_add(&f, &n1st);
    ptr_add(&f, &n2nd);
    // ptr_add(&f, &n3rd);

    printf("%d\n", f.n);

    // for(size_t i = 0; i < f.n; i++)
    // {
    //     // printf("%d\n", (int*)f.elems[i]);
    // }

    // // for(size_t i = 0; i < f.n; i++)
    // // {
    // //     printf("%d\n", ((int*)f.elems[i]));
    // // }
    puts("Alles gut");

    // -----------------------------------

}