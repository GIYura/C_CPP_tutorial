// inheritance_protected.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Base {
	int m_data;
protected:
	void send(void) {
		cout << "SENDING..." << endl;
	};
	void receive(void) {
		cout << "RECEIVING..." << endl;
	};

public:
	Base(int data) : m_data(data) {};
	void set_data(int data) { this->m_data = data; };
	int get_data() { return m_data; };
};

class Derived : public Base {
	int data;
public:
	Derived() : Base(0), data(0) {};

	void change(void) {
		send();
		receive();
		set_data(5555);
	};
};

int main()
{
	Derived d;

	d.change();

	cout << d.get_data() << endl;

	return 0;
}