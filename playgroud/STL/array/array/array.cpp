// array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 10> arr = {7,5,4,2,-88,999};

	for (auto n : arr) {
		cout << n << ' ';
	}
	cout << endl;

	try
	{
		cout << "At: " << arr.at(9) << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	cout << "Size: " << arr.size() << endl;

	cout << "Empty: " << arr.empty() << endl;

	cout << "Max size: " << arr.max_size() << endl;

	cout << "Front:" << arr.front() << endl;

	cout << "Back: " << arr.back() << endl;

	cout << "At position [5]: " << arr.at(5) << endl;

	arr.fill(2);

	cout << "Array after fill: ";
	for (auto& n : arr) {
		cout << n << ' ';
	}
	cout << endl << "----------------------" << endl;

	array<int, 5> x = {1,2,3,4,5};
	array<int, 5> y = {11,22,33,44,55};
	cout << "Array X before swap: ";
	for (auto n : x) {
		cout << n << ' ';
	}
	cout << endl;
	cout << "Array Y before swap: ";
	for (auto n : y) {
		cout << n << ' ';
	}
	cout << endl;

	x.swap(y);

	cout << "Array X after swap: ";
	for (auto n : x) {
		cout << n << ' ';
	}
	cout << endl;
	cout << "Array Y after swap: ";
	for (auto n : y) {
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}