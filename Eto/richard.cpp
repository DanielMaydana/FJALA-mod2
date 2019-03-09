
// Implement a f_stack<T> (LIFO) class.
// Implement a RPN evaluator class. (1 2 +) will push 1 and 2 in a stack,
//   and the operator + will remove them and push into them the result of adding them up.
//   It will support the 4 basic operations.
// You can use everything seen at class, but no other stuff.
// Not compiling code will render your exam useless.
// Having memory leaks will subtract 10 points to your last score.
// Do not use inheritance, polymorphism or any virtual thing.
#include <iostream>
#include <list>
#include <string>
#include <cstring>
#include <stdio.h>
#include <typeinfo>
#include <vector>

using namespace std;

class Ex : public exception
{
    //int error_code;

  public:
    //Ex(int ec) : error_code{ec} {}
    const char *what() const throw()
    {
        return "User 'roberto' is not logged into the system";
    }
};

template <typename T>
class f_stack
{
    list<T> value;

  public:
    bool is_empty()
    {
        if (this->value.empty())
        {
            return true;
        }
        return false;
    }
    void push(T value)
    {
        this->value.push_back(value);
    }

    T pop()
    {
        try
        {
            T v = this->value.back();
            this->value.pop_back();

            return v;
        }
        catch (const std::exception &e)
        {
            //throw Ex();
        }
    }
    template <typename PRED>
    void iterate(PRED p)
    {
        value.reverse();
        for (auto &e : value)
        {
            p(e);
        }
        value.reverse();
    }
};

template <typename PRED>
void split_string(const char c, const string str, PRED p)
{
    string aux;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            p(aux);
            aux = "";
        }
        else
        {
            aux += str[i];
            if (i == str.length() - 1)
            {
                p(aux);
                aux = "";
            }
        }
    }
}

class evaluator
{

  public:
    int evaluate(const string &str)
    {
        vector<string> operators;
        vector<int> numbers;
        split_string(' ', str, [&operators, &numbers](auto &e) {
            if (e == "+" || e == "-" || e == "*" || e == "/")
            {
                operators.push_back(e);
            }
            else
            {
                numbers.push_back(std::stoi(e));
            }
        });

        cout << operators.size() << "\t" << numbers.size() << "\n";

        for (auto &e : operators)
        {
            if (e == "+")
            {
                try
                {
                    int a = numbers.back();
                    numbers.pop_back();
                    int b = numbers.back();
                    cout << a << " " << b << "\n";
                    numbers.pop_back();
                    numbers.push_back(a + b);
                }
                catch (const std::exception &e)
                {
                }
            }
            if (e == "*")
            {
                int a = numbers.back();
                numbers.pop_back();
                int b = numbers.back();
                cout << a << " " << b << "\n";
                numbers.pop_back();
                numbers.push_back(a * b);
            }
        }

        return numbers.back();
    }
};

bool test0()
{
    f_stack<int> st;
    auto r1 = st.is_empty();
    st.push(10);
    auto r2 = st.is_empty();
    return r1 && !r2;
}

bool test1()
{
    f_stack<int> st;
    st.push(50);
    st.push(40);
    st.push(25);
    return st.pop() == 25 && st.pop() == 40;
}

bool test2()
{
    f_stack<string> s;
    s.push("easy");
    s.push("was");
    s.push("exam");
    s.push("second");
    auto s4 = s.pop();
    auto s3 = s.pop();
    auto s2 = s.pop();
    auto s1 = s.pop();
    return s4 == "second" && s3 == "exam" && s2 == "was" && s1 == "easy" && s.is_empty();
}

bool test3()
{
    f_stack<string> sd;
    sd.push("devices");
    sd.push("own");
    sd.push("my");
    sd.push("to");
    sd.push("left");
    string accum;
    sd.iterate([&accum](auto &x) {
        accum += x + " ";
    });
    string accum2;
    sd.iterate([&accum2](auto &x) {
        accum2 += x + " ";
    });
    return accum == accum2 && accum == "left to my own devices ";
}

bool test4()
{
    try
    {
        f_stack<string> x;
        x.push("hello");
        x.push("world");
        x.pop();
        x.pop();
        x.pop();
        return false;
    }
    catch (const std::exception &ex)
    {
        return "Attempt to pop value from empty stack"s == ex.what();
    }
}

bool test5()
{
    string result;
    split_string(' ', "abc def ghi jkl", [&result](auto &s) {
        result += s + "; ";
    });
    return result == "abc; def; ghi; jkl; ";
}

bool test6()
{
    evaluator m;
    return m.evaluate("10 30 +") == 40;
}

bool test7()
{
    evaluator x;
    return x.evaluate("10 20 50 + *") == 700;
}

bool test8()
{
    try
    {
        evaluator x;
        x.evaluate("10 20 + +");
        return false;
    }
    catch (const exception &x)
    {
        return "Operand not found"s == x.what();
    }
}

// bool test9()
// {
//     evaluator x;
//     x.add_operator("min", [](auto &x, auto &y)
//                    {
//                       return x < y ? x : y;
//                   });
//     return x.evaluate("5 3 * 10 20 - min") == 15;
// }

using test = bool (*)();

auto main() -> int
{
    test tests[] = {
        test0,
        test1,
        test2,
        test3,
        test4,
        test5,
        test6,
        test7,
        test8
        // test9
    };

    size_t score = 0;

    for (auto &t : tests)
    {
        score += t() * 10;
    }

    cout << "Score: " << score << " / 100\n";

    getchar();

    return 0;
}
