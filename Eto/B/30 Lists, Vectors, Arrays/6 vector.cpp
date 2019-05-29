#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <memory>
#include <array>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> ints;

    for(size_t i = 0; i < 1'000'000; ++i)
    {
        ints.push_back(i);
    }

    auto pos = find(ints.begin(), ints.end(), 999'999); // returns an iterator if found

    if(pos == ints.end())
    {
        cerr << "not found" << "\n";
    }
    else
    {
        cout << *pos << "\n";
    }
}