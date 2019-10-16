// stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main()
{
	stack<int> st;
	
	st.push(10);
	st.push(11);
	st.push(12);
	st.push(13);
	st.push(14);
	st.push(15);
	
	cout << "Empty: " << st.empty() << endl;

	cout << "Size: " << st.size() << endl;

	cout << "Top: " << st.top() << endl;

	cout << "Pop: ";
	/*
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
	*/
	cout << endl;

	auto a = st._Get_container();

	cout << "Deque: " << a.front() << endl;

	vector<int> v = {1,2,3,4};

	return 0;
}
