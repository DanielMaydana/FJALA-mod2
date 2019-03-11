#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include <list>
#include <string>
#include <iostream>
// #include "JsonArray.h"
#include "IJsonUtilities.h"

using namespace std;

class JsonObject : public virtual IJsonUtilities
{
private:
    string stringified = "{}";
	list <std::pair<string, string> > objectFields;
    
public:
	~JsonObject();
	JsonObject();
    void add(string, string);
	void add(string, int);
	// void add(string, JsonArray);

	string to_string() override; 
};

#endif