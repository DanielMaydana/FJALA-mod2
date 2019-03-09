#pragma once
#include <iostream>
#include <cstring>

struct person
{
    char name[128];
    char last_name[128];
    int birt_year;
    bool operator== (const person& p) const
    {
        return strcmp(name, p.name)==0  &&
        strcmp(last_name, p.last_name)==0;
    }
};

std::ostream &operator<<(std::ostream& os, const person& p)
{
    os<<p.name<<";"<<p.last_name<<";"<<p.birt_year;
    return os;
};
