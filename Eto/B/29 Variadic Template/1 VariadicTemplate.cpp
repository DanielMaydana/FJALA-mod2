#include <stdio.h>
#include <string>
#include <iostream>
/* 
    VARIADIC TEMPLATE
*/
template<class T, class U>
auto sum(const T& a, const U& b) // last step in the recursive execution // LAST
{
    return a + b;
}

template<class T, typename ...ARGS>
auto sum(const T& a, const ARGS& ...args) // MANY STEPS BEFORE THE LAST ONE
{
    return a + sum(args...); // PACK EXPANISON: args... 
}

int main()
{
    // funct(a, b1, b2, b3) // PARAMETER pack: bn
    std::cout << sum(1.4, 2) << "\n";
    std::cout << sum(1, 2, 3) << "\n";
    std::cout << sum(1, 2, 3.2, 4) << "\n"; 


}