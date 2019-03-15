#if !defined(JSONSTRING_H)
#define JSONSTRING_H

#include <string>
#include "IJsonUtilities.h"

using namespace std;

class JsonString : public virtual IJsonUtilities
{
public:
    ~JsonString();
    JsonString(const char*);

    string to_string() override;

private:
    string stringified;
};

#endif // JSONSTRING_H
