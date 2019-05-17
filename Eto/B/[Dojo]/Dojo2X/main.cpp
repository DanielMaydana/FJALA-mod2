#include <cstdio>
#include <ctime>
#include <string>
#include <iostream>
#include <exception>

using namespace std;

// --------CLASSES_&_STRUCTS--------

class HMException : public exception
{
    string msg;
    
    public:

    HMException(const string& msg) : msg{msg}
    { }

    const char* what() const noexcept override
    {
        return msg.data();
    }
};

class Object
{
    public:
    virtual string to_string() const = 0;
    virtual bool equals(const Object& obj)const = 0;
    
    virtual ~Object()
    { }
};

class IHashable : public Object
{
    public:
    virtual int GetHashCode() const = 0;
};

class Integer : public IHashable
{
    int n;
    
    public:
    Integer(const int& n) : n{n}
    { }

    ~Integer()
    { }

    int GetHashCode() const override
    {
        return n;
    }

    string to_string() const override
    {
        return std::to_string(n);
    }

    bool equals(const Object& obj) const override
    {
        const Integer * aux = dynamic_cast<const Integer *>(&obj);
        return aux == nullptr ? false : aux->n == n;
    }
};

class String : public IHashable
{
    string str;
    
    public:
    String(const string& str) : str{str}
    { }

    ~String()
    { }

    int GetHashCode() const override
    {
        const char *aux = str.c_str();
        int r = 0;

        while (*aux)
        {
            r += *(aux++) * 31 + 100;
        }
        return r;
    }

    string to_string() const override
    {
        return str;
    }

    bool equals(const Object& obj) const override
    {
        const String * aux = dynamic_cast<const String *>(&obj);
        return aux == nullptr ? false : aux->str == str;
    }
};

struct LLNode
{
    LLNode *next; 
    IHashable *key;
    Object *value;
     
};

struct LinkedList
{
    LLNode *first;
    LLNode *last;

    LinkedList() : first{nullptr}, last{nullptr}
    { }

    void add(LLNode *new_node)
    {
        if(first == nullptr)
        {
            first = last = new_node;
            return;
        }

        last->next = new_node;
        last = new_node;
    }

    bool erase(const IHashable& key)
    {
        if(first == nullptr) return false;

        if(first == last)
        {
            if(key.equals(*(first->key)))
            {
                delete first->key;
                delete first->value;
                delete first;
                first = last = nullptr;
                return true;
            }
            return false;
        }

        if(key.equals(*(first->key)))
        {
            auto aux = first->next;
            delete first->key;
            delete first->value;
            delete first;
            first = aux;
            return true;
        }

        auto auxA = first;
        while(auxA->next != nullptr)
        {
            auto auxB = auxA->next;

            if(key.equals(*(auxB->key)))
            {
                auxA->next = auxB->next;
                
                if(auxB->next == nullptr)
                {
                    last = auxA;
                }

                delete auxB->key;
                delete auxB->value;
                delete auxB;
                return true;
            }
            auxA = auxA->next;

        }
        return false;
    }

    const Object& operator[](const IHashable &key) const
    {
        LLNode *aux = first;

        while(aux!=nullptr)
        {
            if(key.equals(*(aux->key)))
            {
                return *(aux->value);
            }
            aux = aux->next;
        }

        throw HMException("Key not found");
    }

    void iterate(void (*fun)(const IHashable &h, const Object &val)) const
    {
        auto aux = first;
    
        while(aux != nullptr)
        {
            fun(*(aux->key), *(aux->value));
            aux = aux->next;
        }
    }
};

class HashMap
{
    LinkedList *items;
    size_t array_size;
    size_t total_count;
    double load_factor;

    public:

    HashMap(size_t array_size = 5, size_t total_count = 0, double load_factor = 0.75)
        : items{new LinkedList[array_size]}, array_size{array_size}, total_count{total_count}, load_factor{load_factor}
    {
        // printf("CNSTRCT array_sz: %lu | elem_cnt: %lu | load_f: %f\n", array_size, total_count, load_factor);
    }

    void add(IHashable *key, Object *val)
    {
        LLNode *new_node = new LLNode{nullptr, key, val};

        double new_lf = ((double)total_count) / array_size;

        if(new_lf > load_factor)
        {
            puts("rehash");
            rehash();
        }

        int hash_code = key->GetHashCode();
        int pos = hash_code % ((int)array_size); 
        // printf("X: HC %d | ARR_SZ %d\n", hash_code, array_size);        
        // printf("X: HC %d | POS %d\n", hash_code, pos);

        items[pos].add(new_node);
        total_count++;
    }

    void erase(const IHashable &key)
    {
        int hash_code = key.GetHashCode();
        int pos = hash_code % array_size; 

        auto e = items[pos].erase(key);
        if(e == true)
        {
            total_count--;
        }

        printf("DEL CNT %d\n", total_count);
    }

    const Object& operator[](const IHashable &key) const
    {
        int hc = key.GetHashCode();
        int pos = hc % array_size;

        return items[pos][key];
    }

    void iterate(void(*fun)(const IHashable &h, const Object &val)) const
    {
        for(size_t i = 0; i < array_size; i++)
        {
            items[i].iterate(fun);
        }
    }

    void relink(LinkedList* new_array, size_t n_array_size, LinkedList &array_pos)
    {
        LLNode *aux = array_pos.first;
        while (aux)
        {
            LLNode *next = aux->next;
            aux->next = nullptr;
            int npos = aux->key->GetHashCode() % n_array_size;
            // printf("pos %d | arr_s %lu\n", npos, n_array_size);
            
            new_array[npos].add(aux);
            aux = next;
        }
        array_pos.first = array_pos.last = nullptr;
    }

    void rehash()
    {
        size_t n_array_size = array_size * 2 + 1;

        LinkedList *new_array = new LinkedList[n_array_size];

        for(size_t i = 0; i < array_size; i++)
        {
            relink(new_array, n_array_size, items[i]);
        }

        delete[] items;
        items = new_array;
        array_size = n_array_size;

    }

    ~HashMap()
    {
        delete[] items;
    }
};

// --------OTHER_FUNCTIONS--------

void show(const IHashable &h, const Object &val)
{
    printf("%s %s\n", h.to_string().data(), val.to_string().data());
}

int main()
{
    Object *obj = new Integer{5};
    Object *str = new String{"Hello World"};
    puts(str->to_string().data());
    puts(obj->to_string().data());
    delete str;
    delete obj;

    HashMap hm;
    hm.add(new Integer(10), new String("diez"));
    hm.add(new Integer(20), new String("veinte"));
    hm.add(new Integer(30), new String("treinta"));
    hm.add(new Integer(40), new String("cuarenta"));
    hm.add(new Integer(50), new String("cincuenta"));
    hm.add(new Integer(60), new String("sesenta"));
    hm.add(new Integer(70), new String("setenta"));

    hm.erase(Integer{60});
    hm.erase(Integer{10});
    hm.erase(Integer{30});
    hm.erase(Integer{50});
    hm.erase(Integer{40});
    hm.erase(Integer{40});

    HashMap hm2;
    for (size_t i = 0; i < 1000'000; i++)
    {
        hm2.add(new String(std::to_string(i)), new Integer(i));
    }
    //hm2.iterate(show);
    puts("************");
    auto t0 = clock();
    puts(hm2[String("999999")].to_string().data());
    auto t1 = clock();
    printf("%lf\n", ((double)t1 - t0) / CLOCKS_PER_SEC);

    puts(hm[Integer(20)].to_string().data());

    try
    {
        puts(hm[Integer(25)].to_string().data());
    }
    catch (const std::exception &e)
    {
        puts(e.what());
    }

    puts("******");

    hm.iterate(show);

    puts("END");
}