// especializacion total
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


template <typename T>
class Container
{
private:
    T value;
public:
    Container(const T& x)
    :value{x}
    { }

    ~Container() { }

    const T& get() const
    {
        return value;
    }
};

template<>
class Container<FILE*>
{
private:
    FILE* f;
public:
    Container(const char* fn, const char* om)
    :f{fopen(fn, om)}
    { 
        cout << "file opened \n";
    }

    ~Container() 
    {
        cout << "file closed\n";
        fclose(f);
    }

    void puts(const char* s)
    {
        cout << "file edited\n";
        fputs(s, f);
    }
};

template <typename T>
class Container<T*>  // es esta la especializacion completa???
{
private:
    T* p;

public:
    Container(T* p)
    :p{p} 
    { 
    }
    
    ~Container() 
    {
        cout << "bye container\n";
        delete p;
    }

    const T& get() const
    {
        return *p;
    }

    const T* operator -> () const // al sobrecargar -> se vuelve un smart poiter 
    {
        return p;
    }

};

struct Z
{
    ~Z()
    {
        cout << "bye Z\n";
    }

    void salute()const
    {
        cout << "Luadamus te Vernis\n";
    }
};

int main()
{
    Container<int> p{5};
    Container<int> q{18};
    cout << p.get() + q.get() << "\n";

    Container<string> s{"hello"};
    cout << s.get() << "\n";

    // Container<FILE*> f{fopen("a.txt", "w")};
    // fputs("hello", f.get());
    // fclose(f.get());
    Container<FILE*> f{"b.txt", "w"};
    f.puts("hello Friday");

    Container<Z*> y{new Z()};
    y.get().salute();
    y->salute();

}

