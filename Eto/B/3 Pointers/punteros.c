#include <stdio.h> 

int main() 
{
    // int myActualInt = 15;
    // int* p = (int*)0xDEADBEEF;

    // printf("%p\n", p); // p nos devuelve la direccion de memoria
    // printf("%d\n", *p); // *p nos devuelve el contenido de esa direccion de mem (en este caso se tira)

    //-----------------------

    // int* null1 = NULL; 
    // int* null2 = NULL; 

    // if(null1 == NULL && null2 == NULL)
    // {
    //     printf("%s\n", "BRMC");
    // }

    //-----------------------

    int num1 = 58;
    int* ptr1 = &num1;

    printf("%p\n", ptr1);

    (*ptr1)++;

    printf("%d\n", *ptr1);

}