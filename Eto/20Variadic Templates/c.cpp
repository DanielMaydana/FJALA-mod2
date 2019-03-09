#include <iostream>
#include <string>
using namespace std;

struct doublePoint
{
    int x;
    int y;
};

class Smurfs
{
private:
    string p;

public:
    Smurfs(const string& s) : p{s}
    {
        cout << "Hi\n";
    }

    ~Smurfs() { }

    void show() const
    {
        cout << p << "\n";
    }
};

template <typename T, typename...ARGS>
T create_instance(const ARGS&...args)
{
    cout << "creating instance\n";
    return T{args...};
}

int main()
{
    auto double_pnt = create_instance<doublePoint>(10, 18);
    cout << double_pnt.x + double_pnt.y << "\n";

    auto greetings = create_instance<Smurfs>("greetings");
    greetings.show();
}