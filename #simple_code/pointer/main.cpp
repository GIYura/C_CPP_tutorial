#include <iostream>

using namespace std;

void foo(int*, int*, int*);

int main()
{
    int A = 5, B = 1, C = 4;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;

    foo(&A, &B, &C);

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;

    return 0;
}

void foo(int* pa, int* pb, int* pc){
    (*pa) = 555;
    (*pb)++;
    (*pc) -= 20;
}
