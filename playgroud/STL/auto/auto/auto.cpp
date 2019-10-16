// auto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	auto i = 10;
	auto f = 2.33;
	auto s = "Hello";

	cout << "i type is: " << typeid(i).name() << endl;
	cout << "f type is: " << typeid(f).name() << endl;
	cout << "s type is: " << typeid(s).name() << endl;

	vector<int> data = {2,5,6,-44};
	vector<int>::iterator it = data.begin();
	for (; it != data.end(); ++it) {
		cout << *it << ' ';
	}

	return 0;
}
