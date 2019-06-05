#include <stdio.h>
#include <cstring>
#include <stdlib.h>

const char *test = "this;string;has,two,different;delimiter";

int scan_s(const char *str, size_t str_len, size_t *s, size_t *e, const char delim)
{
    if (*e == str_len)
        return -1;
    for (*e = *s; *e <= str_len; *e += 1)
    {
        if ((str[*e] == delim) || (*e == str_len))
        {
            return *e - *s;
        }
    }
    return -2;
}

int main()
{
    size_t str_len = strlen(test);
    size_t s = 0, e = 0;
    char *tok;

    printf("%d\n", str_len);

    while (scan_s(test, str_len, &s, &e, ';') >= 0)
    {
        size_t ss = 0, ee = 0;
        while (scan_s(test + s, e - s, &ss, &ee, ',') >= 0)
        {
            tok = (char *)malloc((ee - ss + 1) * sizeof(char));
            memcpy(tok, test + s + ss, ee - ss);
            tok[ee - ss] = '\0';

            printf("%d %s\n", ee - ss, tok);
            ss = ee + 1;
            free(tok);
        }
        s = e + 1;
    }
    return 0;
}