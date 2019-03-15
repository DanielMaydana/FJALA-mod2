#include <iostream>
#include <string>
using namespace std;

template<typename PROC, typename...ARGS>
auto invoke(PROC p, const ARGS&...args)
{
    cout << "invoking\n";
    return p(args...);
}

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    cout << invoke(std::to_string, 15) << "\n";
    auto z = invoke(sum, 6, 8);
}