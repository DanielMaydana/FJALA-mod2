#include "JsonArray.h"

JsonArray::~JsonArray()
{ }

JsonArray::JsonArray()
{ }

void JsonArray::add(string value)
{
    arrayFields.push_back("\"" + value + "\"");
}

void JsonArray::add(int value)
{
    arrayFields.push_back(std::to_string(value));    
}

void JsonArray::add(JsonObject object)
{
    arrayFields.push_back(object.to_string());
}

string JsonArray::to_string()
{
    if(arrayFields.size())
    {
        stringified = "[";
        for(auto it : arrayFields)
        {
            stringified += it + ", ";
        }

        stringified = stringified.substr(0, stringified.length() - 2);

        stringified += "]";
    }
    return stringified; 
}