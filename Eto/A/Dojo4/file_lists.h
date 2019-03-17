#pragma once
#include <fstream>
#include <string>
#include "list_info.h"
#include "index_info.h"
#include <optional>
using namespace std;

template <typename T>
class file_lists
{
// private:
    mutable fstream lists;
    mutable fstream indexes;
    mutable fstream data;

public:
    file_lists(const string &s)
        : lists{s + ".lst", ios::in | ios::out | ios::ate | ios::binary},
        indexes{s + ".idx", ios::in | ios::out | ios::ate | ios::binary},
        data{s + ".dat", ios::in | ios::out | ios::ate | ios::binary}
    {
        // const char* ss = "hola";
        // lists.write(ss, 5);
        // lists.seekg(0);
        // char m[10];
        // lists.read(m, 5);
        // cout << m <<"\n";
    }

    long long get_new_list()
    {
        lists.seekp(0, ios::end);
        long long pos = lists.tellp();
        list_info linfo;

        lists.write(reinterpret_cast<const char *>(&linfo), sizeof(list_info));
        cout << "list posicion: " << pos << '\n';
        return pos;
    }

    long long add_element(const T &elem)
    {
        data.seekp(0, ios::end);
        long long pos = data.tellp();
        data.write(reinterpret_cast<const char *>(&elem), sizeof(T));
        return pos;
    }

    void push_back(long long list, const T &elem)
    {
        long long pos_data = add_element(elem);
        cout<<"Data possicion: "<<pos_data<<'\n';
        list_info aux = get_list_info(list);
        long long pos_item = add_index(pos_data, -1);
        if (aux.first == -1)
        {
            aux.first = pos_item;
            aux.last = pos_item;
            cout << aux.last << " entro \n";
            set_list_info(aux, list);
        }
        else
        {
            index_info last_index = get_index(aux.last);
            last_index.next = pos_item;
            set_index_info(aux.last, last_index);
            aux.last = pos_item;
            set_list_info(aux, list);
        }
    }
    void push_front(long long list, const T &elem)
    {
        long long pos_data = add_element(elem);
        cout<<"Data possicion: "<<pos_data<<'\n';
        list_info aux = get_list_info(list);
        long long pos_item = add_index(pos_data, aux.first);
        if (aux.first == -1)
        {
            aux.first = pos_item;
            aux.last = pos_item;
            cout << aux.last << " entro \n";
            set_list_info(aux, list);
        }
        else
        {
            aux.first = pos_item;
            set_list_info(aux, list);
        }
    }

    template<typename PRED>
    void iterate(long long list, PRED pred) const
    {
        list_info info;
        info = get_list_info(list);
        long long aux = info.first;
        while(aux != -1){
            index_info index = get_index(aux);
            T p = get_dato(index.data_pos);
            pred(p);
            aux = index.next;
        }
    }

    optional<T> find(long long list, const T& object) const
    {
        list_info info;
        info = get_list_info(list);
        long long aux = info.first;
        while(aux != -1){
            index_info index = get_index(aux);
            T p = get_dato(index.data_pos);
            if(object== p)
                return optional(p);
            aux = index.next;
        }
        return optional<T>{};
    }

    T get_dato(long long value) const
    {
        data.seekg(value, ios::beg);
        T aux;
        data.read(reinterpret_cast<char *>(&aux), sizeof(T));
        return aux;
    }

  private:
    list_info get_list_info(long long pos) const
    {
        lists.seekg(pos, ios::beg);
        list_info aux;
        lists.read(reinterpret_cast<char *>(&aux), sizeof(list_info));
        return aux;
    }
    long long add_index(long long post_data, long long next)
    {
        indexes.seekp(0, ios::end);
        long long pos = indexes.tellp();
        index_info info = {post_data, next};
        indexes.write(reinterpret_cast<const char *>(&info), sizeof(index_info));
        return pos;
    }

    void set_list_info(const list_info &info, long long list)
    {
        lists.seekp(list, ios::beg);
        cout<<"info: "<<info.first<<'\n';
        cout<<"info: "<<info.last<<'\n';

        lists.write(reinterpret_cast<const char *>(&info), sizeof(list_info));
    }

    index_info get_index(long long index) const
    {
        indexes.seekg(index, ios::beg);
        index_info aux;
        indexes.read(reinterpret_cast<char *>(&aux), sizeof(index_info));
        return aux;
    }

    void set_index_info(long long last, const index_info& info)
    {

        indexes.seekp(last, ios::beg);
        cout<<"info: "<<info.data_pos<<'\n';
        cout<<"info: "<<info.next<<'\n';

        indexes.write(reinterpret_cast<const char *>(&info), sizeof(index_info));
    }
    
};
