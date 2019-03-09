#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

vector<string> m_illegalNamesWindows {"CON", "PRN", "AUX", "NUL", "COM1", "COM2", "COM3", "COM4", "COM5", "COM6", "COM7", "COM8", "COM9", "LPT1", "LPT2", "LPT3", "LPT4", "LPT5", "LPT6", "LPT7", "LPT8", "LPT9"};
vector<char> m_illegalCharacters {'>', '<', '/', '\\', '?', '|', '*'};

bool reviewIllegalName(const string& p_name)
{
    for(auto&e : p_name)
    {
        for(auto& ic : m_illegalCharacters)
        {
            if(e == ic)
            {
                return false;
            }
        }
    }

    for(auto& inw : m_illegalNamesWindows)
    {
        if(p_name == inw)
        {
            return false;
        }
    }

    if(p_name.find_first_not_of(' ') == std::string::npos)
    {
        return false;
    }

    if(p_name == "")
    {
        return false;
    }
    return true;
}

int main()
{
    vector<string> strs;
    // strs.push_back("   ");
    // strs.push_back("");
    // strs.push_back(">");
    // strs.push_back("BRMC");
    // strs.push_back("\\");
    // strs.push_back("/");
    // strs.push_back("|");
    strs.push_back("Bedouin Dress");
    // strs.push_back("?");
    // strs.push_back("*");
    // strs.push_back("    drink it /");
    // strs.push_back("COM9");
    // strs.push_back("LPT8");

    auto t_start = chrono::steady_clock::now();

    for(auto&f : strs)
    {
        if(reviewIllegalName(f) == true)
        {
            // cout << f << " *\n";
        }
    }

    auto t_finish = chrono::steady_clock::now();

    cout << chrono::duration_cast< chrono::microseconds >(t_finish - t_start).count() << " us\n";
}