// list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

template<typename T>
void print_list(const list<T>& lst);

class Test {

};

int main()
{
	list<int> my_list = {1,2,3,4,5,5,6,8};

	my_list.push_back(-1000);
	my_list.push_front(-5000);
	my_list.push_back(22);

	Test t;
	cout << typeid(t).name() << endl;
	cout << typeid(my_list).name() << endl;

	print_list(my_list);

	/*
	my_list.assign(20, 2);
	print_list(my_list);	
	*/

	my_list.sort();

	print_list(my_list);

	cout << my_list.size() << endl;

	return 0;
}

template<typename T>
void print_list(const list<T>& lst) {
	for (auto it = lst.cbegin(); it != lst.cend(); ++it) {
		cout << *it << ' ';
	}
	cout << endl << "=========================" << endl;
}