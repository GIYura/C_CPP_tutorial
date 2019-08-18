#include <iostream>

using namespace std;

template <typename T1, typename T2>
T1 sum(T1 a, T2 b){
    return a + b;
}

int main()
{
    cout << sum(4.7, 8.88) << endl;
    cout << sum(5, 8) << endl;
    cout  << sum(6, 9.88) << endl;
    return 0;
}
