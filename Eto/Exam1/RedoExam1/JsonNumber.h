#ifndef JSONNUMBER_H
#define JSONNUMBER_H

#include "IJsonUtilities.h"

class JsonNumber : public virtual IJsonUtilities
{
    
public:
    int number;

	JsonNumber(int number);
	~JsonNumber();

	string to_string() override; 


private:

};

#endif