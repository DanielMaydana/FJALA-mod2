#include <iostream>
#include <string>
using namespace std;

template<typename T, typename TT>
auto sum(const T& a, const TT& b){

    return a + b;
}

template<typename U, typename ...ARGS>
auto sum(const U& a, const ARGS& ...args){

    return a + sum(args...);
}

int main()
{
    cout << sum(2.9, 8.1) << "\n";
    cout << sum(2, 9.5, 1) << "\n";
    cout << sum(3, 8, 15, 4, 2, 1) << "\n";
}