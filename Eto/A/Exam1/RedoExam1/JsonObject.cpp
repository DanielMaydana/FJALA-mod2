#include "JsonObject.h"

JsonObject::~JsonObject()
{ }

JsonObject::JsonObject()
{ }

void JsonObject::add(string key, string value)
{
    objectFields.push_back(make_pair(string("\"" + key + "\""), string("\"" + value + "\"")));
}

void JsonObject::add(string key, int value)
{
    objectFields.push_back(make_pair(string("\"" + key + "\""), std::to_string(value)));
}

// void JsonObject::add(string key, JsonArray array)
// {
//     objectFields.push_back(make_pair(string("\"" + key + "\""), array.to_string()));
// }

string JsonObject::to_string()
{
    if(objectFields.size() > 0)
    {
        stringified = "{ ";
        list<string, string>::iterator copy;

        for(auto it = objectFields.begin(); it != objectFields.end(); ++it)
        {
            stringified += it->first + ": " + it->second;

            stringified += ", ";
        }

        stringified = stringified.substr(0, stringified.length() - 2);
        stringified += " }";
    }

    return stringified;
}