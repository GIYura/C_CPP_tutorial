#include <iostream>

#include <thread>

#include <chrono>

using namespace std;

class A{

public:
    A(){}
    virtual ~A(){}
};

void work(int a, int b);

int main()
{
    thread t1(work, 11, 12);

    for(int i = 0; true; i++){
        cout << "Thread ID: " << this_thread::get_id() << "\t main works: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    t1.join();

    return 0;
}

void work(int a, int b){
    cout << "Thread ID: " << this_thread::get_id() << "\t work works" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "Work started..." << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "a + b = " << a + b << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "Work stoped" << endl;
}
