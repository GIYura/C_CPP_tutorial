// alg_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {

public:
	string name;
	double score;
	int age;

	Person(string name, double score, int age) : name(name), score(score), age(age) {}

	bool operator()(const Person& p) {
		return p.score > 150;
	}
};


int main()
{
	vector<Person> people = {
								Person("Bob", 180.8, 22),
								Person("Adam", 152.5, 21),
								Person("Fill", 129.1, 40),
								Person("Candy", 111.9, 20),
								Person("Mary", 122.3, 22),
								Person("Monica", 199.9, 23),
								Person("Bill", 90.8, 21),
								Person("Candy", 118.7, 23),
								Person("Den", 118.7, 34),
								Person("Max", 148.2, 23),
								Person("Sam", 188.6, 33),
	};

	auto result = remove_if(people.begin(), people.end(), [](const Person& p) {
		return p.age > 20;
	});

	people.erase(result, people.end());

	for (auto n : people) {
		cout << n.name << "\t" << n.age << "\t" << n.score << endl;
	}
	
	string text = "This line containes several spaces";
	cout << text << endl;

	text.erase(remove(text.begin(), text.end(), ' '), text.end());

	cout << text << endl;

	return 0;
}
