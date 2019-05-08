#include "HashMap.h"
#include "LinkedList.h"
#include "IHashable.h"
#include "object.h"
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

const Object &HashMap::operator[](const IHashable &key) const
{
    int hc = key.GetHashCode();
    int pos = hc % array_size;

    return items[pos][key];
}

void HashMap::iterate(void (*funct)(const IHashable &h, const Object &val)) const
{
    for (size_t i = 0; i < array_size; i++)
    {
        items[i].iterate(funct);
    }
}
