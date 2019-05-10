#ifndef HASHMAP_H
#define HASHMAP_H
#include <cstdio>
struct LinkedList;
class IHashable;
class Object;

class HashMap
{
  private:
    LinkedList *items;
    size_t element_count;
    size_t array_size;
    double load_factor;
    void reHash();
    void relink(LinkedList *n_items, int n_array_size, LinkedList &linkedList);

  public:
    HashMap(size_t array_size = 5, double load_factor = 0.75);
    void add(IHashable *key, Object *value);
    const Object &operator[](const IHashable &key) const;
    void iterate(void (*funct)(const IHashable &h, const Object &val)) const;
    bool erase(const IHashable&);
    ~HashMap();
};

#endif
