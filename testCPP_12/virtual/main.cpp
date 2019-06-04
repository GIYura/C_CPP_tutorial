#include <iostream>

using namespace std;

class Base{
public:

    virtual void showInfo() { cout << "This is Base class" << endl; };
};

class First : public Base{
public:

    void showInfo() { cout << "This is First class" << endl; };
};

class Second : public Base{
public:

    void showInfo() { cout << "This is Second class" << endl; };
};

int main()
{
    Base *b = new Base();
    b->showInfo();

    First first;
    b = &first;
    b->showInfo();

    Second second;
    b = &second;
    b->showInfo();

    return 0;
}
