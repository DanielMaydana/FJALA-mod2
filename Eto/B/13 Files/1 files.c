#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Write to a file

int main()
{
    FILE* f = fopen("days.txt", "w");
    
    const char* days[] = {"lunes", "martes", "miercoles", "jueves", "viernes"};
    
    if (f == NULL) return -4;
    {
        for(size_t i = 0; i < 5; i++)
        {
            fputs(days[i], f);
            fputs("\n", f);
        }
    }
    fclose(f);
}