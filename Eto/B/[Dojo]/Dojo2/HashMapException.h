#ifndef HASHMAPEXCEPTION_H
#define HASHMAPEXCEPTION_H
#include <exception>
#include <string>
class HashMapException : public std::exception
{
    std::string msg;

  public:
    HashMapException(const std::string &msg);
    const char *what() const noexcept override;
};
#endif
