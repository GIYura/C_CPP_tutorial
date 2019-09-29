// polymorphism_quantum_leap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Shape {
	int w;
	int h;
public:
	Shape(int x, int y) {};
	virtual ~Shape() {};

	void move_by(int x, int y);
	int distance_from(Shape const* other) const;

	virtual void draw(void) {
		cout << "Draw shape" << endl;
	};

	virtual int area(void) {
		cout << "Area shape" << endl;
		return 0;
	};
};

class Rectangle : public Shape {
	int w;
	int h;
public:
	Rectangle(int x, int y, int h, int w) : Shape(x, y){};
	void draw(void) override {
		cout << "Draw rectangle" << endl;
	};
	int area(void) override {
		cout << "Area rectangle" << endl;
		return 1;
	};
};

class Triangle : public Shape {
	int w;
	int h;
public:
	Triangle(int x, int y, int h, int w) : Shape(x, y) {};
	void draw(void) override {
		cout << "Draw triangle" << endl;
	};
	int area(void) override {
		cout << "Area triangle" << endl;
		return 1;
	};
};

void draw_graph(Shape* graph[]);

//
int main()
{
	Rectangle r1(1,2,3,4);
	r1.draw();			//early binding

	Shape* graph[] =	{	new Rectangle(1,2,3,4), 
							new Triangle(1,2,3,4),
							(Shape*) 0
						};

	draw_graph(graph);

	return 0;
}


void draw_graph(Shape* graph[]) {
	for (int i = 0; graph[i] != (Shape*)0; i++) {
		graph[i]->draw();
	}
}