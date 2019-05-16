#ifndef STRING_H
#define STRING_H
#include <string>
#include "IHashable.h"
#include "Object.h"

class String : public IHashable
{
    std::string str;

public:
    ~String();
    String(const std::string &str);
    std::string to_string() const override;
    bool equals(const Object &src) const override;
    int GetHashCode() const override;
};

#endif