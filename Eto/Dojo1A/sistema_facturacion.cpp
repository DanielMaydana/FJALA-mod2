#include "sistema_facturacion.h"

sistema_facturacion::sistema_facturacion()
{

}

sistema_facturacion::~sistema_facturacion()
{

}

void sistema_facturacion::agregar_producto(const m_string& name, const m_string& brand, const m_string& id, size_t stock, double price)
{
    producto* new_product = new producto{name, brand, id, stock, price};
    product_list.add(new_product);
}

factura& sistema_facturacion::crear_factura(const m_string& name, const m_string& nit)
{
    factura* new_factura = new factura{name, nit};
    factura_list.add(new_factura);
    return *new_factura;
}

factura& sistema_facturacion::crear_factura(const m_string& name)
{
    factura* new_factura = new factura{name};
    return *new_factura;
}

array_list sistema_facturacion::obtener_facturas_de_hoy()
{
    array_list aux;
    
    for(size_t i = 0; i < factura_list.size(); i++)
    {
        aux.add(&factura_list[i]);
    }
    return aux;
}