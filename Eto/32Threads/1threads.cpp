/*
    Trheads
    Son unidades de ejecucion independiente y "concurrente" dentro un proceso
    Comparten address space
        - pueden acceder a variables de otros procesos
        - dedlocks / condiciones de carrera
    Context-switch ligero

    Proceso
    Un proceso es una unidad de ejecucion independiente dentro un sis op
    No comparten address space
        - no pueden acceder a variables de otros procesos (IPC comunicacion entre procesos)
        - no hay deadlocks ni condiciones de carrera
    Context-switch pesado
*/ 
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

void function(const string& name)
{
    for(int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(10ms);
        this_thread::yield(); // si quieres procesador, salta al otro hilo
        cout << this_thread::get_id() << " :" << name << " :" << i << " *\n";
    }
    cout << "*end*\n";

}

int main()
{
    thread p{function, "p"};
    thread q{function, "q"};

    p.join();
    q.join();
    return 0;

    
}
// compilar con -lpthread