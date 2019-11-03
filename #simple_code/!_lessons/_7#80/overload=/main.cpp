//overload=

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

        cout << "Constructor: " << this << endl;
    };
    ~MyClass(){
        cout << "Destructor: " << this << endl;
        delete[] data;
    };

    void operator = (const MyClass& other){
        cout << "Operator = " << endl;

        this->sz = other.sz;

        delete[] this->data;

        this->data = new int [other.sz];
        for(int i = 0 ; i < other.sz; i++){
            this->data[i] = other.data[i];
        }
    }
};

int main()
{
    MyClass a(3);
    MyClass b(5);

    a = b;

    return 0;
}
