#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>
#include <map>
using namespace std;

template<typename R>
class DataBase
{
private:
    size_t lvls;
    map< size_t, vector<R> > shelf;

public:
    ~DataBase() { }

    DataBase(size_t incoming_size) : lvls{incoming_size}
    {
        // for(auto i = 0U; i < incoming_size; i++) shelf[i] = vector<R>{}; 
    }

    void db_enqueue(const size_t& priority, const R& value)
    {
        shelf[priority].push_back(value);
    }

    R db_dequeue()
    {
        R aux_r{};

        if(shelf.size() != 0)
        {
            aux_r = shelf[lvls - 1].back();
            shelf[lvls - 1].pop_back();
        }

        if(shelf[lvls - 1].size() == 0)
        {
            shelf.erase(lvls - 1);
            --lvls;
        }

        // for(size_t i = 0; i < lvls; i++)
        // {
        //     // cout << "not fade away\n";
        //     cout << shelf[i].size() << "\n";
        // }

        return aux_r;
    }

    bool db_is_empty()
    {
        return (shelf.size() == 0);
    }

};
//***************************************
template<typename T, size_t u>
class pq
{
private:
    DataBase<T> data_base{u};
    
public:
    pq() { }
    ~pq() { }

    template<typename TT>
    void enqueue(const size_t &priority, TT &&value)
    {
        data_base.db_enqueue(priority, forward<TT>(value));
    }

    bool is_empty()
    {
        return data_base.db_is_empty();
    }

    T dequeue()
    {
        return data_base.db_dequeue();
    }
};

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
        cout << r << "\n";
    }
}