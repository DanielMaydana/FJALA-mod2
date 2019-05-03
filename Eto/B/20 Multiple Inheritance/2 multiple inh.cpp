#include <string>

struct Int
{
    int n;
    std::string to_string()const{
        return std::to_string(n);
    }
};


struct Char
{
    char c;
    std::string to_string()const{
        char aux[2];
        aux[0]=c;
        aux[1]='\0';
        return aux;
    }
};

struct IntChar: Int, Char
{
    IntChar (int n, char c):Int{n}, Char{c}{ }

    std::string to_string()const{
        auto s=Int::to_string();
        s +=", ";
        s +=Char::to_string();
        return s;
    }
};




int main()
{
    IntChar p{15,'G'};
    auto s=p.to_string();
    puts(s.data());
    return 0;
}