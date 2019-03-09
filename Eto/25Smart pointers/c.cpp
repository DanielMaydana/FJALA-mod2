// shared pointer 
    // tiene un costo mayor de operacion por el contador

    // caundo hay referencias crusadas de un padre a un hijo y a vicebersa no sirve usar shared pointers

#include <iostream>
#include <memory>

using namespace std;

class Int
{
private:
    int n;
public:
    Int(int n) : n{n}
     { }
    ~Int() 
    {
        cout << "Int deleted\n";
     }
};


int main()
{
    shared_ptr<Int> a {new Int{19}};
    auto b = make_shared<Int>(60);
    auto c = make_shared<Int>(88);
    auto d = a;
    
    b = make_shared<Int>(429);
    auto e = a;
    a = make_shared<Int>(8000);

}