#pragma once
#include <iostream>

struct fecha
{
    size_t dia;
    size_t mes;
    size_t anio;

    fecha();
    fecha(size_t dia, size_t mes, size_t anio);
    bool operator== (const fecha&) const;
};
