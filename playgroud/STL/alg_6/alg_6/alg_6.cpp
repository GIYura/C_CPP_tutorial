// alg_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <array>

using namespace std;

int main()
{
	//vector<int> vec = {1,4,5,-9,88,56,555};

	//list<int> lst = {-10,46,-57,-98,898,560};

	const int SIZE = 10;

	int arr[SIZE] = { 88, 90, 77, 5, 445, -88, -5, 0, 444, 9 };

	auto max = max_element(arr, arr + SIZE);

	cout << "Max: " << *max << endl;


	return 0;
}
