// alg_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <list	>

using namespace std;

int main()
{
	cout << boolalpha;

	vector<int> arr_1 = {99,2,3,4,5,6,7,8,999,1,2,3,23,234,234};
	vector<int> arr_2 = {234,2,3,4,5,6,7,8,999,1,2,3,23,234,99};

	cout << "Initial collection 1:" << endl;
	for (auto n : arr_1) {
		cout << n << ' ';
	}
	cout << endl;

	cout << "Initial collection 2:" << endl;
	for (auto n : arr_2) {
		cout << n << ' ';
	}
	cout << endl;

	sort(begin(arr_1), end(arr_1));

	cout << "Sorted collection 1:" << endl;
	for (auto n : arr_1) {
		cout << n << ' ';
	}
	cout << endl;

	sort(begin(arr_2), end(arr_2));
	cout << "Sorted collection 2:" << endl;
	for (auto n : arr_2) {
		cout << n << ' ';
	}
	cout << endl;

	bool res = equal(begin(arr_1), end(arr_1), begin(arr_2), end(arr_2));

	cout << "Is collection 1 equal collection 2: " << res << endl;



	return 0;
}
