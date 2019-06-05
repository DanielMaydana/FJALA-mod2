#include <iostream>
#include <stdio.h>
#include <string>

template <typename T>
struct deleter
{
    void release(T *new_t)
    {
        puts("deleting T");
        delete new_t;
    }
};

template <>
struct deleter<char>
{
    void release(char *char_star)
    {
        free(char_star);
    }
};

template <typename T, typename Del = deleter<T>>
class Wrapper
{
    T *val;

public:
    Wrapper(T *val) : val{val}
    {
    }

    ~Wrapper()
    {
        Del d;
        d.release(val);
        puts("bye Wrapper");
    }

    const T &get() const
    {
        return *val;
    }
};

struct Ztrings
{
    std::string str;

    Ztrings(const std::string &str) : str{str}
    {
    }

    ~Ztrings()
    {
        puts("bye Ztrings");
    }
};

int main()
{
    Wrapper<Ztrings> wr1{new Ztrings{"miles"}};
    std::cout << wr1.get().str << "\n";
}