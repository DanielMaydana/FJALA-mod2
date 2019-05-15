#ifndef IHASHABLE_H
#define IHASHABLE_H

#include "Object.h"

class IHashable : public Object
{
    virtual int GetHashCode() const = 0;
};

#endif