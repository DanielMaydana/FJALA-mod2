#include "String.h"

String::String(const std::string &str)
    : str{str}
{
}

std::string String::to_string() const
{
    return str;
}

bool String::equals(const Object &obj) const
{
    auto e = dynamic_cast<const String *>(&obj);
    return e == nullptr ? false : str == e->str;
}

int String::GetHashCode() const
{
    const char *aux = str.c_str();
    int r = 0;
    while (*aux)
    {
        r += *(aux++) * 31 + 100;
    }
    return r;
}
