// iterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> data = {0, 11234, -999, 234, -7};

	for (vector<int>::iterator i = data.begin(); i != data.end(); i++) {
		cout << *i << ' ';
	}

	cout << "insert" << endl;

	vector<int>::iterator i = data.begin();

	advance(i, 3);

	data.insert(i, 1000);

	for (vector<int>::iterator i = data.begin(); i != data.end(); i++) {
		cout << *i << ' ';
	}

	vector<int>::iterator it = data.begin();

	it++;

	data.erase(it);

	cout << "erase" << endl;

	for (vector<int>::iterator i = data.begin(); i != data.end(); i++) {
		cout << *i << ' ';
	}

	return 0;
}
