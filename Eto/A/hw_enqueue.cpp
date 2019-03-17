#include <iostream>
#include <map>
#include <vector>
using namespace std;

template <typename R>
class DataBase
{

private:
    map<size_t, vector<R> *> dataBase;
    size_t size;

public:
    DataBase(size_t n) : size{0}
    {
        for (size_t i = 0U; i < n; i++)
        {
            dataBase[i] = new vector<R>;
        }
    }

    ~DataBase()
    {
        for (auto &i : dataBase)
        {
            delete i.second;
        }
    }

    template <typename TT> // es un nuevo template porque podria recibir const y no const
    void enqueue(size_t priority, TT &&value)
    //    void enqueue(size_t priority , const T& value)
    {
        auto it = dataBase.find(priority);
        if (it != dataBase.end())
        {
            it->second->push_back(forward<TT>(value));
            ++size;
        }
    }

    R dequeue()
    {
        size_t map_cursor = 0;
        R return_value;

        while (dataBase.size() > map_cursor)
        {
            auto it = dataBase.find(map_cursor);

            if (it->second->empty() == false)
            {
                map_cursor = dataBase.size();
                return_value = it->second->back();
                it->second->pop_back();
                size--;
                return return_value;
            }
            else
            {
                map_cursor++;
            }
        }
        return return_value;
    }

    bool is_empty()
    {
        return size == 0;
    }
};
//*************************************************
template <typename T, size_t n>
class pq
{

private:
    DataBase<T> db{n};

public:
    pq()
    { }

    ~pq()
    { }

    template <typename TT>
    void enqueue(size_t priority, TT &&value)
    //void enqueue(size_t priority , const T& value)
    {
        db.enqueue(priority, forward<TT>(value));
    }

    T dequeue()
    {
        return db.dequeue();
    }

    bool is_empty()
    {
        return db.is_empty();
    }
};
//*************************************************
int main()
{
    pq<string, 4> s;
    s.enqueue(2, "hello");
    s.enqueue(3, "world");
    s.enqueue(1, "friends");
    s.enqueue(0, "today");
    s.enqueue(0, "is");
    s.enqueue(0, "tuesday");
    s.enqueue(1, "of");
    s.enqueue(1, "c++");

    while (!s.is_empty())
    {
        auto r = s.dequeue();
        cout << r << "\t\t***\n";
    }
}