#ifndef M_STRING
#define M_STRING
#include <cstring>
#include <cstdlib>
// #include <iostream>
using namespace std;


class m_string
{
private:
    size_t len;
    char* str;
public:
    m_string(const char* s = "");
    m_string(const m_string& s);
    ~m_string();
    m_string& operator = (const m_string& s);
    const char* get_str() const;
};

#endif