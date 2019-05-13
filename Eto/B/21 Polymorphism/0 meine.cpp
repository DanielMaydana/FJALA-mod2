#include <iostream>
#include <stdio.h>
#include <string>

class Object
{
public:
    virtual std::string to_string() const = 0;
    // {
    //     return std::to_string((long long)this);
    // }

    virtual bool equals(const Object &src) const = 0;
    // {
    //     return this == &src;
    // }

    virtual ~Object()
    {
        puts("Bye OBJECT");
    }
};

class Integer : public Object
{
    int n;

public:
    Integer(int n) : n{n}
    {
    }

    bool equals(const Object &src) const override
    {
        return n == static_cast<const Integer &>(src).n;
    }

    std::string to_string() const override
    {
        return std::to_string(n);
    }

    int get() const
    {
        return n;
    }
};

class String : public Object
{
    std::string str;

public:
    String(const std::string &s) : str{s}
    {
    }

    bool equals(const Object &src) const override
    {
        return str == static_cast<const String &>(src).str;
    }

    std::string to_string() const override
    {
        return str;
    }
};

class Stack : public Object
{
    Object **stack_items;
    size_t n;

public:
    Stack()
        : stack_items{static_cast<Object **>(malloc(0))}, n{0}
    {
    }

    ~Stack()
    {
        for (size_t i = 0; i < n; i++)
        {
            delete stack_items[i];
        }
        free(stack_items);

        puts("Bye STACK");
    }

    bool is_empty()
    {
        return n == 0;
    }

    void push(Object *obj)
    {
        stack_items = static_cast<Object **>(realloc(stack_items, (n + 1) * sizeof(obj)));
        stack_items[n++] = obj;
    }

    Object *pop()
    {
        return stack_items[--n];
    }

    std::string to_string() const override
    {
        puts("poor elijah");

        std::string converted;

        for (int i = (n - 1); i >= 0; i--)
        {
            converted += stack_items[i]->to_string();
            converted += " ";
        }
        converted += "\n";

        return converted;
    }

    int getN()
    {
        return n;
    }

    bool equals(const Object &obj) const override
    {
        return true;
    }
};

int main()
{
    Stack myStack;

    myStack.push(new Integer(111));
    myStack.push(new Integer(222));
    myStack.push(new String("Robot"));
    printf("Stack string: %s\n", myStack.to_string().data());

    int sum = 0;

    while (!myStack.is_empty())
    {
        auto e = myStack.pop();

        // printf("N: %d\n", myStack.getN());

        auto f = dynamic_cast<Integer *>(e);
        sum += f ? f->get() : 0;
        delete e;
        printf("Sum: %d\n", sum);
    }
}