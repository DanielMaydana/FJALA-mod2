#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "m_string.h"
#include "object.h"

class producto : public object
{
private:
    m_string name;
    m_string brand;
    m_string id;
    size_t stock;
    double price;
public:
    producto(const m_string& name, const m_string& brand, const m_string& id, size_t stock, double price);

    ~producto();
};
#endif