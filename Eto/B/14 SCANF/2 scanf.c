#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct{
    int x;
    int y;
}point;

void print_point(const point* p)
{
    printf("(%d:%d)\n", p->x, p->y);
}

int main()
{
    FILE* f = fopen("points.txt", "r");
    if(!f) return -16;

    point p;

    while(fscanf(f, "%d:%d", &p.x, &p.y) == 2)
    {
        print_point(&p);

    }

    fclose(f);

}