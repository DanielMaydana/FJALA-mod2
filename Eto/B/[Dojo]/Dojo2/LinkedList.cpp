#include "LinkedList.h"

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
