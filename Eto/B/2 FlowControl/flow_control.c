#include <stdio.h> 

int main() 
{
    // int n = 0;
    // while(n != 10)
    // {
    //     printf("%d\n", n);
    //     n++;
    // }

    // int m = 0;
    // do{
    //     printf("%d\n", m++);
    // }
    // while(m != 10);

    //-----------------------

    int error[10];

    for(int q = 0; q <= 10; q++)
    {
        error[q] = q;
        printf("Pos: %d\n", error[q]);
    }

    printf("Pos100: %d\n", error[14]);

    //-----------------------

    // int row, col;
    // int limRow = 5, limCol = 10;

    // for(row = 0, col = 0; row < 20 ;)
    // {
    //     printf("%d\n", row++);
    // }

    //-----------------------

    puts("OK");
}