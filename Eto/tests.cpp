#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>

using namespace std;

class Exception : public std::exception
{
protected:
    std::string msg;
public:

    Exception()
    { }

    Exception(const char* message) : msg(message)
    { }

    Exception(const string message) : msg(message)
    { }

    ~Exception() throw() {}

    const char *what() const throw()
    {
        // return "User 'roberto' is not logged into the system";
        return msg.c_str();
    }
};

int main()
{
    //////////////////MAPS//////////////////
    // std::map< int, std::string > my_map;
    // for(int i = 0; i < 5; i++) my_map[i] = std::to_string(i);

    // std::cout << my_map.size() << "\n";
    // for(int i = 0; i < 10; i++) my_map.erase(i);
    // std::cout << my_map.size() << "\n";

    // for(int i = 0; i < 6; i++)
    // {
    //     std::string aux = std::to_string(i);
    //     my_map[i] = aux;
    // }
    // std::cout << my_map.size() << "\n";
    //////////////////EXCEPTION//////////////////
    try
    {
        string name = "juan";
        throw Exception{"User \'" + name + "\' is not logged into the system"};
    }
    catch (const exception& ex)
    {
            string s = ex.what();

            if(s == "User 'juan' is not logged into the system")
            cout << s << " this was throwed\n";
    }

}