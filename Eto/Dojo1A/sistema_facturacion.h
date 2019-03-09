#ifndef SISTEMA_FACTURACION_H
#define SISTEMA_FACTURACION_H
#include <iostream>
#include "m_string.h"
#include "array_list.h"
#include "factura.h"
#include "producto.h"


class sistema_facturacion
{   
private:
    array_list product_list;
    array_list factura_list;
public:
    sistema_facturacion();

    ~sistema_facturacion();

    void agregar_producto(const m_string& name, const m_string& brand, const m_string& id, size_t stock, double price);

    factura& crear_factura(const m_string& name, const m_string& nit);

    factura& crear_factura(const m_string& name);

    array_list obtener_facturas_de_hoy();
};  


#endif