// insert => o(0) + rehash
// busqueda => 

#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <chrono>
#include <random>

using namespace std;

int main()
{
    unordered_map<int, string> ns;
    ns[0] = "cero";
    ns[10] = "diez";
    ns[20] = "veinte";
    ns[30] = "trenta";
    ns[40] = "cuarenta";

    for(auto& e : ns)
        cout << e.first << " " << e.second << "\n";
}
