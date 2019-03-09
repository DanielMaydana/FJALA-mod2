// hrerencia virtual

#include <iostream>
using namespace std;


class Object
{
private:
    
public:
    Object() { }
    virtual ~Object() { }

    virtual bool equals(const Object& obj) const = 0;

    virtual void show() const = 0;
};


class IComparable : public virtual Object  // virtual para heredar de forma virtual
{
private:
    
public:
    IComparable() { }
    ~IComparable() { }

    virtual int compareTo(const Object& obj) const = 0;
};


class Integer : public virtual Object, public virtual IComparable
{
private:
    int n;
public:
    Integer(int n) 
    :n{n}
    { }
    ~Integer() { }

    bool equals(const Object& obj) const override
    {
        // Integer& i = (Integer&) obj; // para castear en tiempo de ejcucion se necesita un dynamic cast
        const Integer& i = dynamic_cast<const Integer&> (obj); // 
        return n == i.n;
    }

    void show() const override
    {
        cout << n << "\n";
    }

    int compareTo(const Object& obj) const override
    {
        const Integer& i = dynamic_cast<const Integer&>(obj);
        return n - i.n;
    }
};

int main()
{
    Object* p1 = new Integer{10};
    IComparable* p2 = new Integer{20};
    cout << p1->equals(*p2) << "\n";
    cout << p2->compareTo(*p1) << "\n";
    p1->show();
    p2->show();
    delete p1;
    delete p2;
}