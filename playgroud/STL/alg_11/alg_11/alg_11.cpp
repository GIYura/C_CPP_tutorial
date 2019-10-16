// alg_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = {11,11,12,12,13,13,14,14,15,15};
	cout << "Size: " << v.size() << endl;
	auto res = unique(begin(v), end(v));

	v.erase(res, end(v));

	cout << "Unique: " << endl;
	for (auto n : v) {
		cout << n << ' ';
	}
	cout << endl;
	cout << "Size: " << v.size() << endl;

	vector<int> v1;
	unique_copy(begin(v), end(v), back_inserter(v1));
	for (auto n : v1) {
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}
