#include "HashMapException.h"

HashMapException::HashMapException(const std::string &msg)
    : msg{msg}
{
}
const char *HashMapException::what() const noexcept
{
    return msg.data();
}
