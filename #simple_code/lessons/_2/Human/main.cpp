#include <iostream>

using namespace std;

class Human{
    string breed;
    string name;
    int age;

public:
    void set_breed(string breed){
        this->breed = breed;
    };

    void set_name(string name){
        this->name = name;
    };

    void set_age(int age){
        this->age = age;
    };

    string get_breed(void){return this->breed;};
    string get_name(void){return this->name;};
    int get_age(){return this->age;};
};

class Point{
    int x;
    int y;
    int z;

public:
    void set_x(int x){this->x = x; };
    void set_y(int y){this->y = y;};
    void set_z(int z){this->z = z;};
};

int main()
{
    Human person1;
    Human person2;

    person1.set_age(29);
    person1.set_breed("Male");
    person1.set_name("Bob");

    cout << "Breed: " << person1.get_breed() << endl;
    cout << "Name: " << person1.get_name() << endl;
    cout << "Age: " << person1.get_age() << endl;
    cout << "---------------------------" << endl;

    person2.set_age(55);
    person2.set_breed("Female");
    person2.set_name("Suzy");

    cout << "Breed: " << person2.get_breed() << endl;
    cout << "Name: " << person2.get_name() << endl;
    cout << "Age: " << person2.get_age() << endl;


    return 0;
}
