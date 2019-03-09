//palabras reservadas del flujo de control

#include <iostream>
using namespace std;

bool is_even(int n)
{
    if (n % 2)
        return true;
    return false;
}

void print_day(int d)
{
    switch(d)
    {
        default: cout << "invalid day"; break;
        case 0: cout << "Domingo\n"; break;
        case 1: cout << "Lunes\n"; break;
        case 2: cout << "Martes\n"; break;
        case 3: cout << "Miercoles\n"; break;
        case 4: cout << "Jueves\n"; break;
        case 5: cout << "Viernes\n"; break;
        case 6: cout << "Sabado\n"; break;
        
    }
}

// void count_down(int n) //las funciones recursivas muy grandes tienden a salir del callstak y provocar segmentation foult
// {
//     cout << n << "\n";
//     if(n == 0)
//     {
//         return; //hace que salga de la funcion
//     }
//     count_down(n-1);
// }

void count_down(int n)
{
    while (n >= 0)
    {
        cout << n-- << "\n";
    }
}

void count(int a, int b)
{
    for(int i = a; i <= b; i++)
        cout << i << "\n";
}

void count(int a, int b, int ex)
{
    int i = a;
    while(i <= b)
    {
        if (i == ex)
        {
            i++;
            continue; //ignora las lineas de abajo y vuelve al principio del metodo
            // return; // finaliza el metodo
        }
        cout << i << "\n";
        i++;
    }
}

void print_as_text(unsigned int n)
{
    
}

int main()
{
    // cout << is_even(64) << "\n";
    // cout << is_even(63) << "\n";
    // print_day(0);
    // count_down(500000);
    // count(5, 8);
    count(1, 15, 11);

    print_as_text(2481);
}