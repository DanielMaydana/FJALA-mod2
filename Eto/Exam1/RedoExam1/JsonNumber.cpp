#include "JsonNumber.h"
#include<iostream>
#include<string>

using namespace std;

JsonNumber::JsonNumber(int number) : number{number}
{ }

string JsonNumber::to_string()
{
    return std::to_string(number);
}

JsonNumber::~JsonNumber()
{ }