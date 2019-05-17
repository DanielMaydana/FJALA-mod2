#include "HashMap.h"
#include "LinkedList.h"
#include "IHashable.h"
#include "object.h"
#include <cstring>

HashMap::HashMap(size_t array_size, double load_factor)
    : items{new LinkedList[array_size]}, element_count{0},
      array_size{array_size}, load_factor{load_factor}
{
    //memset(items, 0, sizeof(LinkedList) * array_size);
}

void HashMap::add(IHashable *key, Object *value)
{
    if (((double)element_count) / array_size > load_factor)
    {
        reHash();
    }
    
    size_t hc = key->GetHashCode();
    int pos = hc % array_size;

    printf("HC %d | ARR_SZ %d\n", hc, array_size);        
    printf("HC %d | POS %d\n", hc, pos);

    items[pos].add(key, value);
    element_count++;
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

HashMap::~HashMap()
{
    delete[] items;
}

void HashMap::relink(LinkedList *new_items, int n_array_size, LinkedList &array_pos)
{
    LinkedListNode *aux = array_pos.first;
    while (aux)
    {
        LinkedListNode *next = aux->next;
        aux->next = nullptr;
        int npos = aux->key->GetHashCode() % n_array_size;
        new_items[npos].add(aux);
        aux = next;
    }
    array_pos.first = array_pos.last = nullptr;
}

void HashMap::reHash()
{
    puts("REHASH");
    int n_array_size = array_size * 2 + 1;

    LinkedList *new_items = new LinkedList[n_array_size];
    
    for (size_t i = 0; i < array_size; i++)
    {
        relink(new_items, n_array_size, items[i]);
    }

    delete[] items;
    items = new_items;
    array_size = n_array_size;
}

bool HashMap::erase(const IHashable& key)
{
    int hc = key.GetHashCode();
    int pos = hc % array_size;
    return items[pos].erase(key);
}
