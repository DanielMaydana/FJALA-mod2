#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char *item;
    size_t size;
} string_builder;

void sb_init(string_builder *p)
{
    p->item = (char *)malloc(0);
    p->size = 0;
}

// -------------OTHER-------------

size_t char_len(const char *c)
{
    const char *aux = c;

    while (*c)
    {
        c++;
    }

    return c - aux;
}

size_t sb_length(const string_builder *sb)
{
    return sb->size;
}

const char *sb_get_str(const string_builder *sb)
{
    return sb->item;
}

void sb_release(string_builder *sb)
{
    free(sb->item);
}

// -------------ADD-------------

void sb_add_str(string_builder *sb, const char *s)
{
    size_t len = char_len(s);

    sb->item = (char *)realloc(sb->item, ((sb->size) + len + 1) * sizeof(char));

    // memcpy((sb->item) + (sb->size), s, len + 1);
    char *aux = sb->item;
    aux += sb->size;
    memcpy(aux, s, len + 1);

    puts("whut");
    puts(sb->item);

    sb->size += len;
}

// void sb_add_str(string_builder *sb, const char *s)
// {
//     sb->size += strlen(s);
//     sb->item = (char *)realloc(sb->item, sizeof(char *) * sb->size + 1);
//     strcat(sb->item, s);
// }

void sb_add_int(string_builder *sb, int n)
{
    char integer[5];
    sprintf(integer, "%d", n);
    sb_add_str(sb, integer);
}

void sb_add_line(string_builder *sb)
{
    sb->size += 2;
    sb->item = (char *)realloc(sb->item, sizeof(char *) * sb->size + 1);
    strcat(sb->item, "\n");
}

// -------------MAIN-------------

int main()
{
    string_builder x;
    sb_init(&x);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            sb_add_str(&x, "(");
            sb_add_int(&x, i);
            sb_add_str(&x, ",");
            sb_add_int(&x, j);
            sb_add_str(&x, "); ");
        }
        sb_add_line(&x);
    }
    // puts(sb_get_str(&x));

    sb_release(&x);
}