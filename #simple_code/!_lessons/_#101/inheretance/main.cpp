#include <iostream>

using namespace std;

class A{

public:

    A(){
        cout << "CONSTR A :" << endl;
    }

    ~A(){
        cout << "~DESTR A :" << endl;
    }
};

class B : public A{
public:
    B(){
        cout << "CONSTR B :" << endl;
    }

    ~B(){
        cout << "~DESTR B :" << endl;
    }
};

class C : public B{
public:
    C(){
        cout << "CONSTR C :" << endl;
    }

    ~C(){
        cout << "~DESTR C :" << endl;
    }
};

int main()
{
    C c;
    cout << endl << endl;

    return 0;
}
