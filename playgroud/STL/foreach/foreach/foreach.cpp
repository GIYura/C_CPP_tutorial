// foreach.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void print_collection(const T& collection);

int main()
{
	vector<int> data = {-44, 88, 0, 3, 111};

	for (auto& n : data)
	{
		n = 10;
		cout << n << ' ';
	}

	cout << endl << endl;

	for (auto n : data) {
		cout << n << ' ';
	}

	cout << endl << endl;

	list<float> f_data = {2.33, 6.88, 9.01};
	for (auto n : f_data)
	{
		cout << n << ' ';
	}

	cout << endl << endl;

	vector<int> i_vec = {4,5,-22,6,0};
	list<int> i_lst = {9,55,1000,-888};

	print_collection(i_vec);
	print_collection(i_lst);

	return 0;
}


template<typename T>
void print_collection(const T& collection) {
	cout << endl << "-----------------------" << endl;
	for (auto n : collection) {
		cout << n << ' ';
	}
	cout << endl << "-----------------------" << endl;
}