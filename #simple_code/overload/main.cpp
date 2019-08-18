#include <iostream>

using namespace std;

int sum(int, int);
double sum(double, double);
int sum(int, int, int);

int main()
{
    cout << "Hello world!" << endl;

    cout << sum(2.5, 5.7) << endl;
    cout << sum(4, 5) << endl;
    cout << sum(3,5,7) << endl;

    return 0;
}

int sum(int a, int b){
    return a + b;
}

double sum(double a, double b){
    return a + b;
}

int sum(int a, int b, int c){
    return a + b + c;
}
