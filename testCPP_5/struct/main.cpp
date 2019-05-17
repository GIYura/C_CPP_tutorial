#include <iostream>

using namespace std;

/*Struct*/
struct Point{
    private :
        int x;
        int y;
    public:
        int getX();
        int getY();
        void setX(int);
        void setY(int);
};

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}

void Point::setX(int val){
    x = val;
}

void Point::setY(int val){
    y = val;
}
/*Class*/
class Coord{
    int x, y;
public:
    void setX(int);
    void setY(int);
    int getX();
    int getY();

    Coord();
    Coord(int);
    ~Coord();
};

void Coord::setX(int val){
    x = val;
}

void Coord::setY(int val){
    y = val;
}

int Coord::getX(){
    return x;
}

int Coord::getY(){
    return y;
}

Coord::Coord(){
    setX(2);
}

Coord::Coord(int val){
    setX(val);
    setY(val);
}

Coord::~Coord(){

}

int main()
{
    Point p;
    p.setX(100);
    p.setY(200);

    cout << "x = " << p.getX() << endl;
    cout << "y = " << p.getY() << endl;

    Coord c(50);

    cout << "x = " << c.getX() << endl;
    cout << "y = " << c.getY() << endl;

    c.setX(30);
    c.setY(20);

    cout << "x = " << c.getX() << endl;
    cout << "y = " << c.getY() << endl;

    Coord *t = new Coord(3);
    t->setX(444);
    t->setY(777);

    cout << "x = " << t->getX() << endl;
    cout << "y = " << t->getY() << endl;

    return 0;
}
