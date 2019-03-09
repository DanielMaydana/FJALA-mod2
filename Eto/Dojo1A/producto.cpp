#include "producto.h"

producto::producto(const m_string& name, const m_string& brand, const m_string& id, size_t stock, double price)
:name{name}, brand{brand}, id{id}, stock{stock}, price{price}
{}

producto::~producto()
{}