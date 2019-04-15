#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// Write your code here

// -------------STRING_LIST-------------

typedef struct
{
    char **elems;
    size_t len;

} string_list;

void sl_init(string_list *sl)
{
    sl->elems = (char **)malloc(0);
    sl->len = 0;
}

size_t sl_size(string_list *sl)
{
    return sl->len;
}

void sl_release(string_list *sl)
{
}

const char *sl_string_at(string_list *sl, int pos)
{
    return "Today";
}

void sl_add(string_list *sl, const char *c)
{
    size_t len = strlen(c);
    char *copy_c = (char *)malloc(len + 1);
    memcpy(copy_c, c, len + 1);

    sl->elems = (char **)realloc(sl->elems, ((sl->len) + 1) * sizeof(char *));
    sl->elems[sl->len++] = copy_c;
}
// -------------STR_LST_METHODS-------------

void sl_populate(string_list *sl, int n_words, ...)
{
    va_list arg_list;
    va_start(arg_list, n_words);

    for (size_t i = 0; i < n_words; i++)
    {
        // puts();
        sl_add(sl, va_arg(arg_list, char *));
    }

    va_end(arg_list);
}

void sl_join(string_list *sl, const char *tkn, char *c)
{
    for (size_t i = 0; i < sl->len; i++)
    {
        strcat(c, sl->elems[i]);

        if ((i + 1) != sl->len)
        {
            strcat(c, tkn);
        }
    }
}

bool word_ends_with_o(const char *) // -----------FUNCTION
{
    return false;
}

void sl_copy_if(string_list *filtered, string_list *raw, bool (*funct)(const char *))
{
}

const char *str_to_lower_case(const char *str) // -----------FUNCTION
{
    const char *aux = "NO";
    return aux;
}

void sl_transform(string_list *filtered, const char *(*funct)(const char *))
{
}

void sl_reverse(string_list *sl)
{
}

void to_string(char *str, int i)
{
    sprintf(str, "%d", i);
}

void accum()
{
}

void sl_iterate_with_param(string_list *sl, void (*func)(), int *n)
{
}

void sl_insert_at(string_list *sl, int pos, const char *s)
{
}

void split_words(string_list *sl, const char *text)
{
    const char *from = text;
    const char *to = text;

    // while (*to)
    // {
    // if (*to == '.' || *to == ',')
    // {
    //     // char *found_w = (char *)malloc(from - to);
    //     // memcpy(found_w, from, from - to);
    //     // printf("THIS: %c\n", *to);

    //     if (*to == ' ')
    //     {
    //         to++;
    //     }
    //     // printf("THIS: %d\n", to - from);

    //     from++;
    //     to++;

    //     from = to;
    // }

    //     to++;
    // }
}

// _______________________TESTS_______________________

typedef bool (*PTEST)();

bool test0()
{
    const char *text = "Today, Microsoft announced that it is releasing the May 2019 Update to the Release Preview ring, and it is available now";

    string_list words;
    sl_init(&words);

    split_words(&words, text);

    size_t size = sl_size(&words);

    bool result = size == 21 && strcmp(sl_string_at(&words, 0), "Today") == 0 && strcmp(sl_string_at(&words, 20), "now") == 0 && strcmp(sl_string_at(&words, 15), "ring") == 0;

    sl_release(&words);

    return result;
}

bool test1()
{
    string_list words;
    sl_init(&words);
    sl_populate(&words, 10, "Viviana", "Pamela", "Dennis", "Juan", "Alfonso", "Janet", "Jorge", "Rodrigo", "Mauro", "Julia");

    char aux[200];
    sl_join(&words, ", ", aux);

    bool result = strcmp(aux, "Viviana, Pamela, Dennis, Juan, Alfonso, Janet, Jorge, Rodrigo, Mauro, Julia") == 0;
    sl_release(&words);

    return result;
}

bool test2()
{
    string_list words;
    sl_init(&words);
    sl_populate(&words, 5, "Pedro", "Pablo", "Jose", "Maria", "Alvaro");

    string_list filtered_words;
    sl_init(&filtered_words);
    sl_copy_if(&filtered_words, &words, word_ends_with_o);

    char aux[100];
    sl_join(&filtered_words, " ", aux);

    bool result = strcmp(aux, "Pedro Pablo Alvaro") == 0;

    sl_release(&words);
    sl_release(&filtered_words);

    return result;
}

bool test3()
{
    string_list words;
    sl_init(&words);

    sl_populate(&words, 6, "MI", "nombre", "es", "JUANA AZURDUY", "de", "Padilla");
    sl_transform(&words, str_to_lower_case);

    char aux[100];
    sl_join(&words, " ", aux);

    bool result = strcmp(aux, "mi nombre es juana azurduy de padilla") == 0;
    sl_release(&words);

    return result;
}

bool test4()
{
    string_list words;
    sl_init(&words);

    sl_populate(&words, 7, "MI", "NOMBRE", "es", "Juana", "Azurduy", "de", "Padilla");
    sl_transform(&words, str_to_lower_case);

    char aux[100];
    sl_join(&words, " ", aux);

    bool result = strcmp(aux, "mi nombre es juana azurduy de padilla") == 0;
    sl_release(&words);

    return result;
}

bool test5()
{
    string_list words;
    sl_init(&words);

    sl_populate(&words, 11, "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez", "once");
    sl_reverse(&words);

    char aux[200];
    sl_join(&words, ".- ", aux);

    bool result = strcmp(aux, "once.- diez.- nueve.- ocho.- siete.- seis.- cinco.- cuatro.- tres.- dos.- uno") == 0;

    sl_release(&words);

    return result;
}

bool test6()
{
    string_list numbers;
    sl_init(&numbers);

    for (int i = 0; i < 100; i++)
    {
        char aux[20];
        to_string(aux, i);
        sl_add(&numbers, aux);
    }

    int sum = 0;
    sl_iterate_with_param(&numbers, accum, &sum);

    bool result = sum == 4950;

    sl_release(&numbers);
    return result;
}

bool test7()
{
    string_list words;
    sl_init(&words);

    sl_populate(&words, 4, "tres", "cuatro", "cinco", "seis");
    sl_add(&words, "ocho");
    sl_insert_at(&words, 0, "dos");
    sl_insert_at(&words, 0, "uno");
    sl_insert_at(&words, 6, "siete");

    char aux[100];
    sl_join(&words, ".", aux);

    bool result = strcmp(aux, "uno.dos.tres.cuatro.cinco.seis.siete.ocho") == 0;
    sl_release(&words);
    return result;
}

int main()
{
    PTEST tests[] = {test0, test1, test2, test3, test4, test5, test6, test7};

    int score = 0;
    for (size_t i = 0; i < 8; i++)
    {
        printf("Running test%d\n", (int)i);
        score += tests[i]() ? 1 : 0;
    }

    printf("Final score: %d / 8\n", score);
    return 0;
}

/*
Constraints:
- Do not modify the tests or the main function.
- Do not use any C++ construct, only what we have seen at classes
- Do not use any third party library
- Do not leave memory leaks, they will decrease your score in 10 points over 100.
- Your program MUST compile, otherwise your score will be 0.
- Enjoy!
*/