#include<stdio.h>
#include<string>
using namespace std;

struct Int
{
    int n;
    
    ~Int()
    {
        puts("bye Int");
    }
};

struct W
{
    Int* n;

    ~W()
    {
        delete n;
    }
};

void m()
{
    W w{new Int{64}}; // stack objects call their desctructors by themselves
    printf("%d\n", w.n->n);
    throw true;
}

int main()
{
    try
    {
        m();
        
    }
    catch(...)
    {
        puts("error");
    }
    
}