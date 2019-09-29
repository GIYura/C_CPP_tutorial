// polymorphism_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Pet {
	string m_name;
public:
	Pet(string name) : m_name(name) {}
	virtual string get_name(void) { return this->m_name; };
	virtual string description(void) = 0;// { return "This is : " + this->m_name; };
};

class Dog : public Pet {
	string m_activity;
public:
	Dog(string name, string activity) : Pet(name), m_activity(activity) {}
	string description(void) override { return Pet::get_name() + " likes to " + m_activity; };
};

void describe(Pet& pet) {
	cout << pet.description() << endl;
}

int main()
{
	//Pet p("Parrot");
	Dog d("Fluffy", "jump");

	//describe(p);
	describe(d);

	return 0;
}
