// metodos de balanceo de arboles, implementarlos    
    // AVL  
    // RED BLACK TREE


#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct default_less
{
    bool is_less(const T& a, const T& b)const
    {
        return a < b;
    }
};

template <typename T, typename LESS = default_less<T>>  // LESS = default_less<T>  que exactamente significa??? 
class Tree
{
private:
    struct Node
    {
        T elem;
        Node* left;
        Node* right;
    };

    Node* root;
    LESS c;

public:
    Tree() 
    :root{nullptr}
    { }
    
    ~Tree() 
    { 
        release(root);
    }

    void release(Node* node)
    {
        if(node == nullptr) 
            return;

        release(node->left);
        release(node->right);
        // cout << node->elem <<"node deleted\n";
        delete node; 
    }
    
    void add(const T& n)    //Cual es la razon de tener un metodo add publico y uno privado????
    {
        // cout << "add public\n";
        add(root, n);
    }

    void print()const
    {
        print(root);
    }

    const T& operator[](const T& e)const
    {
        return find(root, e);
    }

private:
    void add(Node*& node, const T& n)
    {
        // cout << "add private\n";
        if (node == nullptr)
        {
            node = new Node{n, nullptr, nullptr};
            return;
        }
        
        bool less = c.is_less(n, node->elem);  // si da un error aca es posible que el error sea al momento de instanciar
        if(less)
            add(node->left, n);
        else
            add(node->right, n);
    }

    void print(Node* node)const
    {
        if(node == nullptr) 
            return;
        print(node->left);
        cout <<node->elem << "\n";
        print(node->right);
    } 

    const T& find(const Node* node, const T& e)const
    {
        if(node == nullptr)
            // cout << "not found\n";  // esta linea provoca un warning
            throw "NOT FOUND";  // este throw cuida que el if funcione bien, como lo hace???
        bool less = c.is_less(e, node->elem);
        if(less)
            return find(node->left, e);
        if(c.is_less(node->elem, e))
            return find(node->right, e);
        return node->elem;        
    }

};

int main()
{
    Tree<int> p;
    p.add(14);
    p.add(50);
    p.add(22);
    p.add(25);
    p.add(15);
    p.print();

    Tree<string> s;
    s.add("hello");
    s.add("bye");
    s.add("beer");
    s.add("july"); 
    s.print();

    // auto& q = p[15];
    // cout << q << "\n";

    try
    {
        auto& q = p[15];
        cout << q << "\n";
    }
    catch(const char* s)
    {
        cerr << s << "\n";
    }
    catch(...)
    {
        cerr << "Unknown error\n";
    }
}