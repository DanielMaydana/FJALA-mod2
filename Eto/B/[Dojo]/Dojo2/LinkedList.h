#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "object.h"
#include "IHashable.h"

struct LinkedListNode
{
    LinkedListNode *next;
    IHashable *key;
    Object *value;
};

struct LinkedList
{
    LinkedListNode *first;
    LinkedListNode *last;
    void add(IHashable *key, Object *value);
    const Object &operator[](const IHashable &key) const;
    void iterate(void (*funct)(const IHashable &h, const Object &val)) const;
};

#endif
