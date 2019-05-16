#include "Integer.h"

Integer::~Integer()
{
}

Integer::Integer(const int &n) : n{n}
{
}

std::string Integer::to_string() const
{
    return std::to_string(n);
}

bool Integer::equals(const Object &src) const
{
    auto aux = dynamic_cast<const Integer *>(&src);
    return aux == nullptr ? false : aux->n == n;
}

// bool Integer::equals(const Object *src) const
// {
//     auto aux = dynamic_cast<const Integer *>(src);
//     return aux == nullptr ? false : aux->n == n;
// }

int Integer::GetHashCode() const
{
    return 0;
}
