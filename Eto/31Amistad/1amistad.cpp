// Amistad
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Point3DModify;

class Point3D{
    int x,y,z;

    public:
    Point3D(int x, int y, int z) : x{x}, y{y}, z{z}
    {}

    friend ostream& operator<<(ostream& os, const Point3D& p); // no es metodo es declaracion de amistad
    friend class Point3Dmodifier; // solo se puede especificar funciones sueltas o toda la clase
};

ostream& operator<< (ostream& os, const Point3D& p)
{
    os << p.x << "," << p.y << "," << p.z;
    return os;
}

class Point3Dmodifier
{
private:
    
public:
    Point3Dmodifier() { }
    ~Point3Dmodifier() { }

    void modify(Point3D& p, int x, int y, int z)
    {
        p.x = x;
        p.y = y;
        p.z = z;
    }
};

int main()
{
    Point3D p{6, 7, 8};
    cout << p << "\n";

    Point3Dmodifier m;
    m.modify(p, 10, 20, 30);
    cout << p << "\n";
}