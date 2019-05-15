#ifndef OBJECT_H
#define OBJECT_H

#include <string>

struct Object
{
    virtual ~Object();
    virtual std::string to_string() const = 0;
    virtual bool equals(const Object &obj) const = 0;
};

#endif