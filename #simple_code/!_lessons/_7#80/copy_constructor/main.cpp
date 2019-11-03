#include <iostream>

using namespace std;

class MyClass{
    int sz;
public:
    int* data;

    MyClass(int sz){
        this->sz = sz;
        this->data = new int[sz];

        for(int i = 0; i < sz; i++){
            data[i] = i;
        }

        cout << "Constructor started: " << this << endl;
    };

    MyClass(const MyClass &other){
        cout << "COPY Constructor started: " << this << endl;
        this->sz = other.sz;
        this->data = new int[other.sz];
        for(int i = 0; i < other.sz; i++){
            this->data[i] = other.data[i];
        }
    }

    ~MyClass(){
        cout << "Destructor started: " << this << endl;
        delete[] data;
    }
};

void foo(MyClass value){
    cout << "Foo started" << endl;
}

MyClass foo2(void){
    cout << "Foo 2 started" << endl;
    MyClass temp(2);
    return temp;
};

int main()
{
//    MyClass m1(1);
//    foo(m1);
//    foo2();
    MyClass a(5);
    MyClass b(a);

    return 0;
}
