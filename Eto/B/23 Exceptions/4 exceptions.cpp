#include<stdio.h>
#include<string>
using namespace std;

struct Ex
{
    int code;
    std::string msg;

    ~Ex()
    {
        puts("Exception bye");
    }
};

void s()
{
    puts("A");
    throw Ex{14, "file not found"};
    puts("B");
}

void z()
{
    s();
}

int main()
{
    try
    {
        // s();
        z();
    }
    catch(const Ex& e) // always use const &
    {
        puts(e.msg.data());
    }
}