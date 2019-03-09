// Dread diamond problem

#include <iostream>
using namespace std;


struct J
{
    int p;
};


struct K1 : J
{
    void print()
    {
        cout << p << "\n";
    }
};


struct K2 : J
{
    void show()
    {
        cout << p << "\n";
    }
};


struct L : K1, K2
{
    
};




int main()
{
    L ins;
    // ins.p = 18;  // genera ambiguedad por que no sabe a que p se refiere
    ins.K1::p = 18;
    ins.K2::p = 25;
    ins.print();
    ins.show();
}