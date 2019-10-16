// map.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<int, string> m;

	m.emplace(1, "phone");

	m.emplace(2, "notebook");

	m.emplace(3, "mouse");
	m.emplace(3, "mouse");
	m.emplace(3, "mouse");

 	auto res = m.find(33);

	if (res != m.end()) {
		cout << "Found " << endl;
		cout << res->first << ' ';
		cout << res->second << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	cout << m[3] << endl;


	return 0;
}
