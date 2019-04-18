#include <stdio.h>
#include <stdlib.h>
#define CREATE_ILL(NAME, TYPE)\
\
struct NAME##_item\
{\
	TYPE val;\
	struct NAME##_item* next;\
} ;\
\
typedef struct\
{\
	struct NAME##_item* first;\
	struct NAME##_item* last;\
} NAME;\
\
void NAME##_init(NAME* e)\
{\
	e->first = e->last = NULL;\
}\
\
void NAME##_add(NAME* x, TYPE e)\
{\
	struct NAME##_item* ne = (struct NAME##_item*)malloc(sizeof(struct NAME##_item));\
	ne->val = e;\
	ne->next = NULL;\
	if (x->first == NULL)\
	{\
		x->first = x->last = ne;\
		return;\
	}\
	x->last->next= ne;\
	x->last = ne;\
}\
\
void NAME##_iterate(NAME* p, void (*proc)(TYPE))\
{\
	for (struct NAME##_item* aux= p->first ; aux ; aux = aux->next)\
	{\
		proc(aux->val);\
	}\
}\
\
void NAME##_release(NAME* p)\
{\
	struct NAME##_item* aux = p->first;\
	while(aux)\
	{\
		struct NAME##_item* next = aux->next;\
		free(aux);\
		aux = next;\
	}\
}\

void print_int(int a)
{
	printf("%d\n", a);
}

void print_double(double x)
{
	printf("%f\n", x);
}

void print_str(const char* s)
{
	puts(s);
}

// CREATE_ILL(ILL, const char*)
CREATE_ILL(DLL, double)
CREATE_ILL(PLL, const char*)

int main()
{
	PLL p;
	PLL_init(&p);
	PLL_add(&p, "hola");
	PLL_add(&p, "mundo");
	// ILX_add(&p, 6.5);
	// ILX_add(&p, 1.8);
	// ill_iterate(&p, print_int);
	PLL_iterate(&p, print_str);
	PLL_release(&p);
	
	DLL d;
	DLL_init(&d);
	DLL_add(&d, 6.5);
	DLL_add(&d, 1.8);
	DLL_iterate(&d, print_double);
	DLL_release(&d);

}
