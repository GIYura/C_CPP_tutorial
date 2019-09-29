// abstract.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Instrument {
public:
	virtual void play(void) = 0;
};

class Percussion : public Instrument {

public:
	void play(void) override {
		cout << "BAM! BAM! BAM!" << endl;
	}
};

class Stringed : public Instrument {
public:
	void play(void) override {
		cout << "BRING! BRING! BRING!" << endl;
	}
};

class Wind : public Instrument {
public:
	void play(void) override {
		cout << "BLOW! BLOW! BLOW!" << endl;
	}
};

void tune(Instrument& instr) {
	instr.play();
}

//
//
//
class Pet {
public:
	virtual void eat(void) = 0;
	virtual void speak(void) = 0;
};

void Pet::eat(void) {
	cout << "The Pet is eating..." << endl;
}

void Pet::speak(void) {
	cout << "The Pet is speaking..." << endl;
}

class Dog : public Pet {
public:
	void eat(void) {
		Pet::eat(); 
	}

	void speak(void) {
		Pet::speak();
	}
};

int main()
{
	Wind flute;
	Stringed guitar;
	Percussion drum;

	tune(flute);
	tune(guitar);
	tune(drum);

	Dog rich;
	rich.eat();
	rich.speak();

	return 0;
}
