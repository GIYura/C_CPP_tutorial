// alg_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

class Student {

public:
	string name;
	double score;

	Student(string name, double score) : name(name), score(score) {}

	//bool operator()(const Student& st) {
	//	return st.score > 150;
	//}
};

int main()
{
	const int SIZE = 11;
	int arr[SIZE] = {100, 10099, -2, 6, 7, 8, 0, -5, -7, 88, 39000};

	sort(arr, arr + SIZE, compare);

	for (auto n : arr) {
		cout << n << ' ';
	}
	cout << endl;

	vector<Student> students = {
									Student("Greg", 59),
									Student("Martin", 199),
									Student("Mary", 166),
									Student("Katrine", 133),
									Student("Andy", 155),
									Student("Bob", 122),
									Student("David", 111),
								};
	cout << endl;

	sort(students.begin(), students.end(), [](const Student& s1, const Student& s2)
		{
			return s1.name < s2.name;
		}
	);

	cout << "Name\tScore" << endl << "------------------" << endl;
	for (auto& n : students) {
		cout << n.name << '\t' << n.score << endl;
	}
	cout << endl;

	return 0;
}
