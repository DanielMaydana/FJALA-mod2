#include <iostream>
#include <string>
using namespace std;  

template <int N, char K> //solo finciona con int (y sus similares) y booleanos 
void print()
{
    for(int i = 0; i < N; i++)
    {
        cout << K;
    }
    cout <<"\n";
}

int main()
{
    print<6, '*'>();   
    print<10, '#'>();

    constexpr int n = 5;  // esto hace que n sea conocido en tiempo de compilacion de otra forma no funcionaria 
    print<n, 'A'>();
}