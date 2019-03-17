#ifndef FACTURA_H
#define FACTURA_H
#include "item.h"
#include "object.h"
#include "m_string.h"
#include "array_list.h"


class factura : public object
{
private:
    m_string name;
    m_string nit;
    double descuento;
    array_list item_list;
    
public:
    factura(const m_string& name, const m_string& nit);

    factura(const m_string& name);

    ~factura();
    
    void agregar_item(size_t quantity, const m_string& id);

    void agregar_descuento(double discount);

    void mostrar();


};


#endif