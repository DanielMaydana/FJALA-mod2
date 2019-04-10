#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
// malloc
// realloc
// calloc
// 

void print(int* s, size_t n);

int main()
{
    // int* reserved = (int*)malloc(5*sizeof(int));
    // // if it couldn't reserve memory it returns null

    // reserved[0] = 9;
    // reserved[1] = 333;
    // reserved[2] = 81;
    // reserved[3] = 888;
    // reserved[4] = 343;

    // print(reserved, 5);

    // free(reserved); // just for memory reserved with malloc
    // reserved = null;

    // ---------------------

    // for (int i = 0; i < 100000000; i++)
    // {
    //     char* r = (char*)malloc(100);
    //     free(r); // it runs slower each cycle if free() isn't used
    //     if (i%1000000 == 0) printf("%d:\n", i/1000000);
    // }

    // ---------------------

    const char* h = "Miles";
    const char* hh = " Smiles";
    
    size_t len_h = strlen(h);
    size_t len_hh = strlen(hh);

    printf("Lengths: h - %d, hh -%d\n", len_h, len_hh);

    char* ss = (char*)malloc((len_h + len_hh + 1)*sizeof(char)); // +1 for the null character '\0'

    // strcat(ss, hh); // the least efficient way to copy the char
    // strcpy(ss, h); // copies each byte until it finds the null termination
    // strcpy(ss + len_h, hh); // more efficient than strcat
    
    memcpy(ss, h, len_h);
    memcpy(ss + len_h, hh, len_hh + 1); // copies from-to blocks of bytes
    puts(ss);
    free(ss);

    // ---------------------

    puts("All OK");

}

void print(int* s, size_t n)
{
    for(size_t i = 0; i <= n; i++)
    {
        printf("n: %d\n", s[i]);
    }
}