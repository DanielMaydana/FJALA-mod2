// RTTI  run time type Information
// dynamic cast es parte de RTTI porque en timepo de ejecusion realiza el casteo

//typeid type_info 

#include <iostream>
#include <typeinfo>
using namespace std;

struct FundacionJala
{

};

int main()
{
    int p = 8, q = 9;
    if (typeid(p) == typeid(q))
        cout << "typeids are iqual\n";

    double qq = 123.8;
    if(typeid(qq) == typeid(double))
        cout << "is a double\n";

    auto pp = new FundacionJala();
    const type_info& ti = typeid(pp);
    cout << ti.name() << "\n";
}
