#pragma once
#include <iostream>
#include "object.h"
using namespace std;

class array_list: public object
{
    object** objects;
    size_t len;
    bool owner;
    public:

        array_list(bool owner = true);
        ~array_list();
        size_t size() const;
        void add(object*);
        object & operator[](size_t index);
        const object & operator[](size_t index) const;
        void mostrar() const override;
        const object& get_object(const object&)const;
        object& get_object(const object&);
};