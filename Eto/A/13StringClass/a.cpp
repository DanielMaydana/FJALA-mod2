#include <iostream>
#include <string>
using namespace std;






int main()
{
    string h = "hello";
    string w{"world"};
    string hw = h + " " + w;
    cout << hw << "\n";
    wstring hh = L"hola";
    wstring ww = L"mundo";
    wstring hhww = hh + L" " + ww;
    wcout << hhww << "\n";
}