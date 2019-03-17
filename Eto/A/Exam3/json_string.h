#pragma once

#include<iostream>
#include<string>
using namespace std;

class json_string
{
private:
    string str;
public:

    json_string(const char* str_x)
    {
        str = str_x;
        string str_aux = "\"";

        for(size_t ii = 0; ii < str.length(); ii++ )
        {
            if(str[ii] == '\"')
            {
                str_aux += "\\\"";
            }
            else str_aux += str[ii];
        }
        str_aux += "\"";
        str = str_aux;
    }

    json_string(const string& str_x)
    {
        str = str_x;
        string str_aux = "\"";

        for(size_t ii = 0; ii < str.length(); ii++ )
        {
            if(str[ii] == '\"')
            {
                str_aux += "\\\"";
            }
            else str_aux += str[ii];
        }
        str_aux += "\"";
        str = str_aux;
    }

    ~json_string() { }

    string to_string()
    {
        return str;
    }

    void operator=(const char& str_x)
    {
        str = str_x;
    }
};
