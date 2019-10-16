// dynamic_cast.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>

using namespace std;

class Parent {
public:
	virtual void speak(void) {
		cout << "I'm parent" << endl;
	}
};

class Son : public Parent {
public:
	void speak(void) override {
		cout << "I'm son" << endl;
	}
};

class Daughter : public Parent {
public:
	void speak(void) override {
		cout << "I'm daughter" << endl;
	}
};

class Base {
protected:
	int b;
public:
	Base() : b(0) {}
	Base(int b) : b(b) {}
	virtual void f(void) {};
	void show(void) {
		cout << "B value: " << this->b << endl;
	}
};

class Derived_0 : public Base {
	int d;
public:
	Derived_0(int x, int y) : d(y) {
		b = x;
	}
	void show(void) {
		cout << "B value: " << b << "\t" << "D value: " << this->d << endl;
	}
};

class Derived_1 : public Base {

};

class Derived_2 : public Base {

};

class Derived_3 : public Base {

};

bool is_der_1(Base* unknown) {
	Derived_1* pDer = nullptr;
	if (pDer = dynamic_cast<Derived_1*>(unknown)) {
		return true;
	}
	return false;
	
}

int main()
{
//	Parent parent;
	Son son;

	Parent* p =	&son;
	
	Son* s = dynamic_cast<Son*>(p);

	if (s == nullptr) {
		cout << "Invalid cast" << endl;
	}
	else {
		cout << "Valid cast" << endl;
	}
	cout << endl << endl;

	Derived_1* d1 = new Derived_1;
	Derived_2* d2 = new Derived_2;
	Derived_3* d3 = new Derived_3;

	if (is_der_1(d1)) {
		cout << "Instance: " << typeid(d1).name() << " belongs to Derived 1 class" << endl;
	}
	else {
		cout << "Instance: " << typeid(d1).name() << " NOT belongs to Derived 1 class" << endl;
	}

	if (is_der_1(d2)) {
		cout << "Instance: " << typeid(d2).name() << " belongs to Derived 2 class" << endl;
	}
	else {
		cout << "Instance: " << typeid(d2).name() << " NOT belongs to Derived 2 class" << endl;
	}

	if (is_der_1(d3)) {
		cout << "Instance: " << typeid(d3).name() << " belongs to Derived 3 class" << endl;
	}
	else {
		cout << "Instance: " << typeid(d3).name() << " NOT belongs to Derived 3 class" << endl;
	}

	Base* pBase = new Base(1);
	Derived_0* pDerived_0 = new Derived_0(10, 20);

	pBase = pDerived_0;// dynamic_cast<Base*>(pDerived_0);
	pBase->show();

	pDerived_0 = dynamic_cast<Derived_0*>(pBase);
	pDerived_0->show();

	return 0;
}