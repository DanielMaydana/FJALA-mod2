#pragma once

#include<iostream>
#include<string>
using namespace std;

class json_number
{
private:
    int n;
public:
    json_number(const int& n) : n{n}
    { }
    ~json_number() { }

    string to_string()
    {
        return std::to_string(n);
    }
};