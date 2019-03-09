#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "object.h"
#include "m_string.h"


class item : public object
{
private:
    size_t quantity;
    m_string id;
public:
    item(size_t quantity, m_string id);

    ~item();

};

#endif