#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct{
    void** elems;
    size_t n;
    size_t elem_size;

}ptrarraylist2;

void ptr_init2(ptrarraylist2* p, size_t size){
    p->elems = (void**)malloc(0);
    p->n = 0;
    p->elem_size = 0;
}

void ptr_add2(ptrarraylist2* p, void* e){
    void* copy_e = malloc(p->elem_size); // COPY OF THE ELEMENT
    memcpy(copy_e, e, p->elem_size);
    p->elems = (void**)realloc(p->elems, (p->n + 1)*sizeof(void*));
    p->elems[p->n+1] = copy_e;
}

void ptr_release2(ptrarraylist2* p){
    
    for(int i = 0; i < p->n; i++)
    {
        free(p->elems[i]);
    }
    free(p->elems = NULL);
    p->n = p->elem_size = 0;
}

int main()
{
    int n1 = 11; int n2 = 18; int n3 = 31;
    ptrarraylist2 f;

    ptr_init2(&f, sizeof(int));
    ptr_add2(&f, &n2);
    ptr_add2(&f, &n1);
    ptr_add2(&f, &n3);

    // for(size_t i = 0; i < f.n; i++)
    // {
    //     printf("%d\n", *((int*)f.elems[i]));
    // }
    // puts("Alles gut");

    // -----------------------------------

}