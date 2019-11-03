#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Test{

public:
    void work(void){
        cout << "WORK STARTED\t" << endl;

        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "Thread ID: "  << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "Thread ID: "  << this_thread::get_id() << endl;

        cout << "WORK STOPED\t" << endl;
    }

    void work_1(int a){
        cout << "WORK STARTED\t" << endl;

        cout << "Parameter: " << a << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "Thread ID: "  << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "Thread ID: "  << this_thread::get_id() << endl;

        cout << "WORK STOPED\t" << endl;
    }

    int summ(int a, int b){
        cout << "SUMM STARTED\t" << endl;

        cout << "Parameter 1 : " << a << endl;
        cout << "Parameter 2 : " << b << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "Thread ID: "  << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "Thread ID: "  << this_thread::get_id() << endl;

        cout << "SUMM STOPED\t" << endl;

        return a + b;

    }
};

//
int main()
{
    Test t1;

    thread th1(&Test::work_1, t1, 22);


    for(int i = 0; i < 10; i++){

        cout << "Thread ID: "  << this_thread::get_id() << "\tMain thread" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));

    }

    th1.join();

    return 0;
}
