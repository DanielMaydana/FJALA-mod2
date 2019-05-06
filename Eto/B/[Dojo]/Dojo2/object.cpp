#include "object.h"

std::string Object::to_string() const
{
    return std::to_string((long long)this);
}

bool Object::equals(const Object &src) const
{
    return this == &src;
}

Object::~Object()
{
}