#include "factura.h"

factura::factura(const m_string& name, const m_string& nit)
:name{name}, nit{nit}, descuento{0}
{}

factura::factura(const m_string& name)
:name{name}, nit{"0"}
{}

factura::~factura()
{}

void factura::agregar_item(size_t quantity, const m_string& id)
{
    item* new_item = new item{quantity, id};
    item_list.add(new_item);
}

void factura::agregar_descuento(double discount)
{

}

void factura::mostrar()
{
    cout << name.get_str() << "\t" << nit.get_str() << "\n" << "ITEMS\n"

}