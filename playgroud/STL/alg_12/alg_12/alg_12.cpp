// alg_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

class I_Base {
public:
	virtual void action(void) = 0;
};

class Cat : public I_Base {
public:
	void action(void) override {
		cout << "Cat..." << endl;
	}
};

class Tea : public I_Base {
public:
	void action(void) override {
		cout << "Tea..." << endl;
	}
};

class Dog : public I_Base {
public:
	void action(void) override {
		cout << "Dog..." << endl;
	}
};

class Sleep : public I_Base {
public:
	void action(void) override {
		cout << "Sleep..." << endl;
	}
};

int main()
{
	srand(time(NULL));

	int arr[] = {1,2,3,4,5,6,7,8,9};

	random_shuffle(begin(arr), end(arr));

	cout << "Array: " << endl;
	for (auto n : arr) {
		cout << n << ' ';
	}
	cout << endl;

	I_Base* action[] = {	new Cat,
							new Tea,
							new Dog,
							new Sleep
						};

	random_shuffle(begin(action), end(action));

	for (auto& n : action) {
		n->action();
	}
	cout << endl;

	return 0;
}
