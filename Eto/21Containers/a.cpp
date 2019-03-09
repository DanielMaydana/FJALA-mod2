// contienen 
    // array lists, linked list, maps

#include <iostream>
#include <array> // desde c++11
using namespace std;

template<typename T>
void print(const T& x)
{
    for(auto& i : x)
    {
        cout << i << "\n";
    }
}

int main()
{
    array<int, 6> x;  //es igual a int x[6], 6 tiene que ser conocido en tiempo de compilacion
    x[0] = 8;
    x[1] = 2;
    x[2] = 4;
    x[3] = 5;
    x[4] = 1;
    x[5] = 2;
    
    print(x);
}