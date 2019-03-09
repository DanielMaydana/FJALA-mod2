// Manipuladores
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool x = true;
    cout << boolalpha << x << "\n"; // cambia el valor de entero a un texto
    // endl es otro manipulador (muy lento)

    // for(int i = 1; i < 10000000; i *= 100) cout << setw(10) << i << "\n";

    // double p = 3'141'592'321'333.34;
    // cout << fixed << p << "\n";
    // cout << scientific << p << "\n";
    // cout << defaultfloat << p << "\n";
    // cout << setprecision(3) << p << "\n";

    // cout << hex << uppercase << 0xCAFEBABE << "\n";
    cout << oct << 12312413413 << dec << "\n";
    cout << false << "\n"; // los modificadores se quedan por eso hay que usarlos y setearlos al estado original
}