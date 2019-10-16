// alg_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool greater_zero(int x) {
	return x > 0;
}

bool is_odd(int x) {
	return ((x % 2) == 1);
}

bool less_zero(int x) {
	return x < 0;
}

template <typename T>
void show_vec(const vector<T>& v) {
	cout << "Initial vector: ";
	for (auto n : v) {
		cout << n << ' ';
	}
	cout << endl << "----------------------" << endl;
}

class Student {
public:
	string name;
	double score;

	Student(string name, double score) : name(name), score(score){}

	bool operator()(const Student& st) {
		return st.score > 150;
	}
};

int main()
{
	cout << boolalpha;
	cout << "Result: " << greater_zero(-1) << endl;

	vector<int> v = {2,7,-55,7,-99,0};
	show_vec(v);

	int res = count_if(v.begin(), v.end(), greater_zero);
	cout << "Vector contains : " << res << " values > 0" << endl;

	vector<int> a;	
	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}

	show_vec(a);

	res = count_if(a.begin(), a.end(), is_odd);
	cout << "Vector contains: " << res << " odd values" << endl;

	vector<int> b = {-5,8,-9,77,33,-100};
	show_vec(b);

	res = count_if(b.begin(), b.end(), less_zero);
	cout << "Vector contains: " << res << " values < 0" << endl;

	vector<Student> st = {
							Student("Peter", 120),
							Student("Mark", 188),
							Student("Bob", 133),
							Student("Steven", 199),
							Student("Laura", 144),
							Student("Mike", 177),
							Student("Sofia", 129),
						};
	cout << "Name\t" << "Score" << endl;
	cout << "------------------------" << endl;
	for (auto n : st) {
		cout << n.name << "\t" << n.score << endl;
	}

	int r = count_if(st.begin(), st.end(), st.front());
	cout << "Students score > 150: " << r << endl;

	return 0;
}
