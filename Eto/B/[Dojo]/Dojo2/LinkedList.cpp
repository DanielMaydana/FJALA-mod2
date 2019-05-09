#include "LinkedList.h"
#include "HashMapException.h"

LinkedList::LinkedList()
    : first{nullptr}, last{nullptr}
{
}
void LinkedList::add(LinkedListNode *nn)
{
    if (first == nullptr)
    {
        first = last = nn;
        return;
    }

    last->next = nn;
    last = nn;
}

void LinkedList::add(IHashable *key, Object *value)
{
    auto nn = new LinkedListNode{nullptr, key, value};
    add(nn);
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

LinkedList::~LinkedList()
{
    // puts("Bye");
    LinkedListNode *aux = first;

    while (aux != nullptr)
    {
        LinkedListNode *auxNext = aux->next;
        delete aux;
        aux = auxNext;
    }
}