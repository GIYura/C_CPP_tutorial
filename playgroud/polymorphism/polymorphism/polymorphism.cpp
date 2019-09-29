// polymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
There are 2 kind of function binding: early and later (dynamic).
Binding is connection function call to its body.
Early binding is made before the program is run (C compiler support only EARLY bindnig).
Dynamic binding is performed at runtime, BASED ON THE TYPE OF THE OBJECT. Late binding occurs only with virtual
functions, and only when you’re using an address of the base class.
*/

#include <iostream>
using namespace std;
enum MyEnum
{
	cA = 0,
	cB = 1,
	cC = 2,
	CLASS_NUMBER
};
class A {
public:
	virtual void process(void) {
		cout << "Process from class A" << endl;
	};
};

class B : public A{
public:
	void process(void) override {
		cout << "Process from class B" << endl;
	};
};

class C : public A{
public:
	void process(void) override {
		cout << "Process from class C" << endl;
	};
};

class Vehicle {
public:
	virtual void drive(void) {
		cout << "Vehicle is moving..." << endl;
	}
};

class Car : public Vehicle {
public:
	void drive(void) override {
		cout << "Cas is moving..." << endl;
	}
};

class Truck : public Vehicle {
public:
	void drive(void) override {
		cout << "Truck is moving..." << endl;
	}
};

class Motocycle : public Vehicle {
public:
	void drive(void) override {
		cout << "Motocycle is moving..." << endl;
	}
};

class Bicycle : public Vehicle {
public:
	void drive(void) override {
		cout << "Bicycle is moving..." << endl;
	}
};

class Driver {
public:
	Driver() {
		cout << "The driver starts the engine..." << endl;
	}
	void move(Vehicle& v) {
		v.drive();
	}
};

class T {

};

class Q {
public:
	void set(void) {};
};

class V {
public:
	virtual void foo1(void) {};
	virtual void foo2(void) {};
	virtual void foo3(void) {};
	virtual void foo4(void) {};
	virtual void foo5(void) {};
};

//
int main()
{
	A* arr[CLASS_NUMBER] = {new A, new B, new C};

	for (int i = 0; i < CLASS_NUMBER; i++) {
		arr[i]->process();
	}

	cout << "-----------------------------" << endl;

	Car car;
	Truck truck;
	Motocycle motocycle;
	Bicycle bicycle;

	Driver drv;
	drv.move(car);
	drv.move(truck);
	drv.move(motocycle);
	drv.move(bicycle);

	cout << "-----------------------------" << endl;

	cout << "Size of Empty class: " << sizeof(T) << endl;
	cout << "Size of Not Empty class: " << sizeof(Q) << endl;
	cout << "Size of Virtual class: " << sizeof(V) << endl;

	return 0;
}
