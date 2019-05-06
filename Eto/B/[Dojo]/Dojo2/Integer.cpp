#include "Integer.h"

Integer::Integer(int n) : n{n}
{
}

std::string Integer::to_string() const
{
    return std::to_string(n);
}

bool Integer::equals(const Object &obj) const
{
    auto e = dynamic_cast<const Integer *>(&obj);
    return e == nullptr ? false : n == e->n;
}

int Integer::getIhashcode() const
{
    return n;
}
