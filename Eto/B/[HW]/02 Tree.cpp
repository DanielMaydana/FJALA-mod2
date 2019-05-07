#include <cstdio>
#include <string>
using namespace std;

class Object
{
private:
    // Object value;    
public:
    Object() { }
    ~Object() { }
    virtual string to_string ()const;
};

class IComparable : public Object
{
private:
    Object value;
public:
    IComparable();
    ~IComparable();
    virtual string to_string()const = 0;
    virtual int compare(Object* obj)=0;
};

class bstNode
{
private:
    bstNode* left;
    bstNode* right;
    Object* key;
    Object* value;
public:
    bstNode(Object* key, Object* value) 
    :left{nullptr}, right{nullptr}, key{key}, value{value}
    {}
    ~bstNode() {}
};

class bst : public IComparable
{
private:
    bstNode* root;
public:
    bst() 
    :root{nullptr}
    { }
    ~bst() { }

    void add(Object* key, Object* value, bstNode* node = root)
    {
        bstNode* newNode = new bstNode(key, value);
        bstNode* nextNode;

        if(root == nullptr)
        {
            root = newNode;
        }
        else
        {
            next 
            add(key, value, )
            
        }
        
    } 

    void iterate(void (*func)(const IComparable& key, const Object& value))
    {}

    bool try_find(const Object& key, Object* value)
    {
        return true;
    }

    int compare(Object* obj) override
    {

    }

    string to_string()const override
    {

    } 
};

class Integer : public IComparable
{
private:
    int number;
public:
    Integer(int number)
    :number{number} 
    { }
    ~Integer() { }

    string to_string ()const override
    {}

    int compare(Object* obj) override
    {
        Integer* aux = dynamic_cast<Integer*>(obj);
        return number - aux->number; 
    }
};

class String : public IComparable
{
private:
    string str;
public:
    String(const string str) 
    :str{str}
    { }

    ~String() { }

    string to_string ()const override
    {}

    int compare(Object obj) override
    {

    }
};


void show_pair(const IComparable& key, const Object& value)
{
  printf("%s: %s\n", key.to_string().data(), value.to_string().data());
}

int main()
{
  bst b;
  b.add(new Integer(1), new String("uno"));
  b.add(new Integer(10), new String("diez"));
  b.add(new Integer(5), new String("cinco")); 
  b.add(new Integer(8), new String("ocho"));
  b.add(new Integer(7), new String("siete"));
  b.add(new Integer(2), new String("dos"));

  b.iterate(show_pair);
 
  Object* obj;
 if (b.try_find(Integer(2), obj))
     puts(obj->to_string().data());
  else
     puts("Not found");

  return 0;
}