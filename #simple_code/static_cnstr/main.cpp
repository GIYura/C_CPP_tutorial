#include <iostream>

using namespace std;

class Point{
private:
    int x;
    int y;

public:
    int get_x();
    int get_y();
    void set_x(int);
    void set_y(int);

    Point();
};

int Point::get_x(){
    return this->x;
}

int Point::get_y(){
    return this->y;
}

void Point::set_x(int x){
    this->x = x;
}

void Point::set_y(int y){
    this->y = y;
}

int main()
{

    return 0;
}
