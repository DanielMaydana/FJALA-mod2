#include <cstring>
#include <cstdio>
#include <cstdlib>

constexpr size_t MAX = 16; // es un valor que el compliador reemplaza por algo
class Ztring
{
    char* chars;
    char szo[MAX]; //sso -> small string optimization conciste en que si las cadenas son menor al tamanio max se almacena en sso en lugar de almacenar en el char*
    size_t len;

    public:
        Ztring(const char* str = ""):len{strlen(str)}
        {
            set_string(str);
        }

    private:
        void set_string(const char* str)
        {
            if(len>=MAX)
            {
                chars = (char*)malloc(len+1);
                memcpy(chars,str,len+1);
            }
            else
            {
                memcpy(szo,str,len+1);
            }
        }
    public:
        const char* data() const
        {
            return len<MAX?szo:chars;
        }

        ~Ztring()
        {
            if(len>=MAX) free(chars);
        }

        Ztring(const Ztring& s)
        :len{s.len}
        {
            set_string(s.data());
        }
        
        //sobrecarga de operador

        Ztring& operator = (const Ztring& src)
        {
            if(this == &src) return *this;
            
            this->~Ztring();
            len = src.len;
            set_string(src.data());
            return *this;
        }

        Ztring operator +(const Ztring& s) const
        {
            auto nlen = len + s.len;

            Ztring ns;
            ns.len = nlen;

            if(nlen >= MAX)
            {
                ns.chars = (char*)malloc(nlen+1);
            }
               
                char* str = nlen<MAX?ns.szo:ns.chars;
                memcpy(str,data(),len);
                memcpy(str+len,s.data(),s.len+1);
           

            return ns;
        }

        //Sobrecarga operador +=

        Ztring& operator +=(const Ztring& p)
        {
            auto nlen = len + p.len;
            if(len >= MAX)
            {
                chars = (char*)realloc(chars, nlen+1);
                memcpy(chars + len, p.data(), p.len+1);
                len = nlen;
                return *this;
            }

            if(nlen >= MAX)
            {
                chars = (char*)malloc(nlen+1);
                memcpy(chars,data(),len);
                memcpy(chars+len, p.data(), p.len+1);
                len = nlen;
                return *this;
            }

            memcpy(szo+len, p.data(),p.len+1);
            len = nlen;
            return *this;
        }

};

int main()
{
    /*Ztring s = "Hola";
    puts(s.data());

    Ztring r = "Antonio Jose de Sucre";
    puts(r.data());

    auto p = r;
    puts(p.data());

    //constructor copia
    auto x = s;
    puts(x.data());

    //sobrecarga de operadores
    p = "Segmentation";// es igual a decir p = Ztring{"Segmentation"};
    puts(p.data()); //genera error si no se tiene una sobrecarga de operador

    */

   
   //sobrecarga de operador +
   Ztring h = "Hello";
   Ztring w = "World";
   auto hw = h + " " + w;
   puts(hw.data());


    auto hw2 = hw + "of c++ Segmentation Default";
    puts(hw.data());


    Ztring b = "Today";
    b+= "is";
    b+="Tuesday, April 24,";
    puts((b+= "2019").data());

}

