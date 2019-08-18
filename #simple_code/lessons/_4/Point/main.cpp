#include <iostream>

using namespace std;

class Point{
    int x = 1;

public:
    int y = 2;

protected:
    int z = 3;

public:
    void show_info(){
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
        cout << "Z: " << z << endl;
    };
};

int main()
{
    Point p1;
    p1.show_info();

    return 0;
}
