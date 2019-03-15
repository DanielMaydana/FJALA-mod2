#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <functional>
#include <stdexcept>

using namespace std;

const string msg = "is not";
const string msg2 = "into the system";

class f_exception : public exception
{
  private:
    string name;
    string aux;

  public:
    f_exception(string &name)
        : name{name}
    {
        aux = aux + "User '" + name + "' " + msg + " logged " + msg2;
    }

    f_exception(string &name, string regist)
        : name{name}
    {
        aux = aux + "User '" + name + "' " + msg + " registered " + msg2;
    }
    f_exception() {}

    ~f_exception() {}

    const char *what() const noexcept override
    {

        return aux.data();
    }
};

class user
{
  private:
    string name;
    bool band;
    vector<user> *users;

  public:
    user(const string &name)
        : name{name}, band{false} {}
    ~user() {}

    void set_user(vector<user> *user)
    {
        this->users = user;
    }

    string get_name() const
    {
        return name;
    }

    void send_message(string name, const string &message)
    {
        // cout << "hasta aqui bien\n";
        if (this->band == true)
        {
            for (auto &e : *users)
            {
                if (e.get_name() == name)
                {
                    if (e.get_log())
                    {
                    }
                    else
                    {
                        throw f_exception{name};
                    }
                }
                else
                {
                    throw f_exception{name, "registered"};
                }
            }
        }
        else
            throw f_exception{this->name};
    }

    void operator()(bool band)
    {
        this->band = band;
    }

    bool get_log() const
    {
        return band;
    }
};

class messenger
{
  private:
    vector<user> users;

  public:
    messenger() {}
    ~messenger() {}

    // template<typename T>
    void add_user(const user &user_type)
    {
        users.push_back(user_type);
        const_cast<user &>(user_type).set_user(&users);
    }

    template <typename PROC>
    void iterate_users(PROC p)
    {
        for (auto &e : users)
        {
            p(e);
        }
    }

    user &operator[](string name)
    {
        for (auto &e : users)
        {
            if (e.get_name() == name)
                return e;
        }
        throw f_exception{name, "registered"};
    }

    template <typename PROC>
    void login_user(const string &name, PROC p)
    {
        bool band = true;
        for (auto &e : users)
        {
            if (e.get_name() == name)
                e(band);
        }
    }
};

bool test0()
{
    messenger im;
    im.add_user(user{"juan"});
    im.add_user(user{"roberto"});

    string s;
    im.iterate_users([&s](auto &u) {
        s += u.get_name();
    });

    return s == "juanroberto" || s == "robertojuan";
}

bool test1()
{
    try
    {
        messenger im;
        im.add_user(user{"juan"});
        im.add_user(user{"roberto"});

        im["roberto"].send_message("juan", "nos vemos a las 5");
    }
    catch (const exception &ex)
    {
        cout << "entra\n";
        string s = ex.what();
        cout << s << "\n";
        cout << "User 'roberto' is not logged into the system"
             << "\n";
        return s == "User 'roberto' is not logged into the system";
    }

    return false;
}

bool test2()
{
    try
    {
        messenger im;
        im.add_user(user{"juan"});
        im.add_user(user{"roberto"});

        im.login_user("roberto", [](auto &) {});
        im["roberto"].send_message("juan", "nos vemos a las 5");
    }
    catch (const exception &ex)
    {
        string s = ex.what();
        return s == "User 'juan' is not logged into the system";
    }

    return false;
}

bool test3()
{
    try
    {
        messenger im;
        im.add_user(user{"juan"});
        im.add_user(user{"roberto"});

        im.login_user("roberto", [](auto &) {});
        im["maria"].send_message("roberto", "hola");
    }
    catch (const exception &ex)
    {
        string s = ex.what();
        cout << s << "\n";
        cout << "User 'maria' is not registered into the system"
             << "\n";
        return s == "User 'maria' is not registered into the system";
    }

    return false;
}

bool test4()
{
    try
    {
        messenger im;
        im.add_user(user{"juan"});
        im.add_user(user{"roberto"});

        im.login_user("roberto", [](auto &) {});
        im["roberto"].send_message("maria", "hola");
    }
    catch (const exception &ex)
    {
        string s = ex.what();
        return s == "User 'maria' is not registered into the system";
    }

    return false;
}

// bool test5()
// {
//     messenger im;
//     im.add_user(user{"juan"});
//     im.add_user(user{"roberto"});

//     im.login_user("roberto", [](auto &) {});
//     string s;
//     string r;
//     im.login_user("juan", [&s, &r](auto &msg) {
//         s = msg.get_message();
//         r = msg.get_sender();
//     });
//     im["roberto"].send_message("juan", "nos vemos a las 5");

//     return s == "nos vemos a las 5" && r == "roberto";
// }

// bool test6()
// {
//     string s;
//     auto f = [&s](auto &msg) {
//         s += msg.get_message() + msg.get_sender() + msg.get_receiver();
//     };

//     messenger im;
//     im.add_user(user{"juan"});
//     im.add_user(user{"roberto"});
//     im.add_user(user_group{"cuates", "juan", "roberto"});

//     im.login_user("roberto", f);
//     im.login_user("juan", f);

//     im["juan"].send_message("cuates", "invito pizza");
//     return s == "invito pizzajuancuatesinvito pizzarobertocuates" || s == "invito pizzarobertocuatesinvito pizzajuancuates";
// }

// bool test7()
// {
//     try
//     {
//         messenger im;
//         im.add_user(user{"juan"});
//         im.add_user(user{"roberto"});

//         im.login_user("roberto", [](auto &) {});
//         im.login_user("juan", [](auto &) {});
//         im.logoff_user("roberto");
//         im["roberto"].send_message("juan", "nos vemos a las 5");
//     }
//     catch (const exception &ex)
//     {
//         string s = ex.what();
//         return s == "User 'roberto' is not logged into the system";
//     }

//     return false;
// }

// bool test8()
// {
//     try
//     {
//         messenger im;
//         im.add_user(user{"juan"});
//         im.add_user(user{"roberto"});

//         im.login_user("roberto", [](auto &) {});
//         im.login_user("juan", [](auto &) {});
//         im.logoff_user("juan");
//         im["roberto"].send_message("juan", "nos vemos a las 5");
//     }
//     catch (const exception &ex)
//     {
//         string s = ex.what();
//         return s == "User 'juan' is not logged into the system";
//     }

//     return false;
// }

// bool test9()
// {
//     message_storage ms{messenger{}};

//     ms->add_user(user{"juan"});
//     ms->add_user(user{"roberto"});

//     ms.login_all_users();

//     (*ms)["roberto"].send_message("juan", "hola");
//     (*ms)["roberto"].send_message("juan", "te cuento que me encontré con jorge");

//     (*ms)["juan"].send_message("roberto", "y que te dijo");

//     (*ms)["roberto"].send_message("juan", "que vayamos todos la concierto el viernes");

//     (*ms)["juan"].send_message("roberto", "genial, vamos, bye");

//     string s;
//     ms.iterate_messages([&s](auto &msg) {
//         s += msg.get_sender() + ";" + msg.get_receiver() + ";" + msg.get_message() + ";";
//     });

//     return s == "roberto;juan;hola;roberto;juan;te cuento que me encontré con jorge;juan;roberto;y que te dijo;roberto;juan;que vayamos todos la concierto el viernes;juan;roberto;genial, vamos, bye;";
// }

int main()
{
    vector<function<bool()>> tests;
    tests.push_back(test0);
    tests.push_back(test1);
    tests.push_back(test2);
    tests.push_back(test3);
    tests.push_back(test4);
    // tests.push_back(test5);
    // tests.push_back(test6);
    // tests.push_back(test7);
    // tests.push_back(test8);
    // tests.push_back(test9);

    auto accum = 0;
    for (auto &test : tests)
    {
        accum += test();
    }
    cout << "SCORE: " << accum << " / " << tests.size() << "\n";
    return 0;
}
