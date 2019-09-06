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
    void set_x(int x){
        this->x = x;
    };
    void set_y(int y){
        this->y = y;
    };

    int get_x(){return x;};
    int get_y(){return y;};

    void show_info(){
        cout << "X:" << get_x() << endl;
        cout << "Y:" << get_y() << endl;
        cout << "Address: " << this << endl;
    };
};

class Pixel{
    public:
    Point* p = new Point(2,3);
};

int main()
{
    Point p1(1,2);
    p1.show_info();

    Point p2(3,4);
    p2.show_info();

    Pixel p3;
    p3.p->show_info();

    return 0;
}
