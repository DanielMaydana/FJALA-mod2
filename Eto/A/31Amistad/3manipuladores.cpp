// Manipuladores
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

template<size_t N>
ostream& stars(ostream& os) // custom manipulator
{
    for(size_t i = 0; i < N; i++)
    {
        os << "*";
    }
    return os;
}

struct dashes
{
public:
    int n;
    dashes(int n) : n{n}
    { }
    ~dashes() { }
    ostream& operator()(ostream& os)const
    {
        for(int i = 0; i < n; i++)
        {
            os << "-";
        }
        return os;
    }
};

ostream& operator << (ostream& os, const dashes& d)
{
    return d(os);
}

int main()
{
    int a = 88;
    cout << stars<2> << a << "\n";

    cout << dashes(6) << "mundo" << "\n";
    return 0;
}