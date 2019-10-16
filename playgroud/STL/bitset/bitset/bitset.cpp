// bitset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	enum bits
	{
		S0 = 0,
		S1 = 1,
		S2 = 2,
		S3 = 3,
		S4 = 4,
		S5 = 5,
		S6 = 6,
		S7 = 7
	};

	bitset<8> state;

	cout << "Size: " << state.size() << endl;

	state.set();

	cout << "Set all: " << state << endl;

	state.reset();

	cout << "Reset all: " << state << endl;

	state.set(0);
	state.set(2);
	state.set(4);

	cout << "Set individual: " << state << endl;

	cout << boolalpha;

	for (int i = 0; i < state.size(); i++) {
		cout << state.test(i) << endl;
	}

	state.reset();

	cout << "Reset: " << state << endl;

	state.flip(S1);
	state.flip(S3);
	state.flip(S7);

	cout << "Flip: " << state << endl;

	bitset<8> a;
	bitset<8> b;

	a.set();
	b.reset();

	cout << "Bitwise OR: " << (a | b) << endl;
	cout << "Bitwise AND: " << (a & b) << endl;
	cout << "Bitwise XOR: " << (a ^ b) << endl;

	cout << "Bitwise OR individual: " << a[0] << b[1] << ": " << (a[0] | b[1]) << endl;

	return 0;
}
