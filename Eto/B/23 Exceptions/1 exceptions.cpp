#include<stdio.h>
#include<string>
using namespace std;

// Can't catch arithmetic errors or segmentation fault errors

void c()
{
    puts("string c");
    throw;
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
    catch(...)
    {
        puts("error caught in a");
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