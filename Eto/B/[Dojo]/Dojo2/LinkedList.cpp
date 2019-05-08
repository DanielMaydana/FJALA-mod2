#include "LinkedList.h"
#include "HashMapException.h"
void LinkedList::add(IHashable *key, Object *value)
{
    auto nn = new LinkedListNode{nullptr, key, value};
    if (first == nullptr)
    {
        first = last = nn;
        return;
    }

    last->next = nn;
    last = nn;
}

const Object &LinkedList::operator[](const IHashable &key) const
{
    LinkedListNode *aux = first;

    while (aux != nullptr)
    {
        if (key.equals(*(aux->key)))
            return *(aux->value);
        aux = aux->next;
    }

    throw HashMapException("Key not found");
}

void LinkedList::iterate(void (*funct)(const IHashable &h, const Object &val)) const
{
    LinkedListNode *aux = first;
    while (aux != nullptr)
    {
        funct(*(aux->key), *(aux->value));
        aux = aux->next;
    }
}
