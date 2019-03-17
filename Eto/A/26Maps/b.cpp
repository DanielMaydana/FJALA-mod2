// si la clave es un objeto se debe indicar como ordenar

#include <iostream>
#include <map>
#include <string>
using namespace std;

struct id
{
    int n;
    string c;
};

bool operator < (const id& a, const id& b)
{
    return tie(a.n, a.c) < tie(b.n, b.c);
}

int main()
{
    map<id, string> pp;
    pp.insert(make_pair(id{6854217, "CB"},"Mauricio Salazar"));
    pp[id{7384624, "PT"}] = "Omar Vera";
    pp[id{6347384, "CH"}] = "Pamela Alvares";

    for(auto& e : pp)
    {
        cout << e.first.n << " " << e.first.c << " " << e.second << "\n";
    }

    auto i2 = pp.find(id{6854217, "CB"});
    if(i2 == pp.end())
        cerr << "not fund\n";
    else
        cout << i2->second << "\n";

}