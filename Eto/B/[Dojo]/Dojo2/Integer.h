#ifndef INTEGER_H
#define INTEGER_H

#include "IHashable.h"

class Integer : public IHashable
{
private:
  int n;

public:
  Integer(int n);
  std::string to_string() const override;
  bool equals(const Object &obj) const override;
  int GetHashCode() const override;
};

#endif