
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <variant>
#include <memory>
#include <map>

using namespace std;
class element;
class comment;
class text;

using node = variant<shared_ptr<element>, shared_ptr<comment>, shared_ptr<text>>;

/////////////////////////////TEXT/////////////////////
class text
{
    string_view value;

  public:
    text(const string_view &value) : value{value}
    { }

    string serializable() const
    {
        string json;
        json += "    ";
        json += value;
        return json;
    }
};
/////////////////////////////COMMENT//////////////////
class comment
{
    string_view value;

public:
    comment(const string_view &value) : value{value}
    { }

    string serializable() const
    {
        string json;
        json += "    <!-- ";
        json += value;
        json += " -->";

        return json;
    }
};
/////////////////////////////ELEMENT//////////////////
class element
{
    string_view name_element;
    vector<node> children;
    map<string, string> atributes;

public:

    element(const string_view &name_element) : name_element{name_element}
    { }

    void set_attribute(const string_view &key, const string_view &value)
    {
        atributes.insert(make_pair(key, value));
    }

    template <typename T>
    void append_child(const T &child)
    {
        children.push_back(child);
    }

    string serializable() const
    {
        string json;
        json += "    <";
        json += name_element;
        for (auto &m : atributes)
        {
            json += " ";
            json += m.first;
            json += "=";
            json += "\"";
            json += m.second;
            json += "\"";
        }
        if (children.size() == 0)
        {
            json += " />";
            return json;
        }
        else
        {
            json += ">\n";
            for (auto &c : children)
            {
                json += "    ";
                visit(
                    [&json](auto &e) { json += e->serializable(); },
                    c // each type of the variant
                );
            }
            json += "\n    <";
            json += name_element;
            json += "/>";
        }

        return json;
    }
};
////////////////////////////DOCUMENT////////////////////////////////////
class document
{
  string name_document;
  vector<node> children;
  int count = -1;

public:
    document(const string_view &name_document)
        : name_document{name_document}
    {
    }

    shared_ptr<element> create_element(const string_view &name_element)
    {
        return make_shared<element>(name_element);
    }

    shared_ptr<comment> create_comment(const string_view &value)
    {
        return make_shared<comment>(value);
    }

    shared_ptr<text> create_text(const string_view &value)
    {
        return make_shared<text>(value);
    }

    template <typename T>
    void append_child(const T &child)
    {
        children.push_back(child);
    }

    string serializable() const
    {
    string json;
    json += "<? xml version=\"1.0\" ?>\n";
    json += "<";
    json += name_document;
    if (children.size() != 0)
    {
        json += ">\n";
        for (auto &node_to_visit : children)
        {
            visit(
                [&json](auto &c) {
                    json += c->serializable();
                    json += "\n";
                },
                node_to_visit // node according to type
            );
        }
        json += "<";
        json += name_document;
        json += "/>";
        return json;
    }
    return json += "/>\n";
    }
};
/////////////////////////////XML_WRITER///////////////
class xml_writer
{
public:
    document create_document(const string_view &name_document)
    {
        return document{name_document};
    }
};

////////////////////////////OTHERS//////////////////////////////
ostream &operator<<(ostream &os, const document &doc)
{
    return os << doc.serializable();
}

int main()
{
    xml_writer ws;

    auto doc = ws.create_document("students");
    auto e1 = doc.create_element("student");
    e1->set_attribute("name", "Juan Perez");
    e1->set_attribute("age", "22");
    e1->set_attribute("id", "2193281");

    auto e2 = doc.create_element("student");
    e2->set_attribute("name", "Jorge Lopez");
    e2->set_attribute("age", "25");
    e2->set_attribute("id", "12312312");
    doc.append_child(e1);
    doc.append_child(e2);

    auto c = doc.create_comment("This is a comment");
    doc.append_child(c);

    auto e3 = doc.create_element("info");
    doc.append_child(e3);

    auto text = doc.create_text("This is a text ");
    e3->append_child(text);

    cout << doc << "\n";
}

//   /*
// //Sin herencia, sin polimorfismo, sin raw pointers
// <? xml version="1.0" ?>
// <students>
//   <student name="Juan Perez" age="22" id="2193281" />
//   <student name="Jorge Lopez" age="25" id="12312312" />
//   <!-- This is a comment -->
//   <info>
//     This is a text
//   </info>
// </students>
// */
