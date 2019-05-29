#include <iostream>
#include <stdio.h>
#include <array>
using namespace std;

template<typename Container> 
void show(const Container& c) 
{
    // for(typename Container::const_iterator i = c.begin();
    // i != c.end(); ++i)
    for(auto& i : c)
    {
        // printf("%d\n", (*i)); // would only work with int  
        cout << i << "\n";
    }
}

int main()
{
    string s = "lanegan";

    show(s);

    // cout << s[11] << "\n"; // will print garbage if out of bounds
    // cout << s.at(11) << "\n"; // will throw an exception if out of bounds

    array<int, 5> arr;
    cout << size(arr) << "\n";
}