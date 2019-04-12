#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *str;
    int len;
} s_builder;

void sb_init(s_builder *p)
{
    p->str = (char *)malloc(0);
    p->len = 0;
    // puts("\n*****\nuntil here\n*****\n");
}

// char *clone_str(const char *c)
// {
// }

void sb_add(s_builder *p, const char *c)
{
    size_t lenc = strlen(c);

    p->str = (char *)realloc(p->str, (lenc + 1) + (p->len));
    memcpy(p->str + (p->len), c, lenc + 1);
    p->len = (p->len) + lenc;
    // puts(p->str);
}

void sb_add_space(s_builder *p)
{
    sb_add(p, " ");
}

char *sb_get_string(s_builder *p)
{
    char *aux = (char *)malloc(p->len + 1);
    memcpy(aux, p->str, p->len + 1);
    return aux;
}

void sb_release(s_builder *p)
{
    free(p->str);
}

int main()
{
    s_builder sb;
    sb_init(&sb);

    sb_add(&sb, "Deep beneath");
    sb_add_space(&sb);
    sb_add(&sb, "the rolling waves");
    sb_add_space(&sb);
    sb_add(&sb, "in labyrinths of");
    sb_add_space(&sb);
    sb_add(&sb, "coral caves");

    puts(sb.str);

    char *c = sb_get_string(&sb);
    sb_release(&sb);

    free(c);
    puts(c);

    puts("\nAll OK");
}