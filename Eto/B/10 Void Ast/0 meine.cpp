#include <stdio.h> 
#include <stdlib.h>
#include <string>

using namespace std;

size_t char_len(const char *c)
{
    const char *aux = c;

    while (*c)
    {
        c++;
    }
    return c - aux;
}

struct LLNode
{
    LLNode *next;
    const char* word;

    LLNode(LLNode * next, const string& str) : next{next}, word{str.data()}
    {
    }
};

class LinkedList
{
    LLNode *first;
    LLNode *last;
    size_t count;

    public:

    LinkedList() : first{nullptr}, last{nullptr}
    { 
    }

    void add(const string& s)
    {
        LLNode *nn = new LLNode{nullptr, s};

        if(first == nullptr)
        {
            first = last = nn;
            return;
        }
        
        last->next = nn;
        last = nn;
    }

    const char*const& iterate()
    {
        auto aux = first;
        string concat = "";

        while(aux != nullptr)
        {
            concat.append(aux->word);
            aux = aux->next;
        }
        puts(concat.data());

        return (concat.data());
    }

};

int main()
{
    string s1 = "Hello ";
    string s2 = "my ";
    string s3 = "darling";

    LinkedList myList;

    myList.add(s1);
    myList.add(s2);
    myList.add(s3);

    puts(myList.iterate());

    puts("end");
}