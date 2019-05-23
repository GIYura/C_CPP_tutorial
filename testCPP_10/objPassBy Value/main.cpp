#include <iostream>

using namespace std;

class MyClass{
    int val;
public:
    MyClass(int i) { val = i; cout << "Creating" << endl; }
    ~MyClass() { cout << "Destroying" << endl; }
    int getVal() { return val; }


};

class MyClass1{
    int *p;
public:
    MyClass1(int i);
    ~MyClass1();
    int getValue() { return *p; }
};

MyClass1::MyClass1(int i){
    cout << "Memory allocation" << endl;
    p = new int;
    *p = i;
}

MyClass1::~MyClass1(){
    cout << "Memory freeing" << endl;
    delete p;
}

void display1(MyClass1 obj){
    cout << obj.getValue() << endl;
}

void display(MyClass obj){
    cout << obj.getVal() << endl;
}

int main()
{
    MyClass a(10);

    display(a);

    MyClass1 b(20);

    display1(b);

    return 0;
}
