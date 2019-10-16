// compare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>

using namespace std;
int main()
{
	array<int, 5> x = {3,66,99,0,6};
	array<int, 5> y = {3,66,99,0,6};

	bool result = (x > y);

	cout << result << endl;

	return 0;
}
