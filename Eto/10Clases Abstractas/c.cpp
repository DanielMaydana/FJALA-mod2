#include <iostream>
using namespace std;


void p()
{
    static int n = 5;  // al marcar con static la variable se vuelve como globar pero solo se puede acceder a traves de el metodo p
    cout << n++ << "\n";
}


int main()
{
    p();
    p();
    p();
    p();
    p();
}