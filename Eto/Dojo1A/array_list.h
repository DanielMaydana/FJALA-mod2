#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include  <iostream>
#include "object.h"

class array_list
{
private:
    object** objects;
    size_t len;
public:
    array_list();
    
    ~array_list();

    void add(object*);

    size_t size() const;

    object& array_list::operator[](size_t index);

    const object& array_list::operator[](size_t index) const;

    // void show() const;
};



#endif