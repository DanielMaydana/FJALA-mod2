#include <stdio.h>
#define principal main
#define EMPEZAR {
#define TERMINAR }
#define fin ;
#define entero int
#define iguala =
#define sumar(a,b) (a+b)
#define imprimir(j) printf("%d\n",j)

entero principal()
EMPEZAR
	entero h iguala 16 fin
	entero i iguala 20 fin
	entero j iguala sumar(h,i) fin
	imprimir(j) fin
TERMINAR
