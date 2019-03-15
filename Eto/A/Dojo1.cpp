#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class String
{
private:
    size_t len;
    char* str;
public:
    String(const char* s) 
    :len{strlen(s)}
    { 
        str = (char*)malloc(len+1);
        memcpy(str, s, len+1);
    }

    String() : String{""}  //llama al primer constructor con una cadena vacia
    {}

    String(const String& s)   //copia
    :len{s.len}, str{(char*) malloc(s.len+1)}
    {
        memcpy(str, s.str, len+1);
    }

    ~String() 
    { 
        free(str);
    }

    String& operator = (const String& s)
    {
        if(this == &s) return *this;
        this->~String();
        
        len = s.len;
        str = (char*) malloc(len+1);
        memcpy(str, s.str, len+1);
        return *this;
    }

    const char* c_str() const  // no se escribe en la funcion y no modifica el estado del objeto y no se puede llmaar a metodos no constantes
    {
        return str;
    }

    String operator + (const String& s) const 
    {
        String aux;  
        auto nlen = len + s.len;
        aux.str = (char*)realloc(aux.str, nlen+1);
        memcpy(aux.str, str, len);
        memcpy(aux.str + len, s.str, s.len+1);
        aux.len = nlen;
        return aux;
    }

    String& operator += (const String& s)
    {
        auto nlen = len + s.len;
        str = (char*) realloc(str, nlen+1);
        memcpy(str+len, s.str, s.len+1);
        len = nlen;
        return *this;
    }

    bool operator == (const String& s) const
    {
        bool answer = true;
        if(len == s.len)
        {
            for(size_t i = 0; i < len; i++)
            {
                if(str[i] != s.str[i])
                {
                    answer = false;
                    return answer;
                }
            }
        }
        else 
        {
            answer = false;
            return answer;
        }
        return answer;
    }

    bool operator != (const String& s) const
    {
        bool answer = false;
        if(len == s.len)
        {
            for(size_t i = 0; i < len; i++)
            {
                if(str[i] != s.str[i])
                {
                    answer = true;
                    return answer;
                }
            }
        }
        else 
        {
            answer = true;
            return answer;
        }
        return answer;
    }
};




class sistema_facturacion;

class object // class --------------------
{
private:
    
public:
    object() { }
    virtual ~object() { }
    virtual void mostrar() const = 0; 
};

class array_list : public object // class --------------------
{
private:
    object** list;
    size_t count;
public:
    array_list() 
    :list{(object**)malloc(0)}, count{0}
    { }
    
    ~array_list() { }

    size_t size()
    {
        return count;
    }

    const object& operator[](size_t index) const
    {
        return *list[index];
    }

    object& operator[](size_t index)
    {
        return *list[index];
    }

    void add(object* new_object)
    {
        list = (object**)realloc(list, (count+1)*sizeof(object*));
        list[count] = new_object;
        count++;
    }

    void mostrar() const override
    {
        for(size_t i = 0U; i < count; i++)
        {
            cout << i + 1 << ".- \t";
            (*this)[i].mostrar();   // porque no funciona con (*list), es como si solo entrara una vez al siclo.
        }
        cout << "\n";
    }

    // String get_id()const
    // {
    //     return 
    // }
};

class producto : public object  // class --------------------
{
private:
    String name;
    String brand;
    String id;
    size_t stock;
    double price;

public:
    producto(const String& name, const String& brand, const String& id, size_t stock, double price)
    :name{name}, brand{brand}, id{id}, stock{stock}, price{price}
    { }

    ~producto() { }

    void mostrar() const override
    {
        cout << "producto\n";
    }
};


class item : public object  // class --------------------
{
private:
    size_t quantity;
    String id;
    array_list& prod_finder;
    sistema_facturacion& sis;
public:
    // item(size_t quantity, String id, sistema_facturacion sis)
    // :quantity{quantity}, id{id}, sis{sis}
    item(size_t quantity, String id)
    :quantity{quantity}, id{id}
    {
        // cout << "item ";
    }

    ~item() { }

    void get_array_list_prod() // tal vez no es necesario
    {
        prod_finder = sis.get_array(); 
    }



    void mostrar() const override
    {
        prod_finder = sis.get_array();
        
        for(size_t i = 0; i < prod_finder.size(); i++)
        {
            if(id.c_str() == prod_finder[i].)//////////////////////////////////////////
            {

            }
        }
        

        cout << quantity << "\t" << id.c_str() << "\n";
    }
};

class factura : public object  // class --------------------
{
private:
    String name;
    String nit;
    array_list item_list;
    double descuento;
    // sistema_facturacion& sis;
public:
    // factura(String name, String nit, sistema_facturacion& sis) 
    // :name{name}, nit{nit}, sis{sis}
    factura(String name, String nit) 
    :name{name}, nit{nit}
    { }

    ~factura() { }

    void agregar_item(size_t quantity, String id)
    {
        // item* new_item = new item{quantity, id, sis};
        item* new_item = new item{quantity, id};
        item_list.add(new_item);
    }

    void agregar_descuento(double p_descuento)
    {
        descuento += p_descuento;
    }

    void mostrar() const override
    {
        cout << "Nombre: " << name.c_str() << "\t\t" << "Nit: " << nit.c_str() << "\n";
        cout << "Items: \n";
        item_list.mostrar(); 
    }
};


class sistema_facturacion  // class --------------------
{
private:
    array_list product_list;
    array_list factura_list;
public:
    sistema_facturacion() { }
    
    ~sistema_facturacion() { }

    void agregar_producto(const String& name, const String& brand, const String& id, size_t stock, double price)
    {
        producto* new_product = new producto{name, brand, id, stock, price};
        product_list.add(new_product);
        // return *new_product;
    }

    factura& crear_factura (String name, String nit)
    {
        // factura* new_factura = new factura{name, nit, *this};
        factura* new_factura = new factura{name, nit};
        factura_list.add(new_factura);
        return *new_factura;
    }

    factura& crear_factura (String name)
    {
        // factura* new_factura = new factura{name, "0", *this};
        factura* new_factura = new factura{name, "0"};
        factura_list.add(new_factura);
        return *new_factura;
    }

    array_list obtener_facturas_de_hoy()
    {
        array_list aux;
        
        for(size_t i = 0; i < factura_list.size(); i++)
        {
            aux.add((object*)&(factura_list[i]));
        }
        return aux;
    }

    const array_list get_array()const
    {
        return product_list;
    }
};


int main()
{

    sistema_facturacion sf;

    sf.agregar_producto("Leche", "PIL", "1245235423451", 50, 5);
    sf.agregar_producto("Yogurt", "PIL", "4245845254", 20, 15);
    sf.agregar_producto("Paneton", "IC Norte", "2390482394283", 500, 22.50);

    auto &f = sf.crear_factura("Omar Vera", "1029382015");
    f.agregar_item(1, "1245235423451");
    f.agregar_item(2, "2390482394283");

    auto &g = sf.crear_factura("Juan Pedro");
    g.agregar_item(2, "1245235423451");
    g.agregar_item(1, "4245845254");
    g.agregar_descuento(5);

    auto fc = sf.obtener_facturas_de_hoy();
    for (auto i = 0U; i < fc.size(); i++)
    {
        ((factura&)fc[i]).mostrar();
    }

}






















// #include <iostream>
// #include <cstring>
// using namespace std;

// class String
// {
// private:
//     size_t len;
//     char* str;
// public:
//     String(const char* s) 
//     :len{strlen(s)}
//     { 
//         str = (char*)malloc(len+1);
//         memcpy(str, s, len+1);
//     }

//     String() : String{""}  //llama al primer constructor con una cadena vacia
//     {}

//     String(const String& s)   //copia
//     :len{s.len}, str{(char*) malloc(s.len+1)}
//     {
//         memcpy(str, s.str, len+1);
//     }

//     ~String() 
//     { 
//         free(str);
//     }

//     String& operator = (const String& s)
//     {
//         if(this == &s) return *this;
//         this->~String();
        
//         len = s.len;
//         str = (char*) malloc(len+1);
//         memcpy(str, s.str, len+1);
//         return *this;
//     }

//     const char* c_str() const  // no se escribe en la funcion y no modifica el estado del objeto y no se puede llmaar a metodos no constantes
//     {
//         return str;
//     }

//     String operator + (const String& s) const 
//     {
//         String aux;  
//         auto nlen = len + s.len;
//         aux.str = (char*)realloc(aux.str, nlen+1);
//         memcpy(aux.str, str, len);
//         memcpy(aux.str + len, s.str, s.len+1);
//         aux.len = nlen;
//         return aux;
//     }

//     String& operator += (const String& s)
//     {
//         auto nlen = len + s.len;
//         str = (char*) realloc(str, nlen+1);
//         memcpy(str+len, s.str, s.len+1);
//         len = nlen;
//         return *this;
//     }

//     bool operator == (const String& s) const
//     {
//         bool answer = true;
//         if(len == s.len)
//         {
//             for(size_t i = 0; i < len; i++)
//             {
//                 if(str[i] != s.str[i])
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

//     bool operator != (const String& s) const
//     {
//         bool answer = false;
//         if(len == s.len)
//         {
//             for(size_t i = 0; i < len; i++)
//             {
//                 if(str[i] != s.str[i])
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

// class object // class --------------------
// {
// private:
    
// public:
//     object() { }
//     ~object() { }
//     virtual void mostrar() const = 0; 
// };

// class array_list  // class --------------------
// {
// private:
//     object** list;
//     size_t count;
// public:
//     array_list() 
//     :list{(object**)malloc(0)}, count{0}
//     { }
    
//     ~array_list() { }

//     size_t size()
//     {
//         return count;
//     }

//     const object& operator[](size_t index) const
//     {
//         return *list[index];
//     }

//     object& operator[](size_t index)
//     {
//         return *list[index];
//     }

//     void add(object* new_object)
//     {
//         list = (object**)realloc(list, (count+1)*sizeof(object*));
//         list[count] = new_object;
//         count++;
//     }

//     void mostrar() const
//     {
//         for(size_t i = 0U; i < count; i++)
//         {
//             cout << i + 1 << ".- \t";
//             (*this)[i].mostrar();   // porque no funciona con (*list), es como si solo entrara una vez al siclo.
//         }
//         cout << "\n";
//     }
// };

// class producto : public object  // class --------------------
// {
// private:
//     String name;
//     String brand;
//     String id;
//     size_t stock;
//     double price;

// public:
//     producto(const String& name, const String& brand, const String& id, size_t stock, double price)
//     :name{name}, brand{brand}, id{id}, stock{stock}, price{price}
//     { }

//     ~producto() { }

//     void mostrar() const override
//     {
//         cout << "producto\n";
//     }
// };


// class item : public object  // class --------------------
// {
// private:
//     size_t quantity;
//     String id;
// public:
//     item(size_t quantity, String id)
//     :quantity{quantity}, id{id}
//     {
//         // cout << "item ";
//     }

//     ~item() { }

//     void mostrar() const override
//     {
//         cout << quantity << "\t" << id.c_str() << "\n";
//     }
// };

// class factura : public object  // class --------------------
// {
// private:
//     String name;
//     String nit;
//     array_list item_list;
//     double descuento;
// public:
//     factura(String name, String nit) 
//     :name{name}, nit{nit}
//     { }

//     ~factura() { }

//     void agregar_item(size_t quantity, String id)
//     {
//         item* new_item = new item{quantity, id};
//         item_list.add(new_item);
//     }

//     void agregar_descuento(double p_descuento)
//     {
//         descuento += p_descuento;
//     }

//     void mostrar() const override
//     {
        
//         // for(size_t i = 0; i < count; i++)
//         // {
//         // }
        
//         cout << "Nombre: " << name.c_str() << "\t\t" << "Nit: " << nit.c_str() << "\n";
//         cout << "Items: \n";
//         item_list.mostrar(); 
//     }
// };


// class sistema_facturacion  // class --------------------
// {
// private:
//     array_list product_list;
//     array_list factura_list;
// public:
//     sistema_facturacion() { }
    
//     ~sistema_facturacion() { }

//     void agregar_producto(const String& name, const String& brand, const String& id, size_t stock, double price)
//     {
//         producto* new_product = new producto{name, brand, id, stock, price};
//         product_list.add(new_product);
//         // return *new_product;
//     }

//     factura& crear_factura (String name, String nit)
//     {
//         factura* new_factura = new factura{name, nit};
//         factura_list.add(new_factura);
//         return *new_factura;
//     }

//     factura& crear_factura (String name)
//     {
//         factura* new_factura = new factura{name, "0"};
//         factura_list.add(new_factura);
//         return *new_factura;
//     }

//     array_list obtener_facturas_de_hoy()
//     {
//         array_list aux;
        
//         for(size_t i = 0; i < factura_list.size(); i++)
//         {
//             aux.add((object*)&(factura_list[i]));
//         }
//         return aux;
//     }
// };



// int main(){

//     sistema_facturacion sf;

//     sf.agregar_producto("Leche", "PIL", "1245235423451", 50, 5);
//     sf.agregar_producto("Yogurt", "PIL", "4245845254", 20, 15);
//     sf.agregar_producto("Paneton", "IC Norte", "2390482394283", 500, 22.50);

//     auto &f = sf.crear_factura("Omar Vera", "1029382015");
//     f.agregar_item(1, "1245235423451");
//     f.agregar_item(2, "2390482394283");

//     auto &g = sf.crear_factura("Juan Pedro");
//     g.agregar_item(2, "1245235423451");
//     g.agregar_item(1, "4245845254");
//     g.agregar_descuento(5);

//     auto fc = sf.obtener_facturas_de_hoy();
//     for (auto i = 0U; i < fc.size(); i++)
//     {
//         ((factura&)fc[i]).mostrar();
//     }
// }








// #include <iostream>
// #include <cstring>


// class String
// {
// private:
//     size_t len;
//     char* str;
// public:
//     String(const char* s) 
//     :len{strlen(s)}
//     { 
//         str = (char*)malloc(len+1);
//         memcpy(str, s, len+1);
//     }

//     String() : String{""}  //llama al primer constructor con una cadena vacia
//     {}

//     String(const String& s)   //copia
//     :len{s.len}, str{(char*) malloc(s.len+1)}
//     {
//         memcpy(str, s.str, len+1);
//     }

//     ~String() 
//     { 
//         free(str);
//     }

//     String& operator = (const String& s)
//     {
//         if(this == &s) return *this;
//         this->~String();
        
//         len = s.len;
//         str = (char*) malloc(len+1);
//         memcpy(str, s.str, len+1);
//         return *this;
//     }

//     const char* c_str() const  // no se escribe en la funcion y no modifica el estado del objeto y no se puede llmaar a metodos no constantes
//     {
//         return str;
//     }

//     String operator + (const String& s) const 
//     {
//         String aux;  
//         auto nlen = len + s.len;
//         aux.str = (char*)realloc(aux.str, nlen+1);
//         memcpy(aux.str, str, len);
//         memcpy(aux.str + len, s.str, s.len+1);
//         aux.len = nlen;
//         return aux;
//     }

//     String& operator += (const String& s)
//     {
//         auto nlen = len + s.len;
//         str = (char*) realloc(str, nlen+1);
//         memcpy(str+len, s.str, s.len+1);
//         len = nlen;
//         return *this;
//     }

//     bool operator == (const String& s) const
//     {
//         bool answer = true;
//         if(len == s.len)
//         {
//             for(size_t i = 0; i < len; i++)
//             {
//                 if(str[i] != s.str[i])
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

//     bool operator != (const String& s) const
//     {
//         bool answer = false;
//         if(len == s.len)
//         {
//             for(size_t i = 0; i < len; i++)
//             {
//                 if(str[i] != s.str[i])
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






// class object
// {
// private:
    
// public:
//     object() { }
//     ~object() { }
// };

// class producto : public object
// {
// private:
//     String name;
//     String brand;
//     String id;
//     size_t stock;
//     double price;

// public:
//     producto(const String& name, const String& brand, const String& id, size_t stock, double price)
//     :name{name}, brand{brand}, id{id}, stock{stock}, price{price}
//     { }

//     ~producto() { }
// };


// class factura : public object
// {
// private:
//     String name;
//     String nit;
// public:
//     factura(String name, String nit) 
//     :name{name}, nit{nit}
//     { }

//     ~factura() { }

//     void agregar_item(size_t quantity, String id)
//     {}

//     void agregar_descuento(size_t descuento)
//     {
        
//     }

//     void mostrar()
//     {

//     }
// };


// class array_list
// {
// private:
//     object** list;
//     size_t count;
// public:
//     array_list() 
//     :list{(object**)malloc(0)}, count{0}
//     { }
    
//     ~array_list() { }

//     size_t size()
//     {
//         return count;
//     }

//     const object& operator[](size_t index) const
//     {
//         return *list[index];
//     }

//     object& operator[](size_t index)
//     {
//         return *list[index];
//     }

//     void add(object* new_object)
//     {
//         list = (object**)realloc(list, (count+1)*sizeof(object*));
//         list[count] = new_object;
//         count++;
//     }

// };

// class sistema_facturacion
// {
// private:
//     array_list product_list;
//     public:
//     sistema_facturacion() { }
    
//     ~sistema_facturacion() { }

//     producto agregar_producto(const String& name, const String& brand, const String& id, size_t stock, double price)
//     {
//         producto* new_product = new producto{name, brand, id, stock, price};
//         product_list.add(new_product);
//     }

//     factura& crear_factura (String name, String nit)
//     {

//     }

//     factura& crear_factura (String name)
//     {

//     }

//     array_list obtener_facturas_de_hoy()
//     {

//     }

    
// };



// int main(){

//     sistema_facturacion sf;

//     sf.agregar_producto("Leche", "PIL", "1245235423451", 50, 5);
//     sf.agregar_producto("Yogurt", "PIL", "4245845254", 20, 15);
//     sf.agregar_producto("Paneton", "IC Norte", "2390482394283", 500, 22.50);

//     auto &f = sf.crear_factura("Omar Vera", "1029382015");
//     f.agregar_item(1, "1245235423451");
//     f.agregar_item(2, "2390482394283");

//     auto &g = sf.crear_factura("Juan Pedro");
//     g.agregar_item(2, "1245235423451");
//     g.agregar_item(1, "4245845254");
//     g.agregar_descuento(5);

//     auto fc = sf.obtener_facturas_de_hoy();
//     for (auto i = 0U; i < fc.size(); i++)
//         ((factura&)fc[i]).mostrar();
// }