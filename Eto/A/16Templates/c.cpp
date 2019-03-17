// POD: Plain Old Data
    // un valor de tipo primitivo, un array de PODs, un struct de PODs, una clase con atributos PODs

// si no se concoce el tipo de dato no es una buena idea utilizar malloc y calloc

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;  


// template <class T>
// class ArrayList
// {
// private:
//     T* items;
//     size_t n;
// public:
//     ArrayList()
//     :items{static_cast<T*>(malloc(0))}, n{0}
//     { }

//     ~ArrayList() 
//     {
//         free(items);
//     }

//     ArrayList<T>& add(const T& x)
//     {
//         items = static_cast<T*>(realloc(items, (n+1)*sizeof(T)));
//         items[n++] = x;
//         return *this;
//     }

//     void show() const
//     {
        
//         for(size_t i = 0; i < n; i++)
//         {
//             cout << items[i] << "\n";
//         }
        
//     }
// };


// struct PoormanInt
// {
//     int* n;
//     PoormanInt(int p)
//     :n{new int{p}}
//     {}

//     ~PoormanInt()
//     {
//         delete n;
//     }
// };



// int main()
// {
//     ArrayList<int> p;  // al declarar instancias de clases se le debe pasar el tipo de dato <int> por que el compilador no puede deducir el tipo
//     p.add(5).add(8).add(15).add(25).add(40).show();

//     ArrayList<double> q;
//     q.add(23.52).show();

//     ArrayList<string> r;
    
//     for(size_t i = 0; i < 1000; i++)
//     {
//         r.add(std::to_string(i) + "hola");
//     }
//     r.show();
//     // r.add("adfhdfhasdghsadfbhdh").add("sdkjfgbskldjfbgskldjf").add("kahdsbjasbhjasbghjdfsvg").add("aegasdfhasdhsghsgfh").show();

//     ArrayList<PoormanInt> z;
    
//     for(size_t i = 0; i < 100000000; i++)
//     {
//         z.add(i*17);
//     }
//     // z.show();

// }



template <class T>
class ArrayList
{
private:
    T* items;
    size_t n;
    size_t cap;

    void resize()
    {
        if(n < cap)
            return;
        
        auto ncap = cap * 2;
        auto nitems = new T[ncap];
        
        for(size_t i = 0U; i < n; i++)
        {
            nitems[i] = items[i];  //hay que tener cuidado porque no sabemos que hara el oprador = si se tienen una clase
        }
        delete[] items;
        items = nitems;
        cap = ncap;
    }

public:
    ArrayList()
    :items{new T[4]}, n{0}, cap{4}
    { }

    ~ArrayList() 
    {
        delete [] items;
    }

    ArrayList<T>& add(const T& x)
    {
        resize();
        items[n++] = x;
        return *this;
    }

    void show() const
    {
        
        for(size_t i = 0; i < n; i++)
        {
            cout << items[i] << "\n";
        }
        
    }
};


struct PoormanInt
{
    int* n;
    PoormanInt(int p)
    :n{new int{p}}
    {}

    PoormanInt()
    :n{nullptr}
    {}

    ~PoormanInt()
    {
        delete n;
    }

    void operator = (const PoormanInt& s)
    {
        delete n;
        n = new int{*(s.n)};
    }
};



int main()
{
    ArrayList<int> p;  // al declarar instancias de clases se le debe pasar el tipo de dato <int> por que el compilador no puede deducir el tipo
    p.add(5).add(8).add(15).add(25).add(40).show();

    ArrayList<double> q;
    q.add(23.52).show();

    ArrayList<string> r;
    
    for(size_t i = 0; i < 1000; i++)
    {
         r.add(std::to_string(i) + "hola");
    }
    r.show();
    // r.add("adfhdfhasdghsadfbhdh").add("sdkjfgbskldjfbgskldjf").add("kahdsbjasbhjasbghjdfsvg").add("aegasdfhasdhsghsgfh").show();

    ArrayList<PoormanInt> z;
    
    for(size_t i = 0; i < 1000; i++)
    {
        z.add(i*17);
    }
    //z.show();

}
