// alg_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <array>

using namespace std;

int main()
{
	vector<int> vec = {-9,8,9,77,-6,-44,22,1,34,5,56};
	list<int> lst = {9,6,4,3,2,2,3,42,534,54,5,234,3,4,235,6,65,75,6};

	const int sz = 10;
	int arr[sz] = {9,8,7,6,5,4,3,2,1,10};

	auto min = min_element(arr, arr + sz);
	cout << "MIN arr: " << *min << endl;

	auto min_ = min_element(vec.begin(), vec.end());
	cout << "MIN vec: " << *min_ << endl;

	auto _min_ = min_element(lst.begin(), lst.end());
	cout << "MIN vec: " << *_min_ << endl;

	auto min_max = minmax_element(lst.begin(), lst.end());
	cout << "MIN: " << *min_max.first << '\t' << "MAX: " << *min_max.second << endl;

	return 0;
}
