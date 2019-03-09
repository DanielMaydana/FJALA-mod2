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

istream& operator>> (istream& is, person& p)
{
    string line;
    getline(is, line); // para sacar una linea de texto
    if(is.fail()) return is;
    auto pos = line.find(";");
    if(pos == string::npos) throw 143;

    auto sid = line.substr(0, pos);
    auto name = line.substr(pos + 1);

    p.id = stoi(sid); // stoi string a entero
    p.name = name;

    return is;
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
        g << p << "\n"; // sobrecargar el operador << 
    }

    ifstream h{"people.txt"};
    if(h.fail()) return -1;

    vector <person> ps2;
    while(true)
    {
        person aux;
        h >> aux;
        if(h.fail()) break;
        ps2.push_back(aux);

        for(auto& p : ps2) cout << p << "\n";
    }

}