// rtti_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Shape {
public:
	virtual void draw(void) {};
};

class Circle : public Shape {
	int id;
public: 
	void draw(void) override {
		cout << "Circle \t\t is drawing..." << endl;
	}
};

class Triangle : public Shape {
	int id;
public:
	void draw(void) override {
		cout << "Triangle \t is drawing..." << endl;
	}
};

class Rectangle : public Shape {
	int id;
public:
	void draw(void) override {
		cout << "Rectangle \t is drawing..." << endl;
	}
};

int main()
{
	vector<Shape*> shapes = {
								new Circle, 
								new Triangle, 
								new Rectangle
							};

	sort(begin(shapes), end(shapes));

	for (auto& n : shapes) {
		n->draw();
	}
	
	Shape* sp;

	sp = new Circle;
	Circle* cr = dynamic_cast<Circle*>(sp);

	sp = new Triangle;
	Triangle* tr = dynamic_cast<Triangle*>(sp);

	sp = new Rectangle;
	Rectangle* rec = dynamic_cast<Rectangle*>(sp);

	if (cr) {
		cout << "Circle cast successful" << endl;
	} 
	else {
		cout << "Circle cast NOT successful" << endl;
	}

	if (tr) {
		cout << "Triangle cast successful" << endl;
	}
	else {
		cout << "Triangle cast NOT successful" << endl;
	}

	if (rec) {
		cout << "Rectangle cast successful" << endl;
	}
	else {
		cout << "Rectangle cast NOT successful" << endl;
	}

	return 0;
}
