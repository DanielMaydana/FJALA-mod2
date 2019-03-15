#include <iostream>
using namespace std;


class Singleton
{
private:
    // static Singleton* p = nullptr;
    static Singleton* p;
    
    Singleton()  //constructor privado para que no se instancie objetos de esta clase
    { 
        cout << " create instance\n";
    }
public:
    ~Singleton() { }

    void hi()const {cout << "hello\n";}

    static Singleton* instance()
    {
        if(p == nullptr)
            p = new Singleton();
        return p;
    }
};

Singleton* Singleton::p = nullptr;

int main()
{
    Singleton::instance()->hi();
    Singleton::instance()->hi();


}



