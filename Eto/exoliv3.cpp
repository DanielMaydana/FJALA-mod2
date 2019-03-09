#include <iostream>
#include <string>
using namespace std;

const string OPENBRACK = "[";
const string CLOSEBRACK = "]";
const string OPENKEY = "{";
const string CLOSEKEY = "}";
const string COMILLA = "\"";
const string SPACE = " ";
const string COMA = ",";
const string ENDL = "\n";
const string TAB = "    ";
const string TAB2 = "  ";
const string PUNTOS = ":";

struct JsonNumber
{
      int n;

      string to_string()
      {
            return std::to_string(n);
      }
};

struct JsonString
{
      string word;

      string to_string()
      {
            return COMILLA + word + COMILLA;
      }
};

class object
{
private:
      string str;
public:
      object(const string& str)
      :str{str} { }
      ~object() { }

      string get_str() const
      {
            return str;
      }
};

class f_array
{
private:
      object** objects;
      size_t len;
public:
      f_array()
      :objects{static_cast<object**>(malloc(0))}, len{0} { }
      ~f_array() { }

      void add(object* obj)
      {
            objects = static_cast<object**>(realloc(objects, (len+1)*sizeof(object*)));
            objects[len++] = obj;
      }

      size_t size() const
      {
            return len;
      }

      object& operator[](size_t position) const
      {
            return *objects[position];
      }
};

class JsonArray;

class JsonObject
{
private:
      f_array array_pair;
      f_array array_str;
      bool flag;
public:
      JsonObject();
      ~JsonObject();

      void add(const string& key, const string& value);
      void add(const string& key, size_t value);
      void add(const string& ingrediente, JsonArray& obj);

      void word(string& aux, size_t i);
      void word_pair(string& aux, size_t i);

      string to_string(bool band, size_t n);//2

      size_t size() const;

      object& get_object(size_t position) const;
};

class JsonArray
{
private:
      f_array array_str;
      f_array array_pair;
      bool flag;
public:
      JsonArray()
      :flag{false} { }
      ~JsonArray() { }

      void add(const string& str)
      {
            array_str.add(new object{str});
      }

      void add(size_t number)
      {
            array_str.add(new object{std::to_string(number)});
      }

      void add(const JsonObject& obj)
      {
            flag = true;
            for(size_t i = 0; i < obj.size(); i++)
            {
                  array_pair.add(&obj.get_object(i));
            }
      }   
      //ARRAY_STR
      void word(string& aux, size_t i)
      {
          
            aux += COMILLA;
            aux += array_str[i].get_str();
            aux += COMILLA;
      }

      void number(string& aux, size_t i)
      {
          
            aux += array_str[i].get_str();
      }

      //ARRAY_PAIR
      void word_pair(string& aux, size_t i)
      {
          
            aux += COMILLA;
            aux += array_pair[i].get_str();
            aux += COMILLA;
            aux += PUNTOS;
            aux += SPACE;
      }

      void word_pair_dos(string& aux, size_t i)
      {
            aux += COMILLA;
            aux += array_pair[i].get_str();
            aux += COMILLA;
      }

      void array_pair_number(string& aux, size_t i)
      {
            aux += array_pair[i].get_str();
      }

      string to_string(bool band = false)
      {
            string aux;
            aux += OPENBRACK;
          
            for(size_t i = 0; i < array_str.size(); i++)
            {
                  if(band)
                  {
                        //implement JSONarray
                        if(i == array_str.size()-1)
                        {
                              aux += TAB;
                              number(aux, i);
                        }
                        else
                        {
                              aux += ENDL;
                              aux += TAB;
                              word(aux, i);
                              //implementar JSONobject
                              aux += COMA;
                              aux += ENDL;
                              aux += TAB;
                              aux += OPENKEY;
                              aux += ENDL;
                              aux += TAB;
                              aux += TAB;
                            
                              for(size_t i = 0; i < array_pair.size(); i++)
                              {
                                    word_pair(aux, i);
                                    i++;
                                    if(i == array_pair.size()-1)
                                    {
                                          array_pair_number(aux, i);
                                    }
                                    else
                                    {
                                          word_pair_dos(aux, i);
                                          aux += COMA;
                                          aux += ENDL;
                                          aux += TAB;
                                          aux += TAB;
                                    }
                              }
                              aux += ENDL;
                              aux += TAB;
                              aux += CLOSEKEY;
                              aux += COMA;
                        }
                        aux += ENDL;
                  }
                  else if(flag == true)
                  {
                        //implement test 6
                        if(i == array_str.size()-1)
                              number(aux, i);
                        else
                        {
                              word(aux, i);
                              aux += COMA;
                              aux += SPACE;
                              aux += OPENKEY;
                              aux += SPACE;
                            
                              for(size_t i = 0; i < array_pair.size(); i++)
                              {
                                    word_pair(aux, i);
                                    i++;
                                    if(i == array_pair.size()-1)
                                    {
                                          array_pair_number(aux, i);
                                    }
                                    else
                                    {
                                          word_pair_dos(aux, i);
                                          aux += COMA;
                                          aux += SPACE;
                                    }
                              }
                              aux += SPACE;
                              aux += CLOSEKEY;
                              aux += COMA;
                              aux += SPACE;
                        }
                  }
                  else
                  {
                        if(i == 0)
                        {
                              number(aux, i);
                              aux += COMA;
                              aux += SPACE;
                        }
                        else
                        {
                              if(i == array_str.size()-1)
                                    word(aux, i);
                              else
                              {
                                    word(aux, i);
                                    aux += COMA;
                                    aux += SPACE;
                              }
                        }
                  }
            }
            aux += CLOSEBRACK;
            return aux;
      }

      size_t size() const
      {
            return array_str.size();
      }

      object& get_object(size_t position) const
      {
            return array_str[position];
      }

};

//IMPLEMENT JSON_OBJECT
JsonObject::JsonObject()
:flag{false} { }
JsonObject::~JsonObject() { }

void JsonObject::add(const string& key, const string& value)
{
      array_pair.add(new object{key});
      array_pair.add(new object{value});
}

void JsonObject::add(const string& key, size_t value)
{
      array_pair.add(new object{key});
      array_pair.add(new object{std::to_string(value)});
}
size_t JsonObject::size() const
{
      return array_pair.size();
}

object& JsonObject::get_object(size_t position) const
{
      return array_pair[position];
}

void JsonObject::add(const string& ingrediente, JsonArray& obj)
{
      flag = true;
      array_str.add(new object{ingrediente});
    
      for(size_t i = 0; i < obj.size(); i++)
      {
            array_str.add(&obj.get_object(i));
      }
}

void JsonObject::word(string& aux, size_t i)
{
      aux += COMILLA;
      aux += array_str[i].get_str();
      aux += COMILLA;
}

void JsonObject::word_pair(string& aux, size_t i)
{
      aux += COMILLA;
      aux += array_pair[i].get_str();
      aux += COMILLA;
}


string JsonObject::to_string(bool band = false, size_t n = 0)
{
      string aux;
      aux += OPENKEY;
    
      if(band == true)
      {
            aux += ENDL;
            aux += TAB2;
            for(size_t i = 0; i < array_pair.size(); i++)
            {
                  if(i == n-1)
                  {
                        word_pair(aux, i);
                        aux += COMA;
                  }
                  else
                  {
                        word_pair(aux, i);
                        aux += PUNTOS;
                        aux += SPACE;
                  }
            }
            aux += ENDL;
            aux += TAB2;
          
            for(size_t i = 0; i < array_str.size(); i++)
            {
                  if(i == 0)
                  {
                        word(aux, i);
                        aux += PUNTOS;
                        aux += SPACE;
                        aux += OPENBRACK;
                        aux += ENDL;
                  }
                  else
                  {
                        if(i == array_str.size()-1)
                        {
                              aux += TAB;
                              word(aux, i);
                              aux += ENDL;
                        }
                        else
                        {
                              aux += TAB;
                              word(aux, i);
                              aux += COMA;
                              aux += ENDL;
                        }
                  }
            }
            aux += TAB2;          
            aux += CLOSEBRACK;
            aux += ENDL;
      }
      else if(flag == true)
      {
            aux += SPACE;
            for(size_t i = 0; i < array_pair.size(); i++)
            {
                  if(i == array_pair.size()-1)
                  {
                        word_pair(aux, i);
                        aux += COMA;
                  }
                  else
                  {
                        word_pair(aux, i);
                        aux += PUNTOS;
                        aux += SPACE;
                  }
            }
            aux += SPACE;
            for(size_t i = 0; i < array_str.size(); i++)
            {
                  if(i == 0)
                  {
                        word(aux, i);
                        aux += PUNTOS;
                        aux += SPACE;
                        aux += OPENBRACK;
                  }
                  else
                  {
                        if(i == array_str.size()-1)
                        {
                              aux += SPACE;
                              word(aux, i);
                        }
                        else
                        {
                              aux += SPACE;
                              word(aux, i);
                              aux += COMA;
                        }
                  }
            }
            aux += SPACE;
            aux += CLOSEBRACK;
            aux += SPACE;
      }
      else
      {
            for(size_t i = 0; i < array_pair.size(); i++)
            {
                  aux += SPACE;
                  word_pair(aux, i);
                  aux += PUNTOS;
                  aux += SPACE;
                  i++;
                  if(i == array_pair.size()-1)
                  {
                        aux += array_pair[i].get_str();
                        aux += SPACE;
                  }
                  else
                  {
                        word_pair(aux, i);
                        aux += COMA;
                  }
            }
      }
      aux += CLOSEKEY;
      return aux;
}

bool test0()
{
    JsonNumber jn { 3141 };
    return jn.to_string() == "3141";
}

bool test1()
{
    JsonObject jo;
    cout << jo.to_string() << "\n";
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

bool test5()
{
    JsonObject jo;
    jo.add("firstName", "John");
    jo.add("lastName", "Smith");
    jo.add("birthYear", 1977);
    return jo.to_string() == "{ \"firstName\": \"John\", \"lastName\": \"Smith\", \"birthYear\": 1977 }";
}

bool test6()
{
    JsonArray ja;
    ja.add("hello");

    JsonObject jo;
    jo.add("firstName", "John");
    jo.add("lastName", "Smith");
    jo.add("birthYear", 1977);

    ja.add(jo);

    ja.add(1492);

    return ja.to_string() == "[\"hello\", { \"firstName\": \"John\", \"lastName\": \"Smith\", \"birthYear\": 1977 }, 1492]";
}

bool test7()
{
    JsonObject jo;

    jo.add("nombre", "jugo de frutas");

    JsonArray ingredients;
    ingredients.add("leche");
    ingredients.add("frutilla");
    ingredients.add("manzana");
    ingredients.add("azucar");

    jo.add("ingredientes", ingredients);
    return jo.to_string() == "{ \"nombre\": \"jugo de frutas\", \"ingredientes\": [ \"leche\", \"frutilla\", \"manzana\", \"azucar\" ] }";
}

bool test8()
{
    JsonArray ja;
    ja.add("hello");

    JsonObject jo;
    jo.add("firstName", "John");
    jo.add("lastName", "Smith");
    jo.add("birthYear", 1977);

    ja.add(jo);

    ja.add(1492);

    return ja.to_string(true) ==
    "[\n"
    "    \"hello\",\n"
    "    {\n"
    "        \"firstName\": \"John\",\n"
    "        \"lastName\": \"Smith\",\n"
    "        \"birthYear\": 1977\n"
    "    },\n"
    "    1492\n"
    "]";
}

bool test9()
{
    JsonObject jo;

    jo.add("nombre", "jugo de frutas");

    JsonArray ingredients;
    ingredients.add("leche");
    ingredients.add("frutilla");
    ingredients.add("manzana");
    ingredients.add("azucar");

    jo.add("ingredientes", ingredients);

    return jo.to_string(true, 2) ==
    "{\n"
    "  \"nombre\": \"jugo de frutas\",\n"
    "  \"ingredientes\": [\n"
    "    \"leche\",\n"
    "    \"frutilla\",\n"
    "    \"manzana\",\n"
    "    \"azucar\"\n"
    "  ]\n"
    "}";
}

int main()
{
    size_t score = 0;
    score += test1();
    score += test2();
    score += test0();
    score += test3();
    score += test4();
    score += test5();
    score += test6();
    score += test7();
    score += test8();
    score += test9();

    cout << "Score: " << score << " / 10\n";
}

