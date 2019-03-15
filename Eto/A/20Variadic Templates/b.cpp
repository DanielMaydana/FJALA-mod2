#include <iostream>
#include <string>
using namespace std;

string verifica(const string& value)
{
    return value;
}

string verifica(const int& value)
{ 
    return std::to_string(value);
}

string verifica(const char* value)
{
    return std::string{value};
}

template<typename S>
string join(const string& separator, const S& text) 
{
    return verifica(text);
}

template<typename P, typename...A>
string join(const string& sep, const P& p, const A&...args)
{
    return verifica(p) + sep + join(sep, args...);
}

int main()
{
    auto p = join("-", 2, 45, "rocks", "off", "dangerous", "they", "go", "home");
    cout << p << "\n";

    auto s = join(".", 8, "take", "s", "\n");
    cout << s;

    return 0;
}