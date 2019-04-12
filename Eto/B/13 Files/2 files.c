#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Read form a file

int main()
{
    FILE* f = fopen("days.txt", "r");

    if (f == NULL) return -4; // anything but 0 (0 means that everything went ok)
    
    char aux[1000];
    
    while(true)
    {
        fgets(aux, 1000, f); // [aux] where is going to write the red info, [1000] the max number of chars that's going to read, [f] from where is going to read
        if(feof(f)) break; // breaks the cycle if we reached the end of the file
        else fputs(aux, stdout); // stdout is a ptr that points to the screen
    }
    
    fclose(f);

    // ------------------------------------------

    const char* h = "phill";
    int k = 58;
    char aux[50];

    sprintf(aux, "%s is %d yo", h, k); // write formatted data to string // useful to convert int to string

    puts(aux);
    char x[20];
    sprintf(x, "%d", k);
}