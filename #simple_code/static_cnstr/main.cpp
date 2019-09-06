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

class Test{
    int a;
    int b;
    static int c;
public:
    void seta(int a){this->a = a;};
    void setb(int b){this->b = b;};
    int geta(){return this->a;};
    int getb(){return this->b;};

    static void setA(Test* t, int a) {
        t->a = a;
    };

    static void setC(int newc){
        c = newc;
    };

    static int getC(){return c;};

    Test(){
        a = 33;
    };
};

int Test::c;

int main()
{
    Test* t1 = new Test();
    t1->seta(10);
    t1->setb(20);
    cout << "A: " << t1->geta() << endl;
    cout << "B: " << t1->getb() << endl;

    Test::setA(t1, 55);
    cout << "A: " << t1->geta() << endl;

    Test::setC(77);
    cout << "C: " << Test::getC() << endl;

    return 0;
}
