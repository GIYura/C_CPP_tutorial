// alg_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//find
//find_if
//find_if_not

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Language {
public:
	string name;
	double score;

	Language(string name, double score) : name(name), score(score) {}

	bool operator()(const Language& p) {
		return p.score > 150;
	}
};

int main()
{
	vector<int> v = {8,-100,12,44,66,2,88,68,1000,33};
	auto r = find_if(v.begin(), v.end(), [](int a) {
		return (a % 3 == 0);
	});
	if (r == v.end()) {
		cout << "Not found: " << endl;
	}
	else {
		cout << "Find: " << *r << endl;
	}

	vector<Language> l = {
							Language("Ada", 100),
							Language("Cobol", 120),
							Language("Scala", 88),
							Language("Python", 199),
							Language("Java", 144),
							Language("C#", 154),
							Language("C++", 133)
						};
	auto res = find_if(l.begin(), l.end(), [](const Language& lan) {
		return (lan.name == "Java");
	});

	if (res == l.end()) {
		cout << "Programming language is NOT found: " << endl;
	}
	else {
		cout << "Programming language is found: " << endl;
	}

	return 0;
}
