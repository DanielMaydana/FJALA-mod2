// String Stream
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    stringstream ss;
    string hoy = "viernes";
    int dia = 25;
    const char *mes = "enero";
    size_t anio = 2019;

    ss << "hoy es " << hoy << " " << dia << " " << mes << " " << anio << "\n";
    // el stringsteam tiene sobrecargado el << para construir concat

    string r = ss.str();
    cout << r << "\n";
}