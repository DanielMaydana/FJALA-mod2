#include <iostream>
#include <string>
using namespace std;

class IJson;
//----------------------------class---------------------------
//----------------------------class---------------------------
class ArrayList
{
    IJson **objects;
    size_t len;
    size_t cap;
    // bool owner;

  public:
    ArrayList()//(bool owner = true)
    :objects{(new IJson[4])}, len{0}, cap{4}//, owner{owner}
    {
    }

    ~ArrayList() 
    {
        // implementar //---------------------------
    }

    // void Add(IJson& json)
    // {}

    size_t size() const
    {
        return len;
    }

    void add(IJson* obj)
    {
        objects = (IJson **)realloc(objects, (len + 1) * sizeof(Object *));
        objects[len] = obj;
        len++;
    }

    IJson& operator[](size_t index)
    {
        return *(objects[index]);
    }

    IJson& operator[](size_t index) const
    {
        return *(objects[index]);
    }

    // void mostrar() const
    // {
    //     for (size_t i = 0; i < len; i++)
    //     {
    //         (*this)[i].mostrar();
    //     }
    // }

    // const objecto &get_object(const objecto &) const
    // {
    //     for (size_t i = 0; i < len; i++)
    //     {
    //         if ((*this)[i].equals_to(obj))
    //             return (*this)[i];
    //     }
    //     throw 0;
    // }

    // objecto &get_object(const objecto &)
    // {
    //     for (size_t i = 0; i < len; i++)
    //     {
    //         if ((*this)[i].equals_to(obj))
    //             return (*this)[i];
    //     }
    //     throw 0;
    // }
};

//----------------------------class---------------------------
//----------------------------class---------------------------
class IJson
{
private:
    
public:
    IJson() { }
    
    virtual ~IJson() { }

    virtual string to_string() const = 0;

    // virtual void add(IJson& json) = 0;
};

//----------------------------class---------------------------
class JsonNumber : public IJson
{
private:
    int number;
public:
    JsonNumber(int number) 
    :number{number}
    { }

    ~JsonNumber() { }

    string to_string() const override
    {
        return std::to_string(number);
    }

    // void add(IJson& json) override
    // {}
};

//----------------------------class---------------------------
class JsonObject : public IJson
{
private:
    // Object obj; // creo que no es necesario
    ArrayList objs;
public:
    JsonObject()//(Object obj) 
    // :obj{obj}
    { }

    JsonObject() 
    { }

    ~JsonObject() { }

// return jo.to_string() == "{}";
    string to_string() const override
    {
        if(objs.size() == 0)
        {
            return "{}";
        }
    }

    void add(IJson& json) override
    {}

    void add(string label, string value)
    {}

    void add(string label, int value)
    {}
};

//----------------------------end---------------------------
//----------------------------end---------------------------
bool test0()
{
    JsonNumber jn { 3141 };
    return jn.to_string() == "3141";
}

bool test1()
{
    JsonObject jo;
    return jo.to_string() == "{}";
}

bool test2()
{
    JsonString js { "hello" };
    return js.to_string() == "\"hello\"";
}

bool test3()
{
    JsonArray ja;
    return ja.to_string() == "[]";
}

bool test4()
{
    JsonArray ja;
    ja.add(125);
    ja.add("hello");
    ja.add("friends");
    return ja.to_string() == "[125, \"hello\", \"friends\"]";
}

// bool test5()
// {
//     JsonObject jo;
//     jo.add("firstName", "John");
//     jo.add("lastName", "Smith");
//     jo.add("birthYear", 1977);
//     return jo.to_string() == "{ \"firstName\": \"John\", \"lastName\": \"Smith\", \"birthYear\": 1977 }";
// }

// bool test6()
// {
//     JsonArray ja;
//     ja.add("hello");

//     JsonObject jo;
//     jo.add("firstName", "John");
//     jo.add("lastName", "Smith");
//     jo.add("birthYear", 1977);

//     ja.add(jo);

//     ja.add(1492);

//     return ja.to_string() == "[\"hello\", { \"firstName\": \"John\", \"lastName\": \"Smith\", \"birthYear\": 1977 }, 1492]";
// }

// bool test7()
// {
//     JsonObject jo;

//     jo.add("nombre", "jugo de frutas");

//     JsonArray ingredients;
//     ingredients.add("leche");
//     ingredients.add("frutilla");
//     ingredients.add("manzana");
//     ingredients.add("azucar");

//     jo.add("ingredientes", ingredients);
//     return jo.to_string() == "{ \"nombre\": \"jugo de frutas\", \"ingredientes\": [ \"leche\", \"frutilla\", \"manzana\", \"azucar\" ] }";
// }

// bool test8()
// {
//     JsonArray ja;
//     ja.add("hello");

//     JsonObject jo;
//     jo.add("firstName", "John");
//     jo.add("lastName", "Smith");
//     jo.add("birthYear", 1977);

//     ja.add(jo);

//     ja.add(1492);

//     return ja.to_string(true) ==
//     "[\n"
//     "    \"hello\",\n"
//     "    {\n"
//     "        \"firstName\": \"John\",\n"
//     "        \"lastName\": \"Smith\",\n"
//     "        \"birthYear\": 1977\n"
//     "    },\n"
//     "    1492\n"
//     "]";
// }

// bool test9()
// {
//     JsonObject jo;

//     jo.add("nombre", "jugo de frutas");

//     JsonArray ingredients;
//     ingredients.add("leche");
//     ingredients.add("frutilla");
//     ingredients.add("manzana");
//     ingredients.add("azucar");

//     jo.add("ingredientes", ingredients);
//     return jo.to_string(true, 2) ==
//     "{\n"
//     "  \"nombre\": \"jugo de frutas\",\n"
//     "  \"ingredientes\": [\n"
//     "    \"leche\",\n"
//     "    \"frutilla\",\n"
//     "    \"manzana\",\n"
//     "    \"azucar\"\n"
//     "  ]\n"
//     "}";
// }

int main()
{
    size_t score = 0;
    score += test1();
    score += test2();
    score += test0();
    score += test3();
    score += test4();
    // score += test5();
    // score += test6();
    // score += test7();
    // score += test8();
    // score += test9();

    cout << "Score: " << score << " / 10\n";
}