#include <iostream>

using namespace std;

void fun(int &);

int main()
{
    int a = 10;

    cout << a << endl;
    fun(a);
    cout << a;

    return 0;
}

void fun(int &r){
    r++;
}
