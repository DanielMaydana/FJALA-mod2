#include <iostream>
using namespace std;


int mul(int,int); //prototipo
int main()
{
    int r = mul(14, 5);
    cout << r << "\n";
}

int mul(int a, int b)
{
    return a * b;
}
