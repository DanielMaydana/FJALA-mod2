#pragma once

#include<iostream>
#include<string>
using namespace std;

class json_bool
{
private:
    bool b;
public:
    json_bool(const bool& b) : b{b}
    { }
    ~json_bool() { }

    string to_string()
    {
        if(b) return "true";
        else return "false";
    }
};