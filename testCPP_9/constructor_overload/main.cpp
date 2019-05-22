#include <iostream>
#include <ctime>

using namespace std;

class Timer{
    int seconds;
public:
    Timer(char *t) { seconds = atoi(t); }
    Timer(int t) { seconds = t; }
    Timer(int min, int sec) { seconds = min * 60 + sec; }
    void run();
};

void Timer::run(){
    clock_t time;
    time = clock();
    while( (clock() / CLOCKS_PER_SEC - time / CLOCKS_PER_SEC) < seconds);
    cout << "\a";
}

int main()
{
    Timer a(10), b("20"), c(1, 10);
    a.run();
    b.run();
    c.run();
    return 0;
}
