#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<chrono>
using namespace std;

void find_elem(bool& flag, vector<int>& z, const size_t& lim_start, const size_t& lim_finish, int& to_find, int& position, mutex& mx)
{
    if(flag == false)
    {
        for(size_t i = lim_start; i <= lim_finish; i++)
        {
            if(z.at(i) == to_find)
            {
                lock_guard<mutex> lg(mx);
                position = i;
                flag = true;
            }
        }
    }
}

int main()
{
    vector<int> z;
    int cant = 1'000'000;
    bool flag = false;
    int to_find = 1;
    int position = -1;
    pair<int, int> lim1(0, 250'000);
    pair<int, int> lim2(250'001, 500'000);
    pair<int, int> lim3(500'001, 750'000);
    pair<int, int> lim4(750'001, 999'999);
    mutex mx;

    for(size_t i = cant; i > 0; i--) z.push_back(i);

	auto t_start = chrono::steady_clock::now();

    thread t1{find_elem, ref(flag), ref(z), ref(lim1.first), ref(lim1.second), ref(to_find), ref(position), ref(mx)};
    thread t2{find_elem, ref(flag), ref(z), ref(lim2.first), ref(lim2.second), ref(to_find), ref(position), ref(mx)};
    thread t3{find_elem, ref(flag), ref(z), ref(lim3.first), ref(lim3.second), ref(to_find), ref(position), ref(mx)};
    thread t4{find_elem, ref(flag), ref(z), ref(lim4.first), ref(lim4.second), ref(to_find), ref(position), ref(mx)};

    // thread t1{find_elem, ref(flag), ref(z), ref(lim1.first), ref(lim4.second), ref(to_find), ref(position), ref(mx)};
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();

	auto t_finish = chrono::steady_clock::now();

    cout << chrono::duration_cast<chrono::milliseconds>(t_finish - t_start).count() << " ms\n";
    cout << position << "\n";
}