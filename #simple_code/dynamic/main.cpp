#include <iostream>

using namespace std;

class Point{
    int x;
    int y;

public:
    Point(int x, int y){
        this->x = x;
        this->y = y;
    };
    void set_x(int );
    void set_y(int );
    int get_x(void);
    int get_y(void);
};

int Point::get_x(){
    return x;
}

int Point::get_y(){
    return y;
}

void Point::set_x(int x){
    this->x = x;
}

void Point::set_y(int y){
    this->y = y;
}

int main()
{
    int* a  = new int;

    *a = 10;
    cout << *a << endl;

    Point* point = new Point(55, 66);

    if(nullptr == point){
        cout << "Can't allocate memory" << endl;
    }

    cout << "X = " << point->get_x() << endl;
    point->set_x(88);
    cout << "X = " << point->get_x() << endl;

    point->set_y(99);
    cout << "Y = " << point->get_y() << endl << endl;

    delete point;
    point = nullptr;

    //Point* point1 = new Point(100, 200);
    //point->set_x(77);
    //cout << "X = " << point->get_x() << endl;

    return 0;
}
