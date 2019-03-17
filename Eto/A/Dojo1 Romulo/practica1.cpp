#include<iostream>
#include<vector>
using namespace std;
//Implement everything needed to run this code properly:
class Date
{
    int dia;
    int mes;
    int anio;
    public:
        Date()
        {
            time_t today;
            time(&today);
            tm *info = localtime(&today);
            dia = info->tm_mday;
            mes = info->tm_mon + 1;
            anio = info->tm_year + 1900;
        }
        const int get_day() const
        {
            return dia;
        }
        const int get_month() const
        {
            return mes;
        }
        const int get_year() const
        {
            return anio;
        }
        Date(int dia, int mes, int anio)
            :dia{dia}, mes{mes}, anio{anio}
        {}
        bool operator== (const Date& fe) const
        {
            return dia==fe.dia && mes==fe.mes&&anio==fe.anio;
        }
};
enum class SerializerType
{
    Xml = 0,
    Json = 1
};
enum class DataType
{
    VECTOR = 0,
    STRING = 1,
    NUMBER = 2
};
class object
{
    string name;
    DataType dataType;
    public:
        object(const string& nm,const DataType dtype)
        :name{nm},dataType{dtype}
        {}
        const string get_name() const
        {
            return name;
        }
        DataType get_data_type() const
        {
            return dataType;
        }
        virtual ~object(){}
};
class bas_object: public object
{
    string value;
    public:
        bas_object(const string& nm, DataType dtype,const string& val)
        :object{nm,dtype},value{val}
        {}
        bas_object(const string& nm, DataType dtype,const int val)
        :object{nm,dtype}
        {
            char text[32];
            sprintf(text, "%d", val);
            value = text;
        }
        const string get_value() const
        {
            return value;
        }
};
class arr_object: public object
{
    vector<object*> values;
    public:
        arr_object(const string& nm)
        :object{nm,DataType::VECTOR}
        {
        }
        void add(object* obj)
        {
            values.push_back(obj);
        }
        const vector<object*>& get_values() const
        {
            return values;
        }
        ~arr_object()
        {

            for(size_t i = 0; i < values.size(); i++)
            {
                delete values[i];
            }

        }
};
class serializer
{
    public:
        virtual string& to_str(const arr_object* arr,string& str) = 0;
        virtual ~serializer(){};
};
class json_serializer : public serializer
{
    public:
        string& to_str(const arr_object* arr,string& str)
        {
            str += "\"" + arr->get_name() + "\" : { ";
            for(size_t i = 0; i < arr->get_values().size(); i++)
            {
                if(arr->get_values()[i]->get_data_type() == DataType::VECTOR)
                {
                    to_str((static_cast<arr_object*>(arr->get_values()[i])),str);
                }
                else if(arr->get_values()[i]->get_data_type() == DataType::NUMBER)
                {
                    str += " \"" + arr->get_values()[i]->get_name() + "\" : ";
                    str += (static_cast<bas_object*>(arr->get_values()[i]))->get_value();
                    str += " ,";
                }
                else
                {
                    str += " \"" + arr->get_values()[i]->get_name() + "\" : \"";
                    str += (static_cast<bas_object*>(arr->get_values()[i]))->get_value();
                    str += "\",";
                }
            }
            str += " }";
            return str;
        }
        ~json_serializer(){}

};
class xml_serializer : public serializer
{
    public:
        string& to_str(const arr_object* arr,string& str)
        {
            str += "<" + arr->get_name() + ">";
            for(size_t i = 0; i < arr->get_values().size(); i++)
            {
                if(arr->get_values()[i]->get_data_type() == DataType::VECTOR)
                {
                    to_str((static_cast<arr_object*>(arr->get_values()[i])),str);
                }
                else
                {
                    str += "<" + arr->get_values()[i]->get_name() + ">";
                    str += (static_cast<bas_object*>(arr->get_values()[i]))->get_value();
                    str += "</" + arr->get_values()[i]->get_name() + ">";
                }
            }
            str += "</" + arr->get_name() + ">";
            return str;
        }
        ~xml_serializer(){}
};
class SerializerFactory
{
    public:
    static serializer* get_serializer(const SerializerType type)
    {
        switch(type)
        {
            case SerializerType::Json:
                return new json_serializer();
                break;
            case SerializerType::Xml:
                return new xml_serializer();
                break;
            default:
                return new json_serializer();
                break;
        }
    }
};

class Wrapper
{
    serializer* ser;
    arr_object* obj;
    string parsed = "";
    public:
        void set_serializer(serializer* s)
        {
            ser = s;
        }
        void set_arr_object(arr_object* ob)
        {
            obj = ob;
        }
        const string to_str()
        {
            return ser->to_str(obj,parsed);
        }
        ~Wrapper()
        {

        }
};
class Iserializable
{
    public:
        virtual Wrapper& serialize( serializer* serializer) = 0;
        virtual ~Iserializable(){}
};
class Person : public Iserializable
{
    string first_name;
    string last_name;
    Date date;
    public:
        Person(const string& nom,const string& ape,Date fec)
        :first_name{nom},last_name{ape},date{fec}
        {}
        Wrapper& serialize(serializer* serializer) override
        {
            Wrapper* serialized = new Wrapper();
            arr_object* data = new arr_object{"Person"};
            data->add(new bas_object{"first_name",DataType::STRING,first_name});
            data->add(new bas_object{"last_name",DataType::STRING,last_name});
            arr_object* _date = new arr_object{"date"};
            _date->add(new bas_object{"day",DataType::NUMBER,date.get_day()});
            _date->add(new bas_object{"month",DataType::NUMBER,date.get_month()});
            _date->add(new bas_object{"year",DataType::NUMBER,date.get_year()});
            data->add(_date);
            serialized->set_arr_object(data);
            serialized->set_serializer(serializer);
            return *serialized;
        }

};
class Car : public Iserializable
{
    string id;
    string brand;
    string model;
    int year;
    public:
        Car(const string& _id,const string& _brand,const string& _model,int _year)
        :id{_id},brand{_brand},model{_model},year{_year}
        {}
        Wrapper& serialize(serializer* serializer) override
        {
            Wrapper* serialized = new Wrapper();
            arr_object* data = new arr_object{"Car"};
            data->add(new bas_object{"id",DataType::STRING,id});
            data->add(new bas_object{"brand",DataType::STRING,brand});
            data->add(new bas_object{"model",DataType::STRING,model});
            data->add(new bas_object{"year",DataType::NUMBER,year});
            serialized->set_arr_object(data);
            serialized->set_serializer(serializer);
            return *serialized;
        }
};

int main()
{
    auto p = SerializerFactory::get_serializer(SerializerType::Xml);
    auto q = SerializerFactory::get_serializer(SerializerType::Json);
    auto car = new Car("123ABC", "Volkswagen", "Beetle", 1970);
    auto person = new Person("Juan", "Perez", Date { 10, 2, 1976 });
    auto cp = car->serialize(p);
    auto cq = car->serialize(q);
    auto pp = person->serialize(p);
    auto pq = person->serialize(q);
    cout << cp.to_str() << "\n";
    cout << cq.to_str() << "\n\n";
    cout << pp.to_str() << "\n";
    cout << pq.to_str() << "\n";
    delete car;
    delete person;
    return 0;
}
//Notice I am not explicitly invoking delete for the serializers, think on how to make their destructors to be invoked anyway.
//Should print:
//<car><id>123ABC</id><brand>Volkswagen</brand><model>Beetle</model><year>1970</year></car>
//{ "id": "1234ABC", "brand": "Volkswagen", "model": "Beetle", "year": 1970 }
//
//<person><firstname>Juan</firstname><lastname>Perez</lastname><date><day>10</day><month>2</month><year>1976</year></date></person>
//{ "firstname" : "Juan", "lastname", "Perez", "date" : { "day": 10, "month": 2, "year" : 1976 } //}
//


















// // Implement everything needed to run this code properly:
// #include <iostream>
// #include <cstring>
// #include <stdlib.h>
// using namespace std;

// class String
// {
//   private:
//     size_t len;
//     char *str;

//   public:
//     String(const char *s)
//         : len{strlen(s)} //Initialization list
//     {
//         // str = new char[len+1];
//         str = (char *)malloc(len + 1);
//         memcpy(str, s, len + 1);
//     }

//     String() : String{""} //llama al primer constructor con una cadena vacia
//     {
//     }

//     String(const String &s) //copia
//         : len{s.len}, str{(char *)malloc(s.len + 1)}
//     {
//         memcpy(str, s.str, len + 1);
//     }

//     ~String()
//     {
//         free(str);
//     }

//     String &operator=(const String &s)
//     {
//         if (this == &s)
//             return *this; //si esto compara direcciones de memoria?????????
//         this->~String();

//         len = s.len;
//         str = (char *)malloc(len + 1);
//         memcpy(str, s.str, len + 1);
//         return *this;
//     }

//     const char *c_str() const // no se escribe en la funcion y no modifica el estado del objeto y no se puede llmaar a metodos no constantes
//     {
//         return str;
//     }

//     String operator+(const String &s) const // normalmente es const porque no modifica las cadenas
//     {
//         String aux; // aca ya llama al constructor y el constructor hace el malloc
//         auto nlen = len + s.len;
//         aux.str = (char *)realloc(aux.str, nlen + 1);
//         memcpy(aux.str, str, len);
//         memcpy(aux.str + len, s.str, s.len + 1);
//         aux.len = nlen;
//         return aux;
//     }

//     String &operator+=(const String &s)
//     {
//         auto nlen = len + s.len;
//         str = (char *)realloc(str, nlen + 1);
//         memcpy(str + len, s.str, s.len + 1);
//         len = nlen;
//         return *this;
//     }

//     bool operator==(const String &s) const
//     {
//         bool answer = true;
//         if (len == s.len)
//         {
//             for (size_t i = 0; i < len; i++)
//             {
//                 if (str[i] != s.str[i])
//                 {
//                     answer = false;
//                     return answer;
//                 }
//             }
//         }
//         else
//         {
//             answer = false;
//             return answer;
//         }
//         return answer;
//     }

//     bool operator!=(const String &s) const
//     {
//         bool answer = false;
//         if (len == s.len)
//         {
//             for (size_t i = 0; i < len; i++)
//             {
//                 if (str[i] != s.str[i])
//                 {
//                     answer = true;
//                     return answer;
//                 }
//             }
//         }
//         else
//         {
//             answer = true;
//             return answer;
//         }
//         return answer;
//     }
// };




// enum class SerializerType
// {
//     Xml = 0,
//     Json = 1
// };

// enum class Data_type
// {
//     number = 0,
//     string = 1,
//     vector = 2 
// };



// class objecto
// {
// private:
//     String nombre;
//     Data_type tipo;    
// public:
//     objecto(const String& nombre, Data_type tipo)
//     :nombre{nombre}, tipo{tipo}
//     { }

//     ~objecto() { }
// };

// class array_list
// {
//     objecto **objects;
//     size_t len;
//     bool owner;

//   public:
//     array_list(bool owner = true)
//     :objects{(objecto **)malloc(0)}, len{0}, owner{owner}
//     {
//     }

//     ~array_list() 
//     {
//         // implementar //---------------------------
//     }

//     size_t size() const
//     {
//         return len;
//     }
//     void add(objecto * obj)
//     {
//         objects = (objecto **)realloc(objects, (len + 1) * sizeof(objecto *));
//         objects[len] = obj;
//         len++;
//     }

//     objecto &operator[](size_t index)
//     {
//         return *(objects[index]);
//     }

//     const objecto &operator[](size_t index) const
//     {
//         return *(objects[index]);
//     }

//     // void mostrar() const
//     // {
//     //     for (size_t i = 0; i < len; i++)
//     //     {
//     //         (*this)[i].mostrar();
//     //     }
//     // }

//     // const objecto &get_object(const objecto &) const
//     // {
//     //     for (size_t i = 0; i < len; i++)
//     //     {
//     //         if ((*this)[i].equals_to(obj))
//     //             return (*this)[i];
//     //     }
//     //     throw 0;
//     // }

//     // objecto &get_object(const objecto &)
//     // {
//     //     for (size_t i = 0; i < len; i++)
//     //     {
//     //         if ((*this)[i].equals_to(obj))
//     //             return (*this)[i];
//     //     }
//     //     throw 0;
//     // }
// };


// class Objetito : public objecto
// {
// private:
//     String value;
// public:
//     Objetito(String value, const String& nombre, Data_type tipo) 
//     :value{value}, objecto{nombre, tipo}
//     { }

//     Objetito(int value, const String& nombre, Data_type tipo) 
//     :objecto{nombre, tipo}
//     {
//         char aux_anho[10];
//         sprintf(aux_anho, "%d", value);
//         String aux_string{aux_anho};
//         this->value = aux_string;
//     }

//     ~Objetito() { }
// };

// class Vector_objeto : public objecto
// {
// private:
//     array_list array_values;
// public:
//     Vector_objeto(String nombre) 
//     :objecto{nombre, Data_type::vector}
//     { }   

//     ~Vector_objeto() 
//     { }    

//     void add(objecto* new_object)
//     {
//         array_values.add(new_object);
//     }
// };




// class Serializer_abstract
// {
//   private:
//   public:
//     Serializer_abstract() {}
//     ~Serializer_abstract() {}
//     virtual String& to_str() =0;
// };

// class Serializer_xml : public Serializer_abstract
// {
//   private:
//   public:
//     Serializer_xml() {}
//     ~Serializer_xml() {}
//     String& to_str() override
//     {
//         String a = "ser xml\n";
//         return a;
//     }
// };

// class Serializer_json : public Serializer_abstract
// {
//   private:
//   public:
//     Serializer_json() {}
//     ~Serializer_json() {}
//     String& to_str() override
//     {
//         String a = "ser json\n";
//         return a;
//     }
// };

// class SerializerFactory
// {
//   private:
//   public:
//     SerializerFactory() {}

//     ~SerializerFactory() {}

//     static Serializer_abstract *get_serializer(SerializerType type)
//     {
//         switch (type)
//         {
//         case SerializerType::Json:
//             return new Serializer_json{};
//             break;

//         case SerializerType::Xml:
//             return new Serializer_xml{};
//             break;

//         default:
//             return nullptr;
//         }
//     }
// };


// class Wraper
// {
// private:
//     Vector_objeto* objetos;
//     Serializer_abstract* serialize;
//     String text_result = "";
// public:
//     Wraper(Vector_objeto* objectos, Serializer_abstract* serialize) 
//     :objetos{objetos}, serialize{serialize}
//     { }
    
//     ~Wraper() { }

//     String& to_str()
//     {
//         return (serialize ->to_str());
//     }
// };

// class ISerializer
// {
//   private:
//   public:
//     ISerializer() {}

//     virtual ~ISerializer() {}

//     virtual Wraper& serialize(Serializer_abstract* sa) = 0;
// };

// class Car : public ISerializer
// {
//   private:
//     String id;
//     String brand;
//     String model;
//     size_t year;

//   public:
//     Car(String id, String brand, String model, size_t year)
//         : id{id}, brand{brand}, model{model}, year{year}
//     {
//     }
//     ~Car() {}

//     Wraper& serialize(Serializer_abstract* sa) override
//     {
//         Vector_objeto* car_vector = new Vector_objeto{"car"};
//         car_vector->add(new Objetito{id,"id",Data_type::string});
//         car_vector->add(new Objetito{brand,"brand",Data_type::string});
//         car_vector->add(new Objetito{model,"model",Data_type::string});
//         car_vector->add(new Objetito{year,"year",Data_type::number});
//         Wraper* resultado = new Wraper{car_vector, sa};
//         return *resultado;
//     }
// };

// class Date
// {
//   private:
//     size_t dia;
//     size_t mes;
//     size_t anho;

//   public:
//     Date(size_t dia, size_t mes, size_t anho)
//         : dia{dia}, mes{mes}, anho{anho}
//     {
//     }
//     ~Date() {}
// };



// class Person : public ISerializer
// {
//   private:
//     String nombre;
//     String apellido;
//     Date date;

//   public:
//     Person(const String &nombre, const String &apellido, Date date)
//         : nombre{nombre}, apellido{apellido}, date{date}
//     {
//     }

//     ~Person() {}

//     Wraper& serialize(Serializer_abstract* sa) override
//     {
//         Vector_objeto* car_vector = new Vector_objeto{"car"};
//         Wraper* resultado = new Wraper{car_vector, sa};
//         return *resultado;
//     }
// };

// int main()
// {
//     auto p = SerializerFactory::get_serializer(SerializerType::Xml);
//     auto q = SerializerFactory::get_serializer(SerializerType::Json);
//     auto car = new Car("123ABC", "Volkswagen", "Beetle", 1970);
//     auto person = new Person("Juan", "Perez", Date{10, 2, 1976});
//     auto cp = car->serialize(p);
//     auto cq = car->serialize(q);
//     auto pp = person->serialize(p);
//     auto pq = person->serialize(q);
//     cout << cp.to_str().c_str() << "\n";
//     cout << cq.to_str().c_str() << "\n\n";
//     cout << pp.to_str().c_str() << "\n";
//     cout << pq.to_str().c_str() << "\n";
//     delete car;
//     delete person;
// }

// //Notice I am not explicitly invoking delete for the serializers, think on how to make their destructors to be invoked anyway.

// //Should print:

// //<car><id>123ABC</id><brand>Volkswagen</brand><model>Beetle</model><year>1970</year></car>

// //{ "id": "1234ABC", "brand": "Volkswagen", "model": "Beetle", "year": 1970 }

// //

// //<person><firstname>Juan</firstname><lastname>Perez</lastname><date><day>10</day><month>2</month><year>1976</year></date></person>

// //{ "firstname" : "Juan", "lastname", "Perez", "date" : { "day": 10, "month": 2, "year" : 1976 } }
