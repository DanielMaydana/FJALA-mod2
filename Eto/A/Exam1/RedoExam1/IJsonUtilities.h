#ifndef IJSONUTILITIES_H
#define IJSONUTILITIES_H

#include<string>

using namespace std;

class IJsonUtilities
{
public:

	virtual ~IJsonUtilities()
	{ }
	
	virtual string to_string() = 0;
};

#endif