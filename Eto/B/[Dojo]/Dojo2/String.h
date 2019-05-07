#ifndef STRING_H
#define STRING_H
#include "IHashable.h"
#include <string>

class String : public IHashable
{
    std::string str;

  public:
    String(const std::string &str);

    std::string to_string() const override;

    bool equals(const Object &) const override;

    int GetHashCode() const override;
};

#endif