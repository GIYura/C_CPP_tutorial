// set_multi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	set<int> s = {1,8,5,3,2,10,88,20};
	
	int value;

	//cin >> value;
	/*
	if ( s.find(value) != s.end() ) {
		cout << "Number: " << value << " Found" << endl;
	}
	else
	{
		cout << "Number: " << value << " NOT Found" << endl;
	}
	*/

	s.erase(20000);

	s.insert(1000);

	for (auto&n : s) {
		cout << n << ' ';
	}
	cout << endl;

	multiset<int> ms = {3,6,8,8,9,0,-33,6,8};
	for (auto n : ms) {
		cout << n << ' ';
	}
	cout << endl;

	auto it1 = ms.lower_bound(8);
	cout << "Lower bound: " << *it1 << endl;
	auto it2 = ms.upper_bound(8);
	cout << "Upper bound: " << *it2 << endl;

	return 0;
}
