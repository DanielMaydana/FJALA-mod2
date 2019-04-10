// LINKED LIST
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// node
typedef struct decl_sllitem // struct DECLaration
{
    int value;
    struct decl_sllitem* next;
}sll_node; // alias

// list
typedef struct
{
    sll_node* first;
    sll_node* last;
}sll;

void sll_init(sll* p)
{
    p->first = p->last = NULL;
}

void sll_add(sll* p, int n)
{
    sll_node* new_node = (sll_node*)malloc(sizeof(sll_node)); // create new node
    
    new_node->value = n;
    new_node->next = NULL;

    if(p->first == NULL) p->first = p->last = new_node;
    else
    {
        p->last->next = new_node;
        p->last = new_node;
    }
}

void sll_print(const sll* p)
{
    sll_node* aux = p->first;

    while(aux)
    {
        printf("%d\n", aux->value);
        aux = aux->next;
    }    
}

void sll_release(sll* p)
{
    sll_node* aux = p->first;
    
    while(aux)
    {
        sll_node* next = aux->next;
        printf("%p\n", next);
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
    // sll_add(&x, 24);
    sll_print(&x);
    sll_release(&x);

    puts("Oll Korrekt");
}