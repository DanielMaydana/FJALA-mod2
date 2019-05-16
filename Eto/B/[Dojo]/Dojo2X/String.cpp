#include "String.h"

String::~String()
{
}

String::String(const std::string &str) : str{str}
{
}

std::string String::to_string() const
{
    return str;
}

bool String::equals(const Object &src) const
{
    // printf("[%d]", src);
    auto aux = dynamic_cast<const String *>(&src);
    return aux == nullptr ? false : str == aux->str;
}

int String::GetHashCode() const
{
    return 0;
}
