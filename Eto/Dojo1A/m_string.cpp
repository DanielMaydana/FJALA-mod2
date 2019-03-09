#include "m_string.h"

m_string::m_string(const char* s)
:len{strlen(s)}
{
    str = (char*)malloc(len+1);
    memcpy(str, s, len+1);
}

m_string::m_string(const m_string& s)
:len{s.len}, str{(char*) malloc(s.len+1)}
{
    memcpy(str, s.str, len+1);
}

m_string::~m_string()
{
    free(str);
}

m_string& m_string::operator = (const m_string& s)
{
    if(this == &s) 
        return *this;
    
    this->~m_string();
    len = s.len;
    str = (char*) malloc(len+1);
    memcpy(str, s.str, len+1);
    return *this;
}

const char* m_string::get_str() const
{
    return str;
}