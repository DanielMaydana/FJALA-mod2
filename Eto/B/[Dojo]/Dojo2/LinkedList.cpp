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

bool LinkedList::erase(const IHashable& key)
{
    if(first == nullptr) return false; // there isn't a single node

    if(first == last)
    {        
        if (key.equals(*(first->key)))
        {
            delete first->key;
            delete first->value;
            delete first;
            first = last = nullptr;
            return true;
        }
        return false;
    }

    if (key.equals(*(first->key)))
    {
        LinkedListNode* aux = first->next;
        delete first->key;
        delete first->value;
        delete first;
        first = aux;

        return true;                
    }
    
    LinkedListNode *auxA = first;

    while (auxA->next != nullptr)
    {
        LinkedListNode *auxB = auxA->next;

        if (key.equals(*(auxB->key)))
        {   
            auxA->next = auxB->next;

            if(auxB->next == nullptr)
            {
                last = auxA;
            }

            delete auxB->key;
            delete auxB->value;
            delete auxB;
            return true;
        }

        auxA = auxA->next;
    }

    return false;

}

LinkedList::~LinkedList()
{
    // puts("Bye");
    LinkedListNode *aux = first;

    while (aux != nullptr)
    {
        LinkedListNode *auxNext = aux->next;
        delete aux->value;
        delete aux->key;
        delete aux;
        aux = auxNext;
    }
}