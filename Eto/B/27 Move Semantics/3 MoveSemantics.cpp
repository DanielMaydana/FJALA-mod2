#include <stdio.h>
#include <utility>
#include <iostream>
#include<string>

using namespace std;

int main()
{
    string &&h = "luisitio comunica en algo";
    cout << h << "*\n";

    string r = move(h);

    cout << r << "*\n";
    cout << h << "*\n";
}