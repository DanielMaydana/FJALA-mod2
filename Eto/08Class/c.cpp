// Clase string

#include <iostream>
#include <cstring>
using namespace std;


class String
{
private:
    size_t len;
    char* str;
public:
    String(const char* s) 
    :len{strlen(s)}   //Initialization list
    { 
        // str = new char[len+1];
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
        if(this == &s) return *this; //si esto compara direcciones de memoria?????????
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

    String operator + (const String& s) const // normalmente es const porque no modifica las cadenas
    {
        String aux;  // aca ya llama al constructor y el constructor hace el malloc
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

    void trim()
    {
        size_t finder_ini = 0;
        size_t finder_fin = len;
        size_t new_size;
        size_t cursor = 0;
        
        while(str[finder_ini] == ' ')
        {
            finder_ini++;
        }

        while(str[finder_fin] == ' ')
        {
            finder_fin--;
        }

        new_size = (finder_fin - finder_ini) + 1;

        char* aux = (char*) malloc(new_size+1);
        
        for(size_t i = finder_ini; i <= finder_fin; i++)
        {
            aux[cursor] = str[i];
            cursor++;
        }
        aux[cursor] = 0;
        free(str);  
        str = aux;
    }

    int index_of(const String& s) const
    {
        size_t len_new = 0;
        size_t cont_first = 0;
        size_t len_finded = s.len;
        for(size_t i = 0; i < len; i++)
        {
            if(str[i] == s.str[len_new])
            {
                len_new++;
            }
            else 
            {
                len_new = 0;
                cont_first++;
            }

            if(len_new == len_finded)
            {
                return cont_first;
            }
        }   
        return -1;
    }

    String substring(size_t init, size_t len) const
    {
        size_t new_len = len - init;
        size_t init_new = 0;
        String new_string;    
        new_string.str = (char*) realloc(new_string.str, new_len+1);
        for(size_t i = init; i < len; i++)
        {
            new_string.str[init_new] = str[i];  
            init_new++;
        } 
        
        return new_string;
    }

    // String substring(size_t init) const
    // {}
};


class persona
{
private:
    String first_name;
    String last_name;
    int id;
public:
    persona(const String fn, const String ln, int i) 
    :first_name{fn}, last_name{ln}, id{i}
    { }
    
    ~persona() { }
    
    void print()const
    {
        cout << first_name.c_str() << " " << last_name.c_str() << " " << id << "\n";
    }
};

int main()
{
    String s;
    String s2{"     ab    cd      "};
    String s3 = "abcdefghijk";  //llama al constructor que reciba un const char*
    cout << s2.c_str() << "\n";
    s2.trim();
    cout << s2.c_str() << "\n";
    String s4 = "hijk";
    int indx = s3.index_of(s4);
    cout << indx << "  index\n";

    cout << String("zanahoria").substring(1, 3).c_str() << "\n";

    // bool a = s2 != s3;
    // cout << a << "\n";
    // String s4 = s2;
    // s = s3;
    // cout << s4.c_str() << "\n";
    // auto hm = s4 + " " + s; // el  " " llama al constructor que recibe un const char* y manda un objeto String
    // cout << hm.c_str() << "\n";
    // hm += "nativo";
    // cout << hm.c_str() << "\n";

    // persona p1 {"Elon", "Musk", 123345};
    // persona p2 {"Ma", "Luma", 8678566};
    // persona p3 = p1;
    // p1 = persona {"Rick", "Grime", 657856};
    // p1.print();
    // p2.print();
    // p3.print();

}