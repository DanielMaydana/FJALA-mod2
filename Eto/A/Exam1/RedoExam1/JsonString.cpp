#include "JsonString.h"
JsonString::~JsonString()
{
    
}

JsonString::JsonString(const char* value)
{
    stringified = string(value);
}

string JsonString::to_string()
{
    return "\"" + stringified + "\"";
}