#include <iostream>

#include <thread>

#include <chrono>

using namespace std;

void work(void);

int main()
{
  cout << "Appl started..." << endl;

  thread t(work);
  thread t1(work);

  for(int i = 0; i < 10; i++){
      cout << "Thread ID: " << this_thread::get_id() << "\t main\t" << i << endl;
      this_thread::sleep_for(chrono::milliseconds(500));
  }

  t.join();
  t1.join();

  cout << "Appl stoped" << endl;
  return 0;
}

void work(void){
    for(int i = 0; i < 10; i++){
        cout << "Thread ID: " << this_thread::get_id() << "\t work\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}
