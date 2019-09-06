#include <iostream>

using namespace std;

class Point{
    int x;
    int y;
    bool z;
public:
    Point(){
        x = 0;
        y = 0;
    }

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    Point(int x, bool z){
        if(z){
            this->x = x;
            this->y = x;
        } else {
            this->x = 0;
            this->y = 0;
        }
    }
//    Point(int x, int y){
//        this->x = x;
//        this->y = y;
//    }

    void show_info(){
        cout << "X: " << this->x << endl;
        cout << "Y: " << this->y << endl;
    }
};

int main()
{
    Point p1;
    p1.show_info();

    Point p2(33, 66);
    p2.show_info();

    Point p3(88, true);
    p3.show_info();

    Point p4(55, false);
    p4.show_info();

    return 0;
}
