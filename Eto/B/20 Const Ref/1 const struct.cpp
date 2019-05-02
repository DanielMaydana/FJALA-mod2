#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct Char
{
    char s;

    std::string to_string()
    {
        char aux[2];
        aux[0] = '6';
        aux[1] = '3';
        return aux;
    }
};

struct Int
{
    int n;
    std::string to_string() const
    {
        string aux = std::to_string(n);
        return aux;
    }
};

class IntChar : Int, Char
{
    IntChar(int n, char c) : Int{n}, Char{c}
    {
    }

    // IntChar(int n, char c) : Int{n}, Char{s}
    // {
    //     this->n = n;
    //     this->s = s;
    // }
};
