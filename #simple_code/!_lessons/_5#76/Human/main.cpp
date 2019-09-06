#include <iostream>

using namespace std;

class Point{
    int x;
    int y;

public:
    void set_x(int x){this->x = x;};
    void set_y(int y){this->y = y;};
    int get_x(void){return this->x;};
    int get_y(void){return this->y;};

    void foo(Point* point){
        cout << "X::" << point->get_x() << endl;
        cout << "Y::" << point->get_y() << endl;
    };
};

int main()
{
    Point p1;
    p1.set_x(22);
    p1.set_y(33);

    cout << "X: " << p1.get_x() << endl;
    cout << "Y: " << p1.get_y() << endl;

    Point* p2 = new Point();
    if(nullptr == p2){
        cout << "Can't create point instance" << endl;
    }
    p2->set_x(55);
    p2->set_y(77);

    cout << "X: " << p2->get_x() << endl;
    cout << "Y: " << p2->get_y() << endl;

    p2->foo(p2);

    return 0;
}
