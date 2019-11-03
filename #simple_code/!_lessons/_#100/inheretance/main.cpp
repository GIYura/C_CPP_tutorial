//INHERETANCE

#include <iostream>

using namespace std;

class A{
private:

protected:

public:
    A(){
        cout << "Class A CONSTRUCTOR" << endl;
    }
};

class B : public A{
public:
    B(){
        cout << "Class B CONSTRUCTOR" << endl;
    }
};

class C : public B{
public:
    C(){
        cout << "Class C CONSTRUCTOR" << endl;
    }
};

int main()
{
//    B b1;

    C c1;
    return 0;
}
