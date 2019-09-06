#include <iostream>

using namespace std;

class Point{
    int id;

public:
    Point(int id){
        this->id = id;

        cout << "ID: " << this->id << "  "<< "Constructor started" << endl;
    };
    ~Point(){
        cout << "ID: " << this->id << "  " << "Destructor started" << endl;
    };
};

int main()
{
    Point point1(1);
    Point point2(2);

    return 0;
}
