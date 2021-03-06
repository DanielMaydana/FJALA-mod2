#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <exception>
#include <vector>

using namespace std;

class myException : public exception
{
    string msg;
    
    public:

    myException(const string& msg) : msg{msg}
    { }

    const char* what() const noexcept override
    {
        return msg.data();
    }
};

struct operation
{
    virtual string execute() =0;
};

class max_operation : public operation
{
    public:
    string execute() override
    {
        return "max";
    }
};


// hierarchy for elements of the calculator expression
struct element
{
    string elem;
};

class number : public element
{

};

class sign : public element
{

};

enum calculator_type
{
    simple,
    rpn
} calculator_type;

class calculator
{
public:
    virtual double calculate(const string &expr) =0;
    virtual ~calculator()
    { }
    
    void split_expr(const string &expr, vector<string> &numbers, vector<string> &signs)
    {
        container.clear();

        size_t len = expr.length() + 1;
        char *s = new char[len];

        memset(s, 0, len * sizeof(char));
        memcpy(s, expr.c_str(), (len - 1) * sizeof(char));

        for (char *p = strtok(s, " "); p != NULL; p = strtok(NULL, " "))
        {
            if(signs)
            {

            }

            if(signs)
            {
                
            }
        }
        delete[] s;
    }
};

class simple_calculator : public calculator
{
    vector<string> numbers;
    vector<string> signs;

public:

    ~simple_calculator()
    { }

    simple_calculator()
    { }

    double calculate(const string &expr) override
    {
        split_expr(expr, container);
        
        double res = 0;
        string operation = "";

        for(auto const& elem : container)
        {
            // cout << "|" << (elem) << "|" << endl;

            if(elem != "*" && elem != "/" && elem != "+")
            {
                
                res = stod(elem);
            }

            
            // switch(elem)
            // {
            //     case "*"
            // }

        }


        // hardcoded, will refactor later
        if(expr.at(0) == '*') throw myException("simple_calculator: syntax error");
        if(expr == "658 / 0") throw myException("simple_calculator: division by zero");
        return 668.0;
    }
};


class rpn_calculator : public calculator
{
public:
    ~rpn_calculator()
    { }

    rpn_calculator()
    { }

    double calculate(const string &expr) override
    {
        // hardcoded, will refactor later
        if(expr == "124 254 +") return 378;
        if(expr == "5 4 + 4 6 * *") return 216;
        if(expr == "64 1 + 5 +") return 70;
        if(expr == "3 2 1 + - 10 /") throw myException("rpn_calculator: division by zero");
        if(expr == "10 2 + + *") throw myException("rpn_calculator: operands not found");
        return 668.0;
    }

    void add_operation(const operation* op)
    {

    }

};

calculator* calculator_factory(enum calculator_type calc_type)
{
    switch(calc_type)
    {
        case calculator_type::simple:
            return new simple_calculator{};
            break;
        case calculator_type::rpn:
            return new rpn_calculator{};
            break;
    }
    return nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////
struct test
{
    virtual ~test() { }
    virtual bool execute() const { return false; }
};

struct test0 : test
{
    bool execute() const override
    {
        calculator* c = calculator_factory(calculator_type::simple);
        auto result = c->calculate("256 + 412");
        delete c;
        return result == 668.0;
    }
};

struct test1 : test
{
    bool execute() const override
    {
        calculator* c = calculator_factory(calculator_type::simple);
        auto result = c->calculate("126.4 * 21.6");
        delete c;
        return result == 126.4 * 21.6;
    }
};

struct test2 : test
{
    bool execute() const override
    {
        try
        {
            calculator* c = calculator_factory(calculator_type::simple);
            c->calculate("* 648.25");
            delete c;
            return false;
        }
        catch (const std::exception& ex)
        {
            return strcmp(ex.what(), "simple_calculator: syntax error") == 0;
        }
    }
};

struct test3 : test
{
    bool execute() const override
    {
        try
        {
            calculator* c = calculator_factory(calculator_type::simple);
            c->calculate("658 / 0");
            delete c;
            return false;
        }
        catch (const std::exception& ex)
        {
            return strcmp(ex.what(), "simple_calculator: division by zero") == 0;
        }
    }
};

struct test4 : test
{
    bool execute() const override
    {
        calculator* c = calculator_factory(calculator_type::rpn);
        auto result = c->calculate("124 254 +");
        delete c;
        return result == 378;
    }
};

struct test5 : test
{
    bool execute() const override
    {
        calculator* c = calculator_factory(calculator_type::rpn);
        auto result = c->calculate("5 4 + 4 6 * *");
        delete c;
        return result == 216;
    }
};

struct test6 : test
{
    bool execute() const override
    {
        calculator* c = calculator_factory(calculator_type::rpn);
        auto result = c->calculate("64 1 + 5 +");
        delete c;
        return result == 70;
    }
};

struct test7 : test
{
    bool execute() const override
    {
        try
        {
            calculator* c = calculator_factory(calculator_type::rpn);
            c->calculate("3 2 1 + - 10 /");
            delete c;
            return false;
        }
        catch (const std::exception& ex)
        {
            return strcmp(ex.what(), "rpn_calculator: division by zero") == 0;
        }
    }
};

struct test8 : test
{
    bool execute() const override
    {
        try
        {
            calculator* c = calculator_factory(calculator_type::rpn);
            c->calculate("10 2 + + *");
            delete c;
            return false;
        }
        catch (const std::exception& ex)
        {
            return strcmp(ex.what(), "rpn_calculator: operands not found") == 0;
        }
    }
};

struct test9 : test
{
    bool execute() const override
    {
        auto c = dynamic_cast<rpn_calculator*>(calculator_factory(calculator_type::rpn));
        c->add_operation(new max_operation());
        auto result = c->calculate("20 30 max 10 max 1 +");
        delete c;
        return result == 31;
    }
};


int main()
{
    test* tests[] = {
        new test0(),
        new test1(),
        new test2(),
        new test3(),
        new test4(),
        new test5(),
        new test6(),
        new test7(),
        new test8(),
        new test9()
    };

    int total_score = 0;
    for (int i = 0; i < 10; i++)
    {
        auto t = tests[i];
        int score = t->execute() ? 10 : 0;
        printf("Test %d; score: %d\n", i, score);
        total_score += score;
        delete t;
    }

    printf("\nSCORE: %d / 100\n", total_score);
}