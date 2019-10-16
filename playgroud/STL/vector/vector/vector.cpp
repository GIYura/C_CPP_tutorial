// vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr = {1,2,3,4};

	try
	{
		cout << arr.at(22) << endl;
	}
	catch (const std::out_of_range& ex)
	{
		cout << ex.what() << endl;
	}

	for (int n : arr) {
		cout << n << ' ';
	}
	cout << endl;
	cout << "Vector size: " << arr.size() << endl;
	cout << "Vector capacity: " << arr.capacity() << endl;
	arr.push_back(44);
	cout << "Vector size: " << arr.size() << endl;
	cout << "Vector capacity: " << arr.capacity() << endl;
	arr.pop_back();

	cout << "Vector size: " << arr.size() << endl;
	cout << "Vector capacity: " << arr.capacity() << endl;

	return 0;
}