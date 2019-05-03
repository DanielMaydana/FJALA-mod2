#include<stdio.h>
#include<string>
#include<stdexcept>
using namespace std;

class Ex2 : public std::exception
{
    int code;
    std::string msg;

    public:

    Ex2(int c, const string& m) : code{c}, msg{m}
    {

    }

    const char* what() const noexcept override
    {
        return msg.data();
    }
};

void s()
{
    puts("A");
    throw Ex2{14, "File not found"};
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
        z();
    }
    catch(const std::exception& e)
    {
        puts(e.what());
    }
}