#include "array_list.h"

array_list::array_list()
:objects{(object**)malloc(0)}, len{0}
{}
    
array_list::~array_list()
{}

void array_list::add(object* obj)
{
    objects = (object**)realloc(objects,(len + 1)*sizeof(object*));
    objects[len] = obj;
    len++;
}

size_t array_list::size() const
{
    return len;
}

object& array_list::operator[](size_t index)
{
    return *(objects[index]);
}

const object& array_list::operator[](size_t index) const
{
    return *(objects[index]);
}
