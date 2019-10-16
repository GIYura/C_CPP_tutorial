// alg_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

int main()
{
	int v[] = { 1,2,3,4 };

	auto sum = accumulate(next(begin(v)), end(v), to_string(v[0]), [](string a, int b) {
		return a + "-" + to_string(b);
	});

	cout << "Summ: " << sum << endl;

	return 0;
}

