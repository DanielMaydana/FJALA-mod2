// LINKED LIST
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// node
typedef struct declsllitem // struct DECLaration
{
    int value;
    struct declsllitem* next;
}sllitem; // alias

//list
typedef struct
{
    sllitem* first;
    sllitem* last;
}sll;

void sll_init(sll* p)
{
    p->first = p->last = NULL;
}

void sll_add(sll* p, int n)
{
    sllitem* ni = (sllitem*)malloc(sizeof(sllitem)); // create new node
    ni->value = n;
    ni->next = NULL;
    if(p->first == NULL)
    {
        p->first = p->last = ni;
        return;
    }

    p->last->next = ni;
    p->last = ni;
}

void sll_print(const sll* p)
{
    sllitem* aux = p->first;
    while(aux){
        printf("%d\n", aux->value);
        aux = aux->next;
    }
    
}

void sll_release(sll* p)
{
    sllitem* aux = p->first;
    while(aux){
        sllitem* next = aux->next;
        free(aux);
        aux = next;
    }
}

int main()
{
    sll x;
    sll_init(&x);
    sll_add(&x, 14);
    sll_add(&x, 44);
    sll_add(&x, 24);
    sll_print(&x);
    sll_release(&x);

    puts("Oll Korrekt");
}