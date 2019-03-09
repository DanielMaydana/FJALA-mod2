#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"json_bool.h"
#include"json_number.h"
#include"json_string.h"
#include"json_object.h"
using namespace std;

class json_array
{
private:
    string str;
    vector<string> j_objects;

public:
    json_array() { }
    ~json_array() { }

    json_array& add(const bool& to_add)
    {
        j_objects.push_back(json_bool{to_add}.to_string());
        return *this;
    }

    json_array& add(const int& to_add)
    {
        j_objects.push_back(json_number{to_add}.to_string());
        return *this;
    }

    json_array& add(const char* to_add)
    {
        j_objects.push_back(json_string{to_add}.to_string());
        return *this;
    }

    json_array& add(const string& to_add)
    {
        j_objects.push_back(json_string{to_add}.to_string());
        return *this;
    }

    json_array& add(json_object& j_ob)
    {
        j_objects.push_back(j_ob.to_string());
        return *this;
    }

    string to_string()
    {
        str = "[";
        for(auto& e : j_objects)
        {
            str += e;
            if(e != j_objects.back()) str += ", ";
        }
        str += "]";
        return str;
    }
};