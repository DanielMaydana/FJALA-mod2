// Casting Operators
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct person
{
    int id;
    string name;
};

ostream& operator<< (ostream& os, const person& p)
{
    os << p.id << ";" << p.name <<"\n";
    return os;
}

int main()
{
    // cout << "hola\n"; // cout es ostream
    // ofstream f{"archivo.txt"};

    // if(!f.good())
    // {
    //     cerr << "error\n";
    //     return -4;
    // }

    // vector<string> ss = {"omar", "boris", "pato"};

    // for(auto& i : ss)
    // {
    //     f << ss << "\n";
    // }

    ///////////////////////////////////////////////////////////
    vector<person> ps;
    ps.push_back({1, "Peter Gabriel"});
    ps.push_back({8, "Jim James"});
    ps.push_back({16, "Ada Jones"});

    ofstream g{"people.txt"};
    for(auto& p : ps)
    {
        g << p << "\n";
    }

}