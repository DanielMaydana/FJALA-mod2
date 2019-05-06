#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object
{
  public:
    virtual std::string to_string() const;
    virtual bool equals(const Object &) const;
    virtual ~Object();
};

#endif