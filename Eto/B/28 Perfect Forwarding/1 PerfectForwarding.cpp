#include <stdio.h>
#include <string.h>
#include <utility>
#include <iostream>

using namespace std;

char* clone_str(const char* s)
{
    auto len = strlen(s);
    auto ns = new char[len + 1];
    memcpy(ns, s, len + 1);

    return ns;
}

class myString
{
    char* str;

public:
    ~myString()
    {
        delete[] str;
    }

    myString(const char* s) : str{clone_str(str)}
    {
        puts("regular");
    }

    myString(const myString& src) : str{clone_str(src.str)}
    {
        puts("copy");
    }

    myString(myString &&src) : str{src.str}
    {
        puts("move");
        src.str = nullptr;
    }

    myString& operator=(myString&& src)
    {
        this->~myString();
        str = src.str;
        src.str = nullptr;
        puts("move =");

        return *this;
    }

    myString& operator=(const myString &src)
    {
        puts("copy");
        this->~myString();
        str = clone_str(src.str);
        return *this;
    }

    const char* data()
    {
        return str;
    }
};

class Person
{
    myString fn;
    myString ln;

public:

    template<typename S1, typename S2>
    Person(S1&& fn, S2&& ln) : fn{forward<S1>(fn)}, ln{forward<S2>(ln)}
    {
        puts("constr 1");
    }

    void show()
    {
        printf("%s, %s\n", ln.data(), fn.data());
    }
};

// ---------------------

int main()
{
    // myString s = "hola";
    // puts(s.data());

    // ---------------------

    myString j = "Jon";
    myString s = "Snow";

    // Person p1 {"Dante", "Aligieri"};
    Person p4 {j, s};


    // auto p2 = p1;

    // auto p3 = move(p1);

    // p2.show();
    // p3.show();
    p4.show();

    // ---------------------

    int n = 4;
}