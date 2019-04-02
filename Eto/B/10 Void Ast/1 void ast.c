#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Void *
// Not possible to use ptr arithmetic
// It's a ptr to whatever
typedef struct{
    void** elems;
    size_t n;

}ptrarraylist;

void ptr_init(ptrarraylist* p){
    p->elems = (void**)malloc(0);
    p->n = 0;
}

void ptr_add(ptrarraylist* p, void* e){
    p->elems = (void**)realloc(p->elems, (p->n+1)*sizeof(void*));
    p->elems[p->n+1] = e;
    p->n++;
}

void ptr_release(ptrarraylist* p){
    free(p->elems);
    p->elems = NULL;
    p->n = 0;
}

int main()
{
    ptrarraylist p;
    int n1 = 11; int n2 = 18; int n3 = 31;

    ptr_init(&p);
    ptr_add(&p, &n2);
    ptr_add(&p, &n1);
    ptr_add(&p, &n3);

    size_t n = p.n;
    for(size_t i = 0; i < n; i++)
    {
        printf("%d\n", (int*)p.elems[i]);
    }
    puts("Alles gut");

    // -----------------------------------

    // ptrarraylist q;
    // ptr_init(&q);
    // ptr_add(&q, "hello");
    // ptr_add(&q, "whatever");

    // for(size_t i = 0; i < q.n; i++)
    // {
    //     puts((char*)q.elems[i]);
    // }

    // -----------------------------------

    ptr_release(&p);
}