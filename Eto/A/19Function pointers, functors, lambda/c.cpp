#include <iostream>
using namespace std;

void print_progress(const int p, const int c){

    cout << p << " de " << c << " elementos\n";
}

void my_f(void(*incoming_f)(const int p, const int c))
{
    int work = 2'000'000'000;
    for(int i = 0; i < work; i++){

        if(i % 20'000'000 == 0) incoming_f(i, work);
    }
}

int main()
{
    my_f(print_progress);
}