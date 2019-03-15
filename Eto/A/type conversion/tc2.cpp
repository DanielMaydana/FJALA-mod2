#include <iostream>
using namespace std;


class Dummy
{
private:
    double i, j;
public:
    Dummy() { }
    ~Dummy() { }
};


class Addition
{
private:
    int x, y;
public:
    Addition(int a, int b) 
    :x{a}, y{b}
    {}
    ~Addition() { }

    int result()
    {
        return x + y;
    }
};

int main()
{
    Dummy d;
    Addition* padd;
    padd = (Addition*) &d;
    cout << padd->result();
    return 0;
}