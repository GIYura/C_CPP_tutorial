// factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using namespace std;

class Shape {
public:
	double x, y;
	Shape(double x, double y) : x(x), y(y) {}
	virtual ~Shape() {};

	virtual double area(void) = 0;
};

class Rectangle : public Shape {
public:
	Rectangle(double x, double y) : Shape(x, y) {}
	double area(void) override {
		return x * y;
	}
};

class Triangle : public Shape {
public:
	Triangle(double x, double y) : Shape(x, y) {}
	double area(void) override {
		return x * y * 0.5;
	}
};

class Circle : public Shape {
public:
	Circle(double x, double y = 0) : Shape(x, y) {}
	double area(void) override {
		return 3.14 * x * x;
	}
};

Shape* factory(void) {
	switch (rand() % 3)
	{
		case 0:
			return new Circle(5.0);
			break;

		case 1:
			return new Rectangle(5.0, 5.0);
			break;

		case 2:
			return new Triangle(5.0, 5.0);
			break;

		default:break;
	}
}

int main()
{
	srand(time(NULL));
	Shape* sp;
	int cirle_counter = 0;
	int triangle_counter = 0;
	int rectangle_counter = 0;

	for (int i = 0; i < 10; i++) {
		sp = factory();

		if (typeid(*sp) == typeid(Triangle)) {
			triangle_counter++;
		}

		if (typeid(*sp) == typeid(Rectangle)) {
			rectangle_counter++;
		}

		if (typeid(*sp) == typeid(Circle)) {
			cirle_counter++;
		}
		cout << "Type: " << typeid(*sp).name() << "\t" << "Area: " << sp->area() << endl;
	}

	cout << "Circle numer: " << "\t\t" << cirle_counter << endl;
	cout << "Triangle numer: " << "\t" << triangle_counter << endl;
	cout << "Rectangle numer: " << "\t" << rectangle_counter << endl;

	return 0;
}
