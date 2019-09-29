// polymorphism_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Pet {
	string m_name;
public:
	Pet(string name) : m_name(name){}
	virtual ~Pet() {};

	virtual string speak(void) { return ""; };
};

class Dog : public Pet {

public:
	Dog(string name) : Pet(name) {}

	string speak(void) override { return "Bark!"; };

	virtual string sit(void) { return "The dog sits"; };
};

class Cat : public Pet {

public:
	Cat(string name) : Pet(name) {}

	string speak(void) override { return "Mao!"; };

	virtual string sleep(void) { return "The cat sleeps"; };
};

int main()
{
	Pet* p[] = {new Dog("Spike"), new Cat("Tom")};

	cout << p[0]->speak() << endl;
	cout << p[1]->speak() << endl;
	cout << ((Dog*)p[0])->sit() << endl;
	cout << ((Cat*)p[1])->sleep() << endl;

	return 0;
}
