#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct{
    void** elems;
    size_t type_size;
    size_t n;

}ptr_arrlist;

void ptr_init(ptr_arrlist* p, size_t size){

    p->elems = (void**)malloc(0);
    p->type_size = size;
    p->n = 0;
}

void ptr_add(ptr_arrlist* p, void* e){

    void* copy_e = malloc(p->type_size); // COPY OF THE ELEMENT
    memcpy(copy_e, e, p->type_size);

    p->elems = (void**)realloc(p->elems, (p->n + 1)*sizeof(void*));
    p->elems[p->n++] = copy_e;
}

void ptr_release(ptr_arrlist* p){
    
    for(int i = 0; i < p->n; i++)
    {
        free(p->elems[i]);
    }
    free(p->elems = NULL);
    p->n = p->type_size = 0;
}

int main()
{
    int n1 = 11; int n2 = 18; int n3 = 31;
    ptr_arrlist f;

    ptr_init(&f, sizeof(int));
    ptr_add(&f, &n2);
    ptr_add(&f, &n1);
    ptr_add(&f, &n3);

    for(size_t i = 0; i < f.n; i++)
    {
        printf("%d\n", *((int*)f.elems[i]));
    }

    // -----------------------------------

    puts("\nAlles gut");
}