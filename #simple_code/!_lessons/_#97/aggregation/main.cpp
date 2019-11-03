//AGGREGATION AND COMPOSITION

#include <iostream>

using namespace std;

class Hat{
    string color = "RED";

public:
    string get_color(){
        return this->color;
    };
};

class Brain{

public:
    void think(){
        cout << "The Brain is thinking..." << endl;
    };
    Brain(){};
};

class Human{
    Brain brain;
    Hat hat;
public:
    void think(){
        brain.think();
    };

    void show_cap(void){
        cout << "The hat is: " << this->hat.get_color() << endl;
    };
};

class Model{

    Hat hat;
public:
    void show_cap(void){
        cout << "The hat is: " << this->hat.get_color() << endl;
    };
};



int main()
{
    Human h1;
    h1.think();
    h1.show_cap();

    Model m1;
    m1.show_cap();
    return 0;
}
