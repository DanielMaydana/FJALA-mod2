#ifndef IHASHABLE_H
#define IHASHABLE_H

#include "Object.h"

class IHashable : public Object
{
public:
    virtual int GetHashCode() const = 0;
};

#endif