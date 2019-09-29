// inheritance_private.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Pet {
public:
	void eat(void) {
		cout << "Eating..." << endl;
	};
	void sleep(void) {
		cout << "Sleeping..." << endl;
	};
	void voice(void) {
		cout << "Maiking noise..." << endl;
	};
	void jump(void) {
		cout << "Jumping..." << endl;
	};
};

class Fish : Pet {
public:
	Pet::eat;
};

class Parrot : Pet {
public:
	Pet::eat;
	Pet::voice;
};

//
int main()
{
	Fish sparky;

	Parrot spooky;

	sparky.eat();
	
	spooky.voice();

	return 0;
}
