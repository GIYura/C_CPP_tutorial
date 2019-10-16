// queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;
	cout << "Size: " << q.size() << endl;

	q.emplace(1);
	q.emplace(2);
	q.emplace(3);
	q.emplace(4);
	q.emplace(5);

	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}

	queue<string> qs;
	qs.emplace("one");
	qs.emplace("two");
	qs.emplace("three");
	qs.emplace("four");

	while (!qs.empty())
	{
		cout << qs.front() << ' ';
		qs.pop();
	}



	return 0;
}
