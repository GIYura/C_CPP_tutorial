// destructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Base {
public:
	Base() {
		cout << "Base constructor" << endl;
	}

	virtual ~Base() {
		cout << "Base destructor" << endl;
	}

	virtual void show(void) {
		cout << "Base class working..." << endl;
	}
};

class Derived : public Base{
public:
	Derived() {
		cout << "Derived constructor" << endl;
	}

	~Derived() {
		cout << "Derived destructor" << endl;
	}

	void show(void) override {
		cout << "Derived class working..." << endl;
	}
};

//
int main()
{
	Base* b = new Derived;

	b->show();

	delete b;

	return 0;
}