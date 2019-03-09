#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
using namespace::placeholders;

void invertir(string& s)
{
    reverse(s.begin(), s.end());
    cout << "done! ";
}

int main()
{
    string x = "olumor";
    invertir(x);
    cout << x << "\n";

    string y = "zul";
    // auto my_inv = bind(invertir, y); // bind recibe copias de los parametros 
    auto my_inv = bind(invertir, ref(y)); // lo que hace es crear un reference wrapper
    my_inv();
    cout << y << "\n";
}