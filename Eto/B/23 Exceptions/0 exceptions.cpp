#include <stdio.h>
#include <string>
#include <stdexcept>
using namespace std;

void fun0()
{
    puts("Deepest fun0");
    throw new exception();
    puts("ending fun 0");
}

void fun1()
{
    try
    {
        puts("Function 1");
        fun0();
    }
    catch (...)
    {
        puts("Catched in fun1");
    }

    puts("ending fun 1");
}

int main()
{
    try
    {
        fun1();
    }
    catch (...)
    {
        puts("Catched!");
    }
    puts("Alles ok");
}