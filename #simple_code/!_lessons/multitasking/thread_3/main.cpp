#include <iostream>

#include <thread>

#include <chrono>

using namespace std;

void work(int& a);

int main()
{
    int x = 2;
//    work(x);

    thread t(work, std::ref(x));

    for(int i = 0; i < 10; i++){
        cout << "Tread ID: " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    //t.join();

    cout << "X: " << x << endl;

    return 0;
}

//
void work(int& a){
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "Summ started...Thread ID: " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));

    a = a * 2;

    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "Summ stoped." << endl;
}
