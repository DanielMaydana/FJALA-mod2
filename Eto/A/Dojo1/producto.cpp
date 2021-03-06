#include "producto.h"
producto::producto(const m_string &nombre,
                   const m_string &marca,
                   const m_string &codigo,
                   size_t stock,
                   double precio) : nombre{nombre}, marca{marca}, codigo{codigo}, stock{stock}, precio{precio}
{
}

void producto::mostrar() const {}

bool producto::equals_to(const object &obj) const
{
    const producto &p = static_cast<const producto &>(obj);
    return p.codigo == this->codigo;
}

const m_string &producto::get_name() const
{
    return nombre;
}
const m_string &producto::get_marca() const
{
    return marca;
}
const size_t producto::get_stock() const
{
    return stock;
}
const double producto::get_precio() const
{
    return precio;
}
void producto::reducir_stock(size_t cant)
{
    stock = stock - cant;
}

