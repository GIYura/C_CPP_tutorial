// inline.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

#define BAND(x) (((x)>5 && (x)<10) ? (x) : 0)

#define SQR(x)  ((x) * (x))

#define MAX(a, b) (a > b ? a : b)

#define DOUBLE(x) ((x) + (x))

void fun(void);

inline int plus_one(int x);

int main()
{
	ofstream out("macro.txt");

	for (int i = 4; i < 11; i++) {
		int a = i;
		out << "a = " << a << endl;
		out << "BAND(++a)=" << BAND(++a) << endl;
		out << "a = " << a << endl;
		out << "--------------------" << endl;
	}

	int a = 3;
	a = SQR(a + 1); //a + 1 * a + 1;
	cout << "SQR: " << a << endl;

	int x = 1;
	int y = 33;

	cout << "MAX: " << MAX(y + 1, x + 2) << endl;

	int p = 2;
	cout << "DOUBLE: " << DOUBLE(++p) << endl;

#define MIN(x, y) (x < y ? x : y)

	fun();


	int q = 12;
	cout << "Q: " << q << endl;
	q = plus_one(q);
	cout << "Q: " << q << endl;

	return 0;
}

//
void fun(void) {
	enum MyEnum
	{

	};

	int x = 12;
	int y = 22;

	cout << "MIN: " << MIN(x, y) << endl;;
}

//
inline int plus_one(int x) {
	return ++x;
}