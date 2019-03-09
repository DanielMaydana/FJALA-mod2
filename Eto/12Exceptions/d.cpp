#include <iostream>
using namespace std;


struct Exception
{
    int err;

    ~Exception()
    {
        cout << "Exception instance bye\n";
    }

    void print() const
    {
        cerr << "error code " << err << "\n";
    }
};

void x()
{
    cout << "function x called\n";
    // throw new Exception{125};
    throw Exception{125};
}

int main()
{
    
    try
    {
        x();
    }
    // catch(const Exception* e)
    catch(const Exception& e)
    {
        // e->print();
        // delete e;
        e.print();
    }
    
}
