#include <iostream>
using namespace std;


// struct P
// {
    
//     int n;
// };


// struct Q1 : virtual P{};
// struct Q2 : virtual P{};
// struct R :  Q1, Q2{};



// en este caso se debe llamar a todos los constructores para romper ambiguedad

struct BF
{
    int n;
    BF(int n)
    :n{n}
    {}
};


struct A : virtual BF
{
    A( ) 
    : BF{888} 
    {}

};

struct B : virtual BF
{
    B( ) 
    : BF{111} 
    {}

};

struct C : A, B
{
    C() 
    : BF {456} 
    {}
};


int main()
{
    C c;
    cout << c.n << "\n";
}

