// forward_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

class Shape {

public:
	Shape() {};
	virtual ~Shape() {};
	virtual void draw() = 0;
};

class Triangle : public Shape {
public:
	Triangle() {};
	virtual ~Triangle() {};
	void draw() override{
		cout << "Triangle is drawing..." << endl;
	}
};

class Rectangle : public Shape {
public:
	Rectangle() {};
	virtual ~Rectangle() {};
	void draw() override {
		cout << "Rectangle is drawing..." << endl;
	}
};

class Circle : public Shape {
public:
	Circle() {};
	virtual ~Circle() {};
	void draw() override {
		cout << "Circle is drawing..." << endl;
	}
};

class Diamand : public Shape {
public:
	Diamand() {};
	virtual ~Diamand() {};
	void draw() override{
		cout << "Diamand is drawing..." << endl;
	}
};

void show(const vector<Shape*> vec) {
	for (auto it = vec.cbegin(); it != vec.cend(); ++it){
		(*it)->draw();
	}
}
//
int main()
{
	vector<Shape*> shapes = {new Triangle, new Rectangle, new Circle};
	show(shapes);
	shapes.push_back(new Diamand);
	show(shapes);

	cout << endl << "Forward list is working..." << endl << endl;

	forward_list<int> fl = {2,5,6,7,9999};
	fl.push_front(1000);
	fl.push_front(-1000);

	forward_list<int>::iterator it = fl.begin();

	cout << *it << endl;

	fl.insert_after(it, 777);

	auto a_it = fl.cbegin();
	advance(a_it, 3);
	fl.insert_after(a_it, 99);
	
	for (auto& el : fl) {
		cout << el << ' ';
	}

	cout << endl;

	return 0;
}
