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
    LinkedList();
    LinkedListNode *first;
    LinkedListNode *last;
    void add(IHashable *key, Object *value);
    void add(LinkedListNode *node);
    const Object &operator[](const IHashable &key) const;
    void iterate(void (*funct)(const IHashable &h, const Object &val)) const;
    ~LinkedList();
};

#endif
