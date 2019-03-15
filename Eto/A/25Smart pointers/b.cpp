#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Animal
{
    virtual ~Animal()
    {
        cout << "struct animal deleted\n";
    }
};

struct Vaca : Animal
{ };

struct Oveja : Animal
{ };

struct Zoo
{
//     Animal* a1;
//     Animal* a2;
//     Animal* a3;
    unique_ptr<Animal> a1;
    unique_ptr<Animal> a2;
    unique_ptr<Animal> a3;

    Zoo(Animal* a1, Animal* a2, Animal* a3) : a1{a1}, a2{a2}, a3{a3}
    {
        throw 4;
    }

    ~Zoo()
    {
        // delete a1;
        // delete a2;
        // delete a3;
    }
};


int main()
{
    try
    {
        Zoo z{new Vaca(), new Oveja(), new Oveja()};
    }

    catch(...)
    {
        cout << "Error\n";
    }

    vector<unique_ptr<Animal>> animals;   // si utilizamos polimorfismo es mejor utilizar smart pointers
    animals.emplace_back(new Oveja());
    animals.emplace_back(make_unique<Vaca>());
    for(auto& a : animals) // a es unique pointer y sin & quiere hacer una copia que no es posible
        cout << typeid(*a).name() << "\n";

    // for (auto a : animals)
    //     delete a;

}