#include <stdio.h>
#include <string.h>
#include <memory>
using namespace std;

constexpr size_t MAX = 16;

class Ztring
{
    char* h_char;
    char sso[MAX];
    size_t len;

    void set_string(const char* s)
    {
        if(len >= MAX)
        {
            h_char = (char*)malloc(len + 1);
            memcpy(h_char, s, len + 1);
            // puts("H_CHAR");
        }
        else
        {
            memcpy(sso, s, len + 1);
            // puts("SSO");
        }
    }

    public:

        Ztring(const char* s = "") : len{strlen(s)}
        {
            set_string(s);
        }

        Ztring(const Ztring &src) : len{src.len}
        {
            puts("copy constr");
            set_string(src.data());
        }
        
        Ztring& operator=(const Ztring &src)
        {
            puts("assign operator");
            if(this == &src)
            {
                return *this;
            }
            this->~Ztring();
            len = src.len;
            set_string(src.data());
            return(*this);
        }

        Ztring operator+(const Ztring &src) const
        {
            auto n_len = len + src.len;
            Ztring new_ztr;
            new_ztr.len = n_len;

            if(n_len >= MAX)
            {
                new_ztr.h_char = (char*)malloc(n_len + 1);
            }

            char* str = n_len < MAX ? new_ztr.sso : 

            return new_ztr;
        }

        const char* data() const
        {
            return len < MAX ? sso : h_char;
        }

        ~Ztring()
        {
            if(len >= MAX) free(h_char);
        }
};

int main()
{
    Ztring s = "hallo";
    puts(s.data());

    Ztring r = "Whatever happened to my rock n roll";
    puts(r.data());

    Ztring h0;
    Ztring h1 = r;

    h0 = h1;
    puts(h0.data());
}