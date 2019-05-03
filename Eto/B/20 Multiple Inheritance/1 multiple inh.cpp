#include <iostream>
#include <string>
using namespace std;
struct A{
    int x;
};

struct B{
    int y;
};

struct Punto: A,B {
    void mostrar(){
        printf("%d, %d\n", x,y);
    }
};


class Base1
{
private:
    int n;
public:
    Base1(int n):n{n}{}

    int get_n()const{
        return n;
    }

    //~Base1();
};

class Base2
{
private:
    std::string str;
public:
    Base2(const std::string &str):str{str}{

    }
    const std::string &get_str()const{
        return str;
    }
};

//class Derived:public Base1, public Base2
class Derived:private Base1, private Base2
{
public:
    Derived(int ci, const std::string &name):Base1{ci},Base2{name}{
    }

    void print()const{
        printf("%d, %s\n", get_n(), get_str().data());
    }
};




int main()
{
/*     Punto p;
    p.x=2;
    p.y=3;
    p.mostrar();
*/

    Derived d{132131,"sdsdsd"};
    d.print();
    
    return 0;
}