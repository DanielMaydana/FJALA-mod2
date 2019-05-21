#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

char* clone_str(const char* s)
{
    auto len = strlen(s);
    auto ns = new char[len+1];
    memcpy(ns, s, len+1);
    return ns;
}

class mystring
{
    char* str;

    public:

    mystring(const char* s)
    :str{clone_str(s)}
    {
       
    }

    mystring(const mystring& src)
    :str{clone_str(src.str)}
    {
        puts("Copy");
    }

    ~mystring()
    {
        delete [] str;
    }

    mystring& operator=(const mystring& src)
    {
        puts("=====");
        this->str = clone_str(src.str);
        return *this;
    }

    const char* data()const
    {
        return str;
    }

    mystring(mystring&& src)
    :str{src.str}
    {
        src.str = nullptr;
        puts("MOVE");
    }

    mystring& operator=(mystring&& src)
    {
        this->~mystring();
        str = src.str;
        src.str = nullptr;
        puts("MOVE=");
        return *this;
    }
};


class person
{
    mystring fn;
    mystring ln;

    public:

        person(const mystring& fn, const mystring& ln)
        :fn{fn},ln{ln}
        {
            puts("C1");
        }

        template<typename s1, typename s2>
        person(s1&& fn, s2&& ln)
        :fn{std::forward<s1>(fn)}, ln{std::forward<s2>(ln)}
        {

        }

        void show()const
        {
            printf("%s, %s \n", ln.data(), fn.data());
        }
};

int main()
{

    puts("*****************");

    mystring j = "Jhon";
    mystring s = "Snow";

    person p1{"Tyrion", "Liannyster"};
    auto p2 = p1;
    auto p3 = std::move(p1);

    p2.show();
    p3.show();

    person p4{j,s};
    p4.show();
}
