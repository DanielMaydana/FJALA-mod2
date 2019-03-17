#include <iostream>
#include <map>
#include <memory>
using namespace std;


class vehiculo
{
private:
    
public:
    vehiculo() { }
    ~vehiculo() { }
    virtual void mover() = 0;
};

class autom : public vehiculo
{
private:
    char ch;
public:
    autom() : ch{'j'}
    { }
    ~autom() { }
    void mover()override
    {
        cout << "se mueve\n";
    }
};

int main()
{
    map <string, unique_ptr<vehiculo>> vs;
    vs["4673GAD"] = make_unique<autom>();
    vs["9236TIU"] = make_unique<autom>();

    for(auto& e : vs)
    {
        cout << e.first << "\t";
        e.second->mover();
    }

}