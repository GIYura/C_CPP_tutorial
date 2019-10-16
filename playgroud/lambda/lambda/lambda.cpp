// lambda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

void in_range(int a) {
	cout << "In range is working..." << endl;
	if (a > 10 && a < 50) {
		cout << "Value in range: " << a << endl;
	}
}

void is_odd(int a) {
	cout << "Is odd is working..." << endl;
	if (a % 2 == 0) {
		cout << "Odd value: " << a << endl;
	}
}

void work(vector<int>& v, vector<function<void(int)>>fv) {
	cout << "Work is working..." << endl;
	for (auto& n : v) {
		for (auto& l : fv) {
			l(n);
		}
	}
}

void do_work(vector<int>& v, function<void(int)> f) {
	//cout << "DO_work is working..." << endl;
	for (auto n : v) {
		f(n);
	}
}

int main()
{
	vector<int> x = {-99,7,55,88,2,3,4,5,22,34,45,49};
	//vector<function<void(int)>> fv = {is_odd, in_range};
	
	//work(x, fv);

	//function<void(int)> f;

	int s = 9;

	cout << "S: " << s << endl;

	auto f = [&s]() {
		s = 10;
	};

	f();

	cout << "S: " << s << endl;

	/*
	do_work(x, [](int a) {
		cout << "---Lambda is working..." << endl;
		if (a > 10) {
			cout << "Value greater 10: " << a << endl;
		}
	});
	*/

	struct my_t {
		int a;
		int b;
		int c;
		int d;
	};

	cout << &(((struct my_t*)(0))->a) << endl;
	cout << &(((my_t*)(0))->b) << endl;
	cout << &(((my_t*)(0))->c) << endl;
	cout << &(((my_t*)(0))->d) << endl;

	return 0;
}
