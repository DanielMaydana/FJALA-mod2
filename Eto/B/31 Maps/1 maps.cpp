#include <map>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // unordered_map<string, int> ss;
    map<string, int> ss;

    ss.insert(pair<string, int> {"one", 1});
    ss.insert(pair<string, int> {"two", 2});

    ss.insert(make_pair("two", 2));

    ss["three"] = 3; // if the key is new 
    ss["four"] = 4;
    ss["five"] = 5;

    for(auto& p : ss)
    {
        cout << p.first << "\t" << p.second << "\n";
    }

    // to find don't use : ss["six"] instead use
    auto it = ss.find("four");

    if(it == ss.end()) cerr << "NOT FOUND\n";
    else cout << it->second << "\n";
}