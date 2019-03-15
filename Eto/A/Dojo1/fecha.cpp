#include "fecha.h"
#include <ctime>

fecha::fecha()
{
    time_t today;
    time(&today);
    tm *info = localtime(&today);
    dia = info->tm_mday;
    mes = info->tm_mon + 1;
    anio = info->tm_year + 1900;
}
fecha::fecha(size_t dia, size_t mes, size_t anio)
    :dia{dia}, mes{mes}, anio{anio}
{}
bool fecha::operator== (const fecha& fe) const
{
    return dia==fe.dia && mes==fe.mes&&anio==fe.anio;
}