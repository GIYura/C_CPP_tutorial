#include <iostream>

using namespace std;

typedef enum{
    MON = 0,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
}Tday;

void fun(int &);
inline Tday &operator++(Tday &d){
   return d = Tday(d + 1);
}

int main()
{
    int a = 10;

    cout << a << endl;
    fun(a);
    cout << a;

    for(Tday d = 0; d < 7; ++d){

    }

    return 0;
}

void fun(int &r){
    r++;
}
