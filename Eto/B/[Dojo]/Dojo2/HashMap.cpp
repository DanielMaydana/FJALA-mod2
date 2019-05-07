#include "HashMap.h"
#include "LinkedList.h"
#include "IHashable.h"
#include "Object.h"
#include <cstring>

HashMap::HashMap(size_t array_size, double load_factor)
    : items{new LinkedList[array_size]}, element_count{0},
      array_size{array_size}, load_factor{load_factor}
{
    memset(items, 0, sizeof(LinkedList) * array_size);
}

void HashMap::add(IHashable *key, Object *value)
{
    int hc = key->GetHashCode();
    int pos = hc % array_size;
    items[pos].add(key, value);
}
