#ifndef STRING_H
#define STRING_H
#include "IHashable.h"

class String : public IHashable
{
public:
    String();
    ~String();
    std::string to_string() const override;
    bool equals(const Object &obj) const override;
    int GetHashCode() const override;
};

#endif