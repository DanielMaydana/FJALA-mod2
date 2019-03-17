#include <iostream>
using namespace std;


namespace a
{
    namespace b
    {
        namespace c
        {
            void D ()
            {
                cout << "Nested DDD\n";
            }

        }
        void E()
        {
            cout << "EEE\n";
        }
    }
}

namespace x::y::z
{
    void W()
    {
        cout << "WWW\n";
    }
}
// using namespace a::b::c;  //parece no tener ningun efecto pporque lo ponemos?
int main()
{
    a::b::c::D();
    a::b::E();

    x::y::z::W();
}