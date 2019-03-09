#include<iostream>
#include<vector>
using namespace std;

const string MARKER = "/";

class Element
{
    protected:
    string m_elementName;
    public:
        Element(const string &p_elementName)
        :m_elementName{p_elementName}
        { }
        ~Element() { }
};

class Group : public Element
{
private:
    
public:
    Group(const string &p_groupName) 
    :Element{p_groupName}
    { }

    ~Group() { }
};

template<typename T>
class Node
{
    protected:
        T* m_object = nullptr;
        string m_key;
        vector<Node<T> *> m_children;

        Node<T> * verifyExistence(const string &p_key) const
        {
            for(auto e : m_children)
            {
                if(e->m_key == p_key)
                {
                    return e;
                }
            }
            return nullptr;
        }
    public:
        Node(const string& p_key)
        :m_key{p_key}
         { }

        Node<T> * addChild(const string& p_key, T* p_object)
        {
            if(verifyExistence(p_key) == nullptr)
            {
                auto node = new Node<T>(p_key);
                m_children.push_back(node);
                m_object = p_object;
                return node;
            }
            return nullptr;
        }
        Node<T> * get(const string& p_key)
        {
            Node<T> * node = verifyExistence(p_key);
            if(node != nullptr)
            {
                return node;
            }
            return nullptr;
        }

        void showAll()
        {
            cout << this -> m_key << "*\n";
            for(auto& i : m_children)
            {
                i -> showAll();
            }
        }

        void serialize(FILE* p_file)
        {
            fprintf(p_file, "%s ", m_key.c_str()); 
            for (auto& e : m_children) 
            {
                e->serialize(p_file);
            }
            fprintf(p_file, "%s ", MARKER.c_str()); 
        }

        void deserialize(FILE* p_file)
        {
            
        }

        ~Node()
        {
            
        }
};

template<typename T>
class Tree : public Node<T>
{
    public:
        Tree(const string& p_key)
        :Node<T>{p_key}
         { }
        ~Tree() { }
};

int main()
{
    Tree<Element> arbol("Root");
    // Node* nodo = arbol.getRoot();
    arbol.addChild("nodo1", new Group{"album1"});
    arbol.addChild("nodo2", new Group{"album2"});
    arbol.addChild("nodo3", new Group{"album2"});
    arbol.get("nodo3") -> addChild("nodo3.1", new Group{"album10"}) -> addChild("nodo3.1.1", new Group{"album11"});
    arbol.get("nodo2")->addChild("nodo2.1", new Group{"album2"});

    arbol.showAll();

    FILE *fp = fopen("tree.txt", "w");
    arbol.serialize(fp);
}