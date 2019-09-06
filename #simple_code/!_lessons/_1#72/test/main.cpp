#include <iostream>

/*
Intro Lesson
There are 3 "wales" in OOP:
- encapsulation;
- inheritance;
- polymorphism;
*/

using namespace std;

class Hello{

public:
    void show_info(){
        cout << "Hello world!" << endl;
    };
};

class Vehicle{
public:
    uint16_t max_speed;
    string fuel;

    void start(void);
    void stop(void);
    void feed(void);
};

class Car : public Vehicle{
public:
    string make;
};

int main()
{
    Hello* hello = new Hello();
    hello->show_info();

    Car* car1 = new Car();
    car1->fuel = "Gasoline";
    car1->max_speed = 250;
    car1->make = "BWM";

    cout << "Make: " << car1->make << endl;
    cout << "Fuel: " << car1->fuel << endl;
    cout << "Max speed: " << car1->max_speed << endl;


    return 0;
}
