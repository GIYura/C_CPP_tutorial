// deque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

template<typename T>
void print_dq(const deque<T>& dq) {
	for (auto n : dq) {
		cout << n << ' ';
	}
	cout << endl << "----------------------" << endl;
}

template<typename T>
void print_vec(const vector<T>& vec) {
	for (auto n : vec) {
		cout << n << ' ';
	}
	cout << endl << "----------------------" << endl;
}

int main()
{
	deque<int> dq = { 1, 44, 99, 0 };

	cout << "Deque: ";
	for (auto n : dq) {
		cout << n << ' ';
	}
	cout << endl;
	
	
	cout << "Front: " << dq.front() << endl;

	cout << "Back: " << dq.back() << endl;

	cout << "Deque_1: " ;
	deque<int> dq_1;
	for (int i = 0; i < 10; ++i) {
		dq_1.push_back(i);
	}

	deque<int>::const_iterator it = dq_1.cbegin();
	advance(it, 5);

	dq_1.insert(it, 9999);

	for (auto n : dq_1) {
		cout << n << ' ';
	}

	cout << endl << "Deque_1 size: " << dq_1.size() << endl;
	cout << "Deque_1 Front: " << dq_1.front() << endl;
	cout << "Deque_1 Back: " << dq_1.back() << endl;

	dq_1.push_back(1000);
	print_dq(dq_1);
	cout << "Size: " << dq_1.size() << endl;

	dq_1.push_front(-8888);
	print_dq(dq_1);
	cout << "Size: " << dq_1.size() << endl;

	dq_1.pop_back();
	print_dq(dq_1);
	cout << "Size: " << dq_1.size() << endl;

	it = dq_1.begin();
	dq_1.erase(dq_1.begin(), dq_1.begin() + 3);
	print_dq(dq_1);

	dq_1.clear();
	print_dq(dq_1);

	deque<int> dq_2 = {10,20,30};
	auto it_1 = dq_2.emplace(dq_2.begin() + 2, 100);
	print_dq(dq_2);

	auto it_3 = dq_2.begin() + 2;
	dq_2.emplace(it_3, 1000);
	print_dq(dq_2);

	vector<int> x;
	vector<int> y = {1,2,3,4,5};
	cout << "X vector: ";
	print_vec(x);
	cout << "Y vector: ";
	print_vec(y);
	x = y;
	cout << "X vector after copy: ";
	print_vec(x);

	return 0;
}

