// inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//IS-A relationship
//Composition is generally used when you want the features of an existing class inside your new class, but not its interface.

/*
Conclusion The is-a relationship is expressed with inheritance, and the has-a relationship is expressed with composition
*/

#include <iostream>
using namespace std;

class Human {
	string m_name;
	string m_gender;
public:
	Human(string name, string gender) : m_name(name), m_gender(gender) {
		cout << "The Human created" << endl;
	};
	virtual ~Human() {
		cout << "The Human destroyed" << endl;
	};

	void set_name(string name) {
		this->m_name = name;
	};

	void set_gender(string gender) {
		this->m_gender = gender;
	}

	string get_name(void) {
		return this->m_name;
	}

	string get_gender(void) {
		return this->m_gender;
	}
};

class Person : public Human {

public:
	Person(string name, string gender) : Human(name, gender){
		cout << "The Person created" << endl;
	}
	virtual ~Person() {
		cout << "The Person destroyed" << endl;
	}
};

//
class A {
	int i;
	float f;
	char c;
	double d;
	string str;
public:
	A() : i(10), f(3.14), c('C'), d(2.77), str("Hello"){

	}

	void show(void) {
		cout << "I: " << i << "\tF: " << f << "\tc: " << c << "\tD: " << d << "\tstr: " << str << endl;
	}
};

class X {
	int x;
public:
	X(int x) : x(x){}
	virtual ~X() {};
	void show(void) {
		cout << "x: " << this->x << endl;
	}
};

class Y {
	int y;
public:
	Y(int y) : y(y) {}
	virtual ~Y() {};
	void show(void) {
		cout << "y: " << this->y << endl;
	}
};

//Z inherits from Y and has a member of object (IS COMPOSED OF) of type X.
// !!! Notice that the only time you can talk about redefinition of functions is during
// inheritance; with a member object you can only manipulate the public interface of the object, not redefine it.

class Z : public Y {
	X m_x;
public:
	Z(int i) : Y(i), m_x(i){}
	virtual ~Z() {};
	void show() {		//this function redefines the same function in Y
		m_x.show();
		Y::show();
	}
};

class Base {
public:
	int f() const {
		cout << "Base::f()" << endl;
		return 1;
	}

	int f(string str) const { return 1; };
	void g() {};
};

class Derived1 : public Base {
public:
	void g() const {};
};

class Derived2 : public Base {
public:
	// Redefinition:
	int f() const {
		cout << "Derived2::f()\n";
		return 2;
	}
};

class Derived4 : public Base {
public:
	// Change argument list:
	int f(int) const {
		cout << "Derived4::f()\n";
		return 4;
	}
};

class Derived3 : public Base {
public:
	// Change return type:
	void f() const { cout << "Derived3::f()\n"; }
};

class Engine {
public:
	void start(void) {
		cout << "The engine started" << endl;
	};
	void stop(void) {
		cout << "The engine stopped" << endl;
	};
};

class Wheel {
	int m_pressure;
public:
	void inflate(int pressure) {
		cout << "The wheel inflated" << endl;
	};
};

class Window {
public:
	void roll_up(void) {
		cout << "The window is UP" << endl;
	};
	void roll_down(void) {
		cout << "The window is DOWN" << endl;
	};
};

class Door {
public:
	void open() {
		cout << "The door is OPEN" << endl;
	};
	void close() {
		cout << "The door is CLOSE" << endl;
	};
};

class Car {
	string make;
public:
	Engine m_engine;
	Wheel m_wheel[4];
	Window m_window[4];
	Door m_door[4];

	Car(string make) : make(make){
		m_engine.stop();

		m_wheel[0].inflate(20);
		m_wheel[1].inflate(20);
		m_wheel[2].inflate(20);
		m_wheel[3].inflate(20);

		m_window[0].roll_up();
		m_window[1].roll_up();
		m_window[2].roll_up();
		m_window[3].roll_up();

		m_door[0].close();
		m_door[1].close();
		m_door[2].close();
		m_door[3].close();
	};
	virtual ~Car() {};
};

//
//
//
int main()
{
	Person p1("Barnaba", "Male");

	cout << "Persn name is: " << p1.get_name() << endl;
	cout << "Persn gender is: " << p1.get_gender() << endl;

	A a;
	a.show();

	X x(10);
	x.show();

	cout << "-------------------------" << endl;

	Z z(22);
	z.show();

	cout << "-------------------------" << endl;

	string s("Hello");
	Derived1 dr1;
	int v = dr1.f();
	dr1.f(s);
	dr1.g();
	//
	Derived2 dr2;
	dr2.f();
//	dr2.f(s); //unavailable
	dr2.g();

	cout << "-------------------------" << endl;
	Car car("Opel");

	car.m_door[0].open();
	car.m_window[2].roll_down();

	cout << "-------------------------" << endl;

	return 0;
}