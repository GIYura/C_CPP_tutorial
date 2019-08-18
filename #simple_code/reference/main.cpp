#include <iostream>

using namespace std;

void swap_pointer(int*, int*);
void swap_reference(int&, int&);

void foo_1(int*);
void foo_2(int&);
void foo_3(int);

int main()
{
    int a = 5;
    int *pa = &a;

    int &aRef = a;

    cout << "pa = " << *pa << endl;
    cout << "aref = " << aRef << endl;

    ++*pa;
    cout << "pa = " << *pa << endl;

    aRef++;
    cout << "aref = " << aRef << endl;

    int arr[] = {5,4,3,2,1};
    int &ref_arr = *arr;
    cout << ref_arr++ << endl;
    cout << ref_arr++ << endl;
    cout << ref_arr++ << endl;
    cout << ref_arr << endl;

    int arra[] = {1,2,3,4,5,6,7};
    int *parra = arra;
    cout << *parra++ << endl;
    cout << *parra++ << endl;
    cout << *parra++ << endl;
    cout << *parra++ << endl;
    cout << *parra++ << endl;
    cout << *parra++ << endl << endl;


    int x = 10, y = 20;
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    swap_pointer(&x, &y);
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    swap_reference(x, y);
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl << endl << endl;

    int val = 33;
    cout << "Val = " << val << endl;
    foo_1(&val);
    cout << "Val = " << val << endl;

    val = 55;
    cout << "Val = " << val << endl;
    foo_2(val);
    cout << "Val = " << val << endl;

    val = 100;
    cout << "Val = " << val << endl;
    foo_3(val);
    cout << "Val = " << val << endl;

    return 0;
}


void swap_pointer(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void swap_reference(int& a, int& b){
    int c = a;
    a = b;
    b = c;
}

void foo_1(int* x){
    (*x)++;
}

void foo_2(int& x){
    x = 0;
}

void foo_3(int x){
    x = 0;
}
