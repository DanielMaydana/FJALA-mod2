// Guardar en un archivo como binario para ser mas rapidos, pero perdemos versatilidad
// Es escritura binaria
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct student
{
    int id;
    char name[124];

};

// ostream& operator<< (ostream& os, const student& p)
// {
//     os << p.id << ";" << p.name <<"\n";
//     return os;
// }

// istream& operator>> (istream& is, student& p)
// {
    // string line;
    // getline(is, line); // para sacar una linea de texto
    // if(is.fail()) return is;
    // auto pos = line.find(";");
    // if(pos == string::npos) throw 143;

    // auto sid = line.substr(0, pos);
    // auto name = line.substr(pos + 1);

    // p.id = stoi(sid); // stoi string a entero
    // p.name = name;

//     return is;
// }

int main()
{
    vector <student> sts;
    sts.push_back(student{1, "Avril Lavigne\n"});
    sts.push_back(student{2, "Chris Robinson\n"});
    sts.push_back(student{3, "Chavela Vargas\n"});

    ofstream j{"students.dat", ios::binary}; // dat es para archivo binario // ios::bin es para archivos binarios

    for(auto& s : sts)
    {
        j.write((char*)&s, sizeof(student)); // solo acepta 
    }
    j.close(); // siempre hacer close

    student arr[3]; // ese 3
    ifstream k{"students.dat", ios::binary}; // otra instancia puede abrir el miso archivo anterior
    k.read((char*)arr, 3 * sizeof(student)); // es este 3, se necesita saber cuantos elementos hay en el file
    k.close();

    for(auto& i : arr)
    {
        cout << i.name << "\n";
    }

    size_t size;
    ifstream m("students.dat", ios::binary);

    // ios::beg / ios::end / ios::cur
    m.seekg(0, ios::end); // sirve para saltar a cualquier parte del archivo, sirve mas en binarios
    size = m.tellg(); // con estos dos sabemos cual es el tamano del archivo
    // cout << (size/sizeof(student)) << endl; // cuantos elementos hay en el archivo

    student n;
    m.seekg(1 * sizeof(student), ios::beg );
    m.read((char*)&n, sizeof(student));

    cout << n.name << "\n";
}