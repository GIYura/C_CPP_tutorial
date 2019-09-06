#include <iostream>

using namespace std;

class Point{
    int x;
    int y;

public:
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    void show_info(){
        cout << "X: " << this->x << endl;
        cout << "Y: " << this->y << endl;
    }
};

int main()
{
    Point p1(2, 222);
    p1.show_info();

    Point p2(33, 44);
    p2.show_info();

    return 0;
}
