#include <iostream>
using namespace std;

void copiar_cadena(char* cd, const char* c)
{   
    while(*c)
    {
        *cd = *c;
        cd++;
        c++;
    }
    *cd = 0;
}

// char* posicion_final(char* cd)
// {
//     while(*cd){
//     cd++;
//     }
//     *cd = ' ';
//     return ++cd;
// }

// void concatenar_cadena(char* cd, const char* d)
// {
//     char* pos = posicion_final(cd);
//     copiar_cadena(pos, d);
// }

// void substring(char* rr, const char* r, size_t ini, size_t size)
// {   
//     r += ini;
//     while(size && *r)
//     {
//         *rr = *r;
//         rr++;
//         r++;
//         size--;
//     }
//     *rr = 0;
// }


int main()
{
    const char* c = "fundacion";
    const char* d = "jala";
    char cd[30];
    copiar_cadena(cd, c);
    // cout << cd << "\n";
    // concatenar_cadena(cd, d);
    // cout << cd << "\n";

    // auto r = "hoy es lunes 12";
    // char rr[10];
    // substring(rr, r, 7, 10);
    // cout << rr << "\n";
}



// ejercicio mauricio
// #include <iostream>
// using namespace std;

// size_t calc_length_ap(const char *s)
// {
//     const char *orig = s;
//     while (*s++);
//     return s - orig - 1;
// }

// void copiar_cadena(char *dest, const char *src)
// {
//     while (*src != '\0')
//     {
//         *dest = *src;
//         dest++;
//         src++;
//     }
//     *dest = 0;
// }

// void concatenar_cadena(char *dest, const char *src)
// {
//     size_t length = calc_length_ap(dest);
//     while (*src != '\0')
//     {
//         *(dest + length) = *src;
//         dest++;
//         src++;
//     }
//     *dest = 0;
// }

// void substring(char *sstr, const char *str, size_t from, size_t to)
// {
//     size_t i = 0;
//     while (i < to && *str != '\0')
//     {
//         *sstr = *(str + from);
//         *str++;
//         *sstr++;
//         i++;
//     }
//     *sstr = 0;
// }

// int main()
// {
//     // const char *c = "Fundacion";
//     // const char *d = "Jala";
//     // char cd[30];
//     // copiar_cadena(cd, c);
//     // cout << cd << "\n";
//     // concatenar_cadena(cd, d);
//     // cout << cd << "\n";
//     auto r = "hoy es lunes 12";
//     char rr[10];
//     substring(rr, r, 7, 5);
//     cout << rr << "\n"; //lunes
// }