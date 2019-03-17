#pragma once

#include <fstream>
#include <iostream>
using namespace std;

template<typename T>
class file_lists
{
private:
    std::string f_name;
    fstream data;
    fstream lists;
    fstream indexes;

public:
    file_lists(const std::string& f_name)
    : lists{s + ".lst", ios::in | ios::out | ios::ate | ios::binary},
    indexes{s + ".idx", ios::in | ios::out | ios::ate | ios::binary},
    data{s + ".dat", ios::in | ios::out | ios::ate | ios::binary}
    { }

    ~file_lists() { }

    long long get_new_list()
    {
        lists.seekp(0, ios::end)
        long long pos = lists.tellp();
    }

};