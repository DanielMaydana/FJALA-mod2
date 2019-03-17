#if !defined(JSONARRAY_H)
#define JSONARRAY_H

#include <list>
#include <string>
#include "JsonObject.h"
#include "IJsonUtilities.h"

using namespace std;

class JsonArray : public virtual IJsonUtilities
{
private:
    list<string> arrayFields;
    string stringified = "[]";
    
public:
    ~JsonArray();
    JsonArray();

    void add(string);
    void add(int);
    void add(JsonObject);

    string to_string() override;
};

#endif
