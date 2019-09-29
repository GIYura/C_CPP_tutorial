// rtti_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Test {
public:
	Test() {};
};

class Base {
public:
	Base() {};
	virtual void f(void) {};
};

class Derived1 : public Base {
public:
	Derived1() {}
};

class Derived2 : public Base {
public:
	Derived2() {}
};

int main()
{
	int i;
	char j;
	float f;
	Test test;

	cout << "i type of: " << typeid(i).name() << endl;
	cout << "f type of: " << typeid(f).name() << endl;
	cout << "test type of: " << typeid(test).name() << endl;

	if (typeid(i) == typeid(j)) {
		cout << "types of i and j are the same" << endl;
	}
	else {
		cout << "types of i and j are NOT the same" << endl;
	}
	Base b;
	Derived1 d1;
	Derived2 d2;

	Base* ptr = &b;
	cout << typeid(*ptr).name() << endl;

	ptr = &d1;
	cout << typeid(*ptr).name() << endl;

	ptr = &d2;
	cout << typeid(*ptr).name() << endl;

	return 0;
}

