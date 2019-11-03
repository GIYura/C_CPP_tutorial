#include <iostream>
#include <thread>
#include <chrono>

#include <mutex>

using namespace std;

class Timer{
  chrono::high_resolution_clock::time_point start, end;
  chrono::duration<float> m_duration;
public:
  Timer(){
    this->start = chrono::high_resolution_clock::now();
  }

  ~Timer(){
    this->end = chrono::high_resolution_clock::now();
    this->m_duration = this->end - this->start;
    float res = this->m_duration.count();
    cout << "Time spend: " << res << " s"<< endl;
  }
};

int summ(int a, int b);

void foo(void);

int main()
{
    foo();
//    Timer tmr;
/*
    int res;

    thread th1([&res](){
        res = summ(22, 23);
    });

    for(int i = 0; i < 10; i++){
        cout << "Thread ID: " << this_thread::get_id() << "\t main" << "\titearation\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    th1.join();

    cout << "Res: " << res << endl;
*/
    return 0;
}


//
int summ(int a, int b){
    cout << "Thread ID: " << this_thread::get_id() << "\t work started" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "Thread ID: " << this_thread::get_id() << "\t work stoped" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));

    return a + b;
}

void foo(void){
  Timer tmr;

  for(int i = 0; i < 50; i++){
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Iteration: " << i << endl;
  }
}
