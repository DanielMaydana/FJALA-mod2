#include <iostream>
using namespace std;

int suma(int& number1, int& number2){
    return ++number1 + ++number2;
}
int suma(int& number1, int& number2, int num){
    return ++number1 + ++number2 + num; 
}
int main()
{
    int number1 = 6;
    int number2 = 4;
    cout << number1 << "  " << number2 << "\n";
    int result = suma(number1, number2); 
    cout << result << "\n";
    cout << number1 << "  " << number2 << "\n";
    result = suma(number1, number2); 
    cout << result << "\n";
    cout << number1 << "  " << number2 << "\n";
    result = suma(number1, number2, 8); 
    cout << result << "\n";
    cout << number1 << "  " << number2 << "\n";
}