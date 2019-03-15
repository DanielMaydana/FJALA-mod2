#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<functional>
#include<optional>
#include<any>

using namespace std;




int main(){

    vector <any> x;
    x.push_back(8);
    x.push_back("hola"s);
    x.push_back(true);

    for(auto e : x){

        if(e.type() == typeid(int)){
            
            cout << any_cast<int>(e) << "\n";
        }
    }

    any p = 1;
    cout << any_cast<int>(p) << "\n";

    p = "hola"s;
    cout << any_cast<string>(p) << "\n";
}