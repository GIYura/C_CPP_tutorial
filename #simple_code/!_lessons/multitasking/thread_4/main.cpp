#include <iostream>

#include <thread>

#include <chrono>

using namespace std;

void work(int& a);

int summ(int a, int b);

int main()
{
    int result;

    thread t([&result]() {
        result = summ(3, 7);
    });

    for(int i = 0; i < 10; i++){
        cout << "Tread ID: " << this_thread::get_id() << "\t main\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    t.join();

    cout << "Result: " << result << endl;

    return 0;
}

//
/*
void work(int& a){
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "Work started...Thread ID: " << this_thread::get_id() << "\t work" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    a = a * 2;

    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "Work stoped." << endl;
}*/

//
int summ(int a, int b){
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "Summ started...Thread ID: " << this_thread::get_id() << "\t summ" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "Summ stoped...Thread ID: " << this_thread::get_id() << "\t summ" << endl;
    return a + b;
}
