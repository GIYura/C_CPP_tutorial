// function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

void foo(void) {
	cout << "Foo is working..." << endl;
}

void bar(void) {
	cout << "Bar is working..." << endl;
}

int summ(int a, int b) {
	cout << "Summ is working..." << endl;
	return a + b;
}

void in_range(int a) {
	if (a > 10 && a < 40) {
		cout << "In range value: " << a << endl;
	}
}

void is_even(int a ) {
	if (a % 2 == 0) {
		cout << "Even value: " << a << endl;
	}
}

void work(const vector<int>& v, vector<function<void(int)>> fv) {
	for (auto& n : v) {
		for (auto& l : fv) {
			l(n);
		}
	}
}

int main()
{
	function<int(int, int)> f;

	f = summ;

 	int ret = f(3, 66);

	cout << "Sum: " << ret << endl << "---------------------" << endl;

	vector<int> v = {2,6,7,4-7,0,88,5,33,12,77,10};

	vector<function<void(int)>> fv;
	fv.emplace_back(in_range);
	fv.emplace_back(is_even);

	work(v, fv);

	return 0;
}
