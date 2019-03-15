#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
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

void function2(const int& id, mutex& m)
{
    // m.lock(); // bloquea el hilo para dejar que termine
    for(int i = 0; i < 1000; i++)
    {
        lock_guard<mutex> gr{m}; // no sirve para llamadas recursivas
        cout << id << " : " << i << "\n";
        this_thread::yield();
        // if(i == 8) return; // produce un deadlock() por que no hace unlock()
    }
    // m.unlock();
}

int main()
{
    mutex m;
    vector<thread> r;
    for(int i = 0; i < 1000; i++)
    {
        r.emplace_back(function2, i, ref(m)); 
        // el bind hace copias de sus parametros
        // por eso hay que forzarlo para pasarlo por referencia
    }

    for(auto& x : r)
    {
        x.join();
    }
}
// compilar con -lpthread