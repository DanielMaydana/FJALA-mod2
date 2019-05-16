#define INTEGER_H
#ifndef INTEGER_h
#include "IHashable.h"

class Integer : public IHashable
{
    int n;

public:
    ~Integer();
    Integer(const int &n);
    std::string to_string() const override;
    bool equals(const Object &src) const override;
    // bool equals(const Object *src) const;
    int GetHashCode() const override;
};

#endif