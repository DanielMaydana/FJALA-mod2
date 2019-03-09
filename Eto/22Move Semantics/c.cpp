#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
// #include "ctime"
using namespace std;


class Fatty
{
private:
    char* p;
public:
    Fatty(char k) 
    { 
        p = new char[1000000];
        for(int i = 0; i < 1000000; i++)
        {
            p[i] = k;
        }
    }

    Fatty(const Fatty& src)
    {
        p = new char[1000000];
        for(int i = 0; i < 1000000; i++)
        {
            p[i] = src.p[i];
        }
    }

    Fatty(Fatty&& src) : p{src.p}
    {
        src.p = nullptr;
    }

    Fatty& operator = (Fatty&& src)
    {
        // cout << "Fatty operator =\n";
        delete[] p;
        p = src.p;
        src.p = nullptr;
        return *this;
    }

    Fatty& operator=(const Fatty& src)
    {
        cout << "Fatty const operator =\n";
        delete[] p;
        p = new char[1000000];
        for(int i = 0; i < 1000000; i++)
            p[i] = src.p[i];
        return *this;
    }

    ~Fatty() 
    { 
        delete [] p;
    }
};

template <typename T>
void swp(T& a, T& b)
{
    T aux = move(a);
    a = move(b);
    b = move (aux);
}

int main()
{
    Fatty a{'x'};
    Fatty b{'y'};
    auto z = clock();
    for(int i = 0; i < 10000000; i++)
    {
        swp(a, b);
    }

    auto z1 = clock();
    cout << (z1 - z) << "\n";
}