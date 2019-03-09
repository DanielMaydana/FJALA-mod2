#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <string>
#include <memory>
#include <map>
using namespace std;

constexpr string_view HEADER = "<? xml version=\"1.0\" ?>";
constexpr string_view CLOSE = ">";
constexpr string_view OPEN = "<";
constexpr string_view SLASH = "/";
constexpr string_view QUOTE = "\"";
constexpr string_view EQUAL = "=";
constexpr string_view SPACE = " ";
constexpr string_view DASH = "-";
constexpr string_view ADMS = "!";

class document;
class element;
class comment;
class text;

using node = variant<shared_ptr<element>, shared_ptr<comment>, shared_ptr<text>>;

void spaces(string& str, size_t n = 4)
{
    for(auto i = 0U; i < n; i++) str += " ";
}

string check_special_characters(const string& incoming_str)
{
    string out_str;
    for(auto& i : incoming_str)
    {
        switch(i)
        {
            case '<': out_str += " &lt"; break;
            case '>': out_str += " &gt"; break;
            case '&': out_str += " &amp"; break;
            case '\'': out_str += " &apos"; break;
            case '\"': out_str += " &quot"; break;
            default: out_str += i;
        }
    }
    return out_str;
}

// *****************************************************

class text
{
private:
    string tex_name;
public:
    text(const string& tex_name) : tex_name{tex_name} 
    { }

    ~text()
    { }

    void serialize(string& str)
    {
        str = str + check_special_characters(tex_name);
    }
};

// *****************************************************

class comment
{
private:
    string com_name;
public:
    comment(const string& com_name) : com_name{com_name}
    { }
    ~comment() { }

    void serialize(string& str)
    {
        spaces(str);
        str += OPEN;
        str += ADMS;
        str += DASH;
        str += DASH;
        str += SPACE;
        str += check_special_characters(com_name);
        str += SPACE;
        str += DASH;
        str += DASH;
        str += CLOSE;
    }
};

// *****************************************************

class element
{
private:
    
    string ele_name;
    vector<node>children;
    map<string, string> atributes;

public:
    element(const string& ele_name) : ele_name{ele_name}
    {

    }

    ~element() { }

    void set_attribute(const string& atr_name, const string& atr_value)
    {
        atributes.insert(make_pair(atr_name, atr_value));
    }

    template<typename UU>
    void append_child(const UU& ele)
    {
        children.push_back(ele);
    }

    void serialize(string& str)
    {
        spaces(str);
        str += OPEN;
        str += check_special_characters(ele_name);

        if(atributes.size() != 0)
        {
            for(auto& i : atributes)
            {
                str += SPACE;
                str += i.first;
                str += EQUAL;
                str += QUOTE;
                str += i.second;
                str += QUOTE;
            }
        }
        str += CLOSE;

        if(children.size() != 0)
        {
            str += "\n";
            spaces(str, 8);
            for (auto &node_visit : children){

                visit(
                    [&str](auto &e) {
                        e->serialize(str);
                        str += "\n";
                    },
                    node_visit
                );
            }
            spaces(str, 4);
            str += OPEN;
            str += SLASH;
            str += check_special_characters(ele_name);
            str += CLOSE;
        }
        // else
        // {

        // }
    }

    // map<string, string> gimme_attr(){
    //     return atributes;
    // }
};

// *****************************************************

class document
{
    string doc_name;
    vector<node> children;

public:
    document(const string& doc_name) : doc_name{doc_name}
    {}

    shared_ptr<element> create_element(const string& ele_name)
    {
        return make_shared<element>(ele_name);
    }

    shared_ptr<comment> create_comment(const string& com_name)
    {
        return make_shared<comment>(com_name);
    }

    shared_ptr<text> create_text(const string& tex_name)
    {
        return make_shared<text>(tex_name);
    }

    template<typename TT>
    void append_child(const TT& ele)
    {
        children.push_back(ele);
    }

    string serialize(int = -1)
    {
        string main_str = string{HEADER};
        main_str += "\n";
        main_str += OPEN;
        main_str += check_special_characters(doc_name);
        main_str += CLOSE;
        main_str += "\n";        

        if(children.size() != 0)
        {
            for(auto& node_visit : children)
            {
                visit(
                    [&main_str](auto &e){
                        e -> serialize(main_str);
                        main_str += "\n";
                    },
                    node_visit
                );
            }
        }
        main_str += OPEN;
        main_str += SLASH;
        main_str += check_special_characters(doc_name);
        main_str += CLOSE;
        return main_str; 
    }
};

// *****************************************************

class xml_writer
{
public:
    xml_writer() { }
    ~xml_writer() { }
    document create_document(const string& doc_name)
    {
        return document{doc_name};
    }
};
// -----------------------------------------------------

ostream& operator<<(ostream& os, document& ws)
{
    return os << ws.serialize(4);
}

int main()
{
    xml_writer ws;
  
    auto doc = ws.create_document("students");

    auto e1 = doc.create_element("student");
    e1->set_attribute("name", "Juan Perez");
    e1->set_attribute("age", "22");
    e1->set_attribute("id", "2193281");

    // auto eg = e1->gimme_attr();
    // for(auto& i : eg) std::cout << i.second << "\n";

    auto e2 = doc.create_element("student");
    e2->set_attribute("name", "Jorge Lopez");
    e2->set_attribute("age", "25");
    e2->set_attribute("id", "12312312");

    doc.append_child(e1);
    doc.append_child(e2);

    auto c = doc.create_comment("This is a comment ><&&''\"");
    doc.append_child(c);

    auto e3 = doc.create_element("info");
    doc.append_child(e3);

    auto text = doc.create_text("This is a text ");
    e3->append_child(text);

    cout << doc << "\n";
}