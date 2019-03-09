#include <iostream>
using namespace std;
void do_something(int n)
{
    cout << "hello\n";
    cout << "one\n";
    cout << "two\n";
    if(n == 3)
        goto SAY_BYE;
    cout << "four\n";
    cout << "five\n";
    SAY_BYE:
    cout << "bye\n";
}

int main()
{
    do_something(5);
    do_something(3);

}