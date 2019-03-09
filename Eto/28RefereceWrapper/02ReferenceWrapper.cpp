#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<functional>
#include<optional>

using namespace std;


template<typename C, typename T>
// auto my_find(const C& c, const T& val){
optional<typename C::mapped_type> my_find(const C& c, const T& val){ // Para que ya no sea un chorizo

    if(val == c.end()){
        return {}; // es como poner el constructor: optional<typename C::mapped_type>
    }
    else{
        return val -> second; // optional<typename C::mapped_type>{it->second}
    }
}

int main(){

    map<int, string> m;
    m[10] = "diez";
    m[20] = "veinte";
    m[30] = "treinta";

    auto r = my_find(m, 20); // r es de tipo string canalizado por optional
    if(r)
        cout << r.value() << "\n";
    else
        cerr << "NOT FOUND\n";
}

// template <typename C, typename T>
// optional<typename C::mapped_type> my_find(const C& c, const T& val)
// {
//     auto it = c.find(val);
//     if(it==c.end())
//     {
//         return {};// optional<typename C::mapped_type>{}// eso para entender
//     }
//     else
//     {
//         return it->second;// optional<typename C::mapped_type>{it->second}
//     }
// }

// int main()
// {
//     map<int, string> m;
//     m[10]= "diez";
//     m[20]= "veinte";
//     m[30]= "treinta";
//     auto r= my_find(m, 30);
//     if(r)
//         cout << r.value() << '\n';
//     else
//         cout << "not found\n";   
//     //compilar con: g++ 2reference_optional.cpp -o compile -std=c++17
// }
