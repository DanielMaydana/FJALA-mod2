#pragma once

#include<iostream>
#include<vector>
#include"json_bool.h"
#include"json_number.h"
#include"json_string.h"
#include"json_array.h"

using namespace std;

class json_object
{
private:
    string str;
    vector<string> elements;
public:
    json_object() { }

    ~json_object() { }

    json_object& add(const string& key, const string& value)
    {
        json_string js_str_key(key);
        json_string js_str_value(value);
        elements.push_back(js_str_key.to_string() + " : " + js_str_value.to_string());
        return *this;
    }

    json_object& add(const string& key, const int& value)
    {
        json_string js_str_key(key);
        json_number js_str_value(value);
        elements.push_back(js_str_key.to_string() + " : " + js_str_value.to_string());
        return *this;
    }

    void add(const string& key, json_array& j_arr)
    {
        elements.push_back((json_string{key}).to_string() + " : " + j_arr.to_string());
        // return *this;
    }

    // void add(const string& key, json_object& j_obj)
    // {
    //     elements.push_back((json_string{key}).to_string() + " : " + j_obj.to_string());
    // }

    string to_string()
    {
        str = "{ ";
        for(auto& e : elements)
        {
            str += e;
            if(e != elements.back()) str += ",";
            str += " ";
        }
        str += "}";
        return str;
    }
};