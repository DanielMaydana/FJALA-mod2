#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <cstring>
#include <functional>

using namespace std;
class json_object;
class json_array;

class json_null
{
  public:
    string to_string()
    {
        return "null";
    }
};

class json_number
{
    int number;

  public:
    json_number(int n)
        : number{n}
    {
    }
    string to_string()
    {
        return std::to_string(number);
    }
};

class json_bool
{
    bool boolean;

  public:
    json_bool(bool b)
        : boolean{b}
    {
    }
    string to_string()
    {
        if (boolean == true)
        {
            return "true";
        }
        return "false";
    }
};

class json_string
{
    string str;

    void remplace_character(const char *s)
    {
        string value;
        str = s;
        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] == '"')
            {
                value += "\\";
            }
            value += str[i];
        }
        str = value;
    }

  public:
    json_string(const char *s)
    {
        remplace_character(s);
    }
    string to_string()
    {
        return "\"" + str + "\"";
    }
    void operator=(const string &value)
    {
        str = value;
    }
};

///////////////////////Especializacion de Template///////////////////
// template <typename T>
// string str_different(const T &value);

// template <>
// string str_different<bool>(const bool &value)
// {
//     json_bool b{value};
//     return b.to_string();
// }
// template <>
// string str_different<int>(const int &value)
// {
//     json_number n{value};
//     return n.to_string();
// }
// template <>
// string str_different<string>(const string &value)
// {
//     char aux[100];
//     strcpy(aux, value.c_str());
//     json_string s{aux};
//     return s.to_string();
// }
///////////////////////////////////////////////////////
class json_object
{
    string str;
    vector<string> values;

  public:
    json_object add(const char *key, const char *value)
    {
        json_string k{key};
        json_string v{value};
        values.push_back(k.to_string() + " : " + v.to_string());
        return *this;
    }
    json_object add(const char *key, int value)
    {
        json_string k{key};
        json_number v{value};
        values.push_back(k.to_string() + " : " + v.to_string());
        return *this;
    }
    // json_object &add(const char *key, json_array &value)
    // {
    //     values.push_back(value.to_string());
    //     return *this;
    // }
    string to_string()
    {
        if (values.empty())
        {
            return "{ }";
        }
        str += "{ ";
        for (auto &v : values)
        {
            str += v;
            if (v != values.back())
                str += ", ";
        }
        str += " }";
        return str;
    }
};

class json_array
{
    string str;
    vector<string> values;

  public:
    json_array &add(bool value)
    {
        json_bool b{value};
        values.push_back(b.to_string());
        return *this;
    }
    json_array &add(int value)
    {
        json_number n{value};
        values.push_back(n.to_string());
        return *this;
    }
    json_array &add(const string &value)
    {
        char aux[100];
        strcpy(aux, value.c_str());
        json_string s{aux};
        values.push_back(s.to_string());
        return *this;
    }

    json_array &add(json_object &value)
    {
        values.push_back(value.to_string());
        return *this;
    }

    string to_string()
    {
        str += "[";
        for (auto &v : values)
        {
            str += v;
            if (v != values.back()) str += ", ";
        }
        str += "]";
        return str;
    }
};

// ------------------------------------------------------

bool test0()
{
    json_null j;
    return j.to_string() == "null";
}

bool test1()
{
    json_number j{125};
    return j.to_string() == "125";
}

bool test2()
{
    json_bool j{true};
    json_bool k{false};
    return j.to_string() == "true" && k.to_string() == "false";
}

bool test3()
{
    json_string j{"hello world"};
    return j.to_string() == "\"hello world\"";
}

bool test4()
{
    json_string j = "my name is \"Michael\"";
    return j.to_string() == "\"my name is \\\"Michael\\\"\"";
}

bool test5()
{
    json_object j;
    return j.to_string() == "{ }";
}

bool test6()
{
    json_array ja;
    ja.add(true);
    ja.add("hello world"s);
    ja.add(237);
    return ja.to_string() == "[true, \"hello world\", 237]";
}

bool test7()
{
    json_object jo;
    jo.add("first_name", "juan");
    jo.add("last_name", "perez");
    jo.add("birth_year", 1970);
    return jo.to_string() == "{ \"first_name\" : \"juan\", \"last_name\" : \"perez\", \"birth_year\" : 1970 }";
}

bool test8()
{
    json_array ja;

    json_object jo1;
    jo1.add("first_name", "juan");
    jo1.add("last_name", "perez");
    jo1.add("birth_year", 1970);

    json_object jo2;
    jo2.add("first_name", "omar");
    jo2.add("last_name", "vera");
    jo2.add("birth_year", 1995);

    ja.add(jo1).add(jo2);

    return ja.to_string() == "[{ \"first_name\" : \"juan\", \"last_name\" : \"perez\", \"birth_year\" : 1970 }, { \"first_name\" : \"omar\", \"last_name\" : \"vera\", \"birth_year\" : 1995 }]";
}

bool test9()
{
    json_object jo;
    jo.add("marca", "volkswagen");
    jo.add("modelos", json_array{}.add("jetta").add("new beetle").add("golf"));
    //jo.add("descripcion", json_object{}.add("pais", "alemania").add("produccion_anual", 50000));
    return jo.to_string() == "{ \"marca\" : \"volkswagen\", \"modelos\" : [\"jetta\", \"new beetle\", \"golf\"], \"descripcion\" : { \"pais\" : \"alemania\", \"produccion_anual\" : 50000 } }";
}

// ------------------------------------------------------

int main()
{
    auto score = 0.0;

    score += 0.5 * static_cast<double>(test0());
    score += 0.5 * static_cast<double>(test1());
    score += 0.5 * static_cast<double>(test2());
    score += 0.5 * static_cast<double>(test3());
    score += 0.5 * static_cast<double>(test4());
    score += 0.5 * static_cast<double>(test5());
    score += 1.6 * static_cast<double>(test6());
    score += 1.7 * static_cast<double>(test7());
    score += 1.8 * static_cast<double>(test8());
    score += 1.9 * static_cast<double>(test9());

    cout << score * 10 << " / 100\n";

    return 0;
}