// downcast.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Pet { 
public: 
	virtual ~Pet() {} 
	virtual void speak(void) = 0;
};

class Dog : public Pet {
public:
	void speak(void) override {
		cout << "BARK!" << endl;
	}
};

class Cat : public Pet {
public:
	void speak(void) override {
		cout << "MAO!" << endl;
	}
};

int main()
{
	Pet* p = new Cat;
	p->speak();

	p = new Dog;
	p->speak();

	Dog* d = static_cast <Dog*>(p);
	cout << d << endl;

	Cat* c = static_cast <Cat*>(p);
	cout << c << endl;

	return 0;
}
