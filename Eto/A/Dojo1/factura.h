#include <iostream>
#include "object.h"
#include "m_string.h"
#include "array_list.h"
#include "fecha.h"
#pragma once// es valido, de momento

using namespace std;
class sistema_facturacion;
class factura: public object
{
    m_string nombre;
    m_string nit;
    double descuento;
    array_list items;
    sistema_facturacion& sis;
    fecha fecha_factura;
    public:
        factura(const m_string &nombre, const m_string &nit, sistema_facturacion& sis, const fecha& f = fecha{});
        void agregar_item(size_t, const m_string&);
        void agregar_descuento(double desc);
        void mostrar() const override;
        double get_precio_total()const;
        const fecha& get_fecha() const;
};