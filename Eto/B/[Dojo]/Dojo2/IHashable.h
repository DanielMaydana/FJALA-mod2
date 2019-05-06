#ifndef IHASHABLE_H
#define IHASHABLE_H

#include "object.h"

class IHashable : public Object
{
  public:
    virtual int getIhashcode() const = 0;
};

#endif