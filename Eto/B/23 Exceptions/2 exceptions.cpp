#include<stdio.h>
#include<string>
using namespace std;

// Can't catch arithmetic errors or segmentation fault errors

void c()
{
    puts("string c");
    // throw ":("; // exception throwed
    throw 20U;
}

void b()
{
    puts("string b");
    c();
    puts("ending b");
}

void a()
{
    try
    {
        puts("string a");
        b();
        puts("Ending a");
    }
    catch(const char* e) // type of exception
    {
        printf("Error: %s\n", e);
    }
    catch(const size_t e)
    {
        printf("Unsigned exception %d\n", e);
    }
}

int main()
{
    try
    {
        a();
        puts("Happy bye");
    }
    catch(...) // (...) catches any exception
    {
        puts("error");
    }

    puts("Bye anyway");
}