#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// typedef union{

//     char str[32];
//     int num;
//     double dbl;
// }item;

// -------------------------------

// typedef enum{
//     ALTA = 10,
//     MEDIA = 36,
//     BAJA = 99
// }prioridad;

// typedef enum{
//     BAJA, MEDIA, ALTA
// }estatura;

// -------------------------------

typedef enum{
    LL_STR,
    LL_INT
}ll_type;

typedef struct{
    ll_type type;

    union{
        char* str;
        int num;
    }item;

}value;

typedef struct pitem{
    value val;
    struct pitem* next;
}item;

typedef struct{
    item* first;
    item* last;
}ll;

void ll_init(ll* x)
{
    x->first = x->last = NULL;
}

void ll_add(ll* x, item* p)
{
    if(x->first == NULL)
    {
        x->first = x->last = p;
        return;
    }
    x->last->next = p;
    x->last = p;
}

void ll_print(const ll* p)
{
    item* aux = p->first;

    while(aux)
    {
        switch(aux->val.type)
        {
            case LL_INT:
                printf("%d\n", aux->val.item.num);
                break;
            case LL_STR:
                puts(aux->val.item.str);
                break;
        }
        aux = aux -> next;
    }
}

void ll_release(ll* p)
{
    item* aux = p->first;

    while(aux)
    {
        item* next = aux->next;
        if(aux->val.type == LL_STR) free(aux->val.item.str);
        free(aux);
        aux = aux->next;
    }
}

// void ll_release(ll* b)
// {
//     item* aux = b->first;
//     while(aux)
//     {
//         item* next = aux->next;
//         if(aux->val.type == LL_STR)
//         {
//             free(aux->val.item.str);
//         }
//         free(aux);
//         aux = next;
//     }
// }

void ll_add_int(ll* x, int n)
{
    item* ni = (item*)malloc(sizeof(item));
    ni->next = NULL;
    ni->val.type = LL_INT;
    ni->val.item.num = n;

    ll_add(x, ni);
}

void ll_add_str(ll* x, const char* s)
{
    item* ni = (item*)malloc(sizeof(item));
    ni->next = NULL;
    ni->val.type = LL_STR;
    size_t len = strlen(s);
    char* aux = (char*)malloc(len + 1);
    memcpy(aux, s, len + 1);
    ni->val.item.str = aux;

    ll_add(x, ni);
}

int main()
{
    // item x;
    // strcpy(x.str, "hallo");
    // puts(x.str);

    // x.num = 0x00616263;

    // printf("%d\n", x.num);
    // puts(x.str);

    // -------------------------------

    // prioridad p;

    // p = MEDIA;
    // printf("%d\n", p);

    // if(p == MEDIA)
    // {
    //     puts("Equal");
    // }

    // -------------------------------

    ll z;
    ll_init(&z);
    ll_add_int(&z, 9);
    ll_add_int(&z, 333);
    ll_add_str(&z, "Specter");
    ll_add_str(&z, "Baby81");

    ll_print(&z);
    ll_release(&z);

    puts("\nAlles gut");
}