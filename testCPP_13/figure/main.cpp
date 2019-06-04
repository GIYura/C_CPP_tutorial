#include <iostream>

using namespace std;


class Figure{
protected :
    double x, y;
public:
    void setDim(double i, double j = 0){ x = i, y = j; }

    virtual void showArea() {
        cout << "For this class area is undefined" << endl;
    }
};

class Triangle : public Figure{
public:
    void showArea() {
        cout << "Triangle with Height " << x << " and Base " << y << " area = " << x * 0.5 * y << endl;
    }
};

class Rectangle : public Figure{
public:
    void showArea() {
        cout << "Rectangle with Height " << x << " and Width " << y << " area = " << x * y << endl;
    }
};

class Circle : public Figure{
public:
    void showArea() {
        cout << "Circle with radius " << x << " area = " << 3.14 * x * x << endl;
    }
};

int main()
{
    Figure *fig = new Figure();
    fig->setDim(18.4, 55.9);
    fig->showArea();

    Rectangle rect;
    fig = &rect;

    fig->setDim(12.8, 0.7);
    fig->showArea();

    Triangle tri;
    fig = &tri;
    fig->setDim(2.99, 77.14);
    fig->showArea();

    Circle c;
    fig = &c;
    fig->setDim(33.8);
    fig->showArea();

    return 0;
}
