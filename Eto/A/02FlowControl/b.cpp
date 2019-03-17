#include <iostream>
using namespace std;

void p()
{
    int n = 8;
    do
    {
        cout << n-- << "\n";
    }
    while(n);
}




int main()
{
    p();
}