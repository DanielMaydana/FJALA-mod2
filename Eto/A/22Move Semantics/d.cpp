#include <iostream>
#include <map>
#include <vector>
using namespace std;

template<typename T>
class DataBase
{
private:
    map<size_t, vector<T>* > dataBase;
    size_t size;
public:
    DataBase() 
    :size{0}
    { }

    ~DataBase() { }

    void initialize(size_t n)
    {
        for(size_t i = 0U; i < n; i++)
        {
            //dataBase[i] = new vector<T>;
            dataBase[i] = new vector<T>;
        }
    }

    void enqueue(size_t priority , const T& value)
    {
        // map<size_t, vector<T>*>::iterator it;
        auto it = dataBase.find(priority);

        if(it != dataBase.end())
        {
            // cout << it -> second << "\n";
            it -> second -> push_back(value);
            ++size;
        }
        // dataBase.find(priority)->s
        
    }

    T dequeue()
    {
        size_t map_cursor = 0;
        
    }

    bool is_empty()
    {
        return size == 0;
    }
};

template <typename T, size_t n>
class pq
{
private:
    DataBase<T> db;

public:
    pq() 
    { 
        db.initialize(n);
    }

    ~pq() { }

    void enqueue(size_t priority , const T& value)
    {
        db.enqueue(priority, value);
    }

    T dequeue()
    {
        db.dequeue();
    }
    
    bool is_empty()
    {
        return db.is_empty();
    }
};

int main()
{
    pq <string, 4> s;
    s.enqueue(2, "hello");
    s.enqueue(3, "world");
    s.enqueue(1, "friends");
    s.enqueue(0, "today");
    s.enqueue(0, "is");
    s.enqueue(0, "tuesday");
    s.enqueue(1, "of");
    s.enqueue(1, "c++");
    cout << s.is_empty() << "\n";

    while(!s.is_empty)
    {
        auto r = s.dequeue();
        cout << r << "\n";
    }
}