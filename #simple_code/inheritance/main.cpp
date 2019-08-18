#include <iostream>

using namespace std;

class Person{
    int age;
    std::string name;

public:
    void set_name(std::string name);
    void set_age(int age);

    int get_age();
    std::string get_name();

};

void Person::set_age(int age){
    this->age = age;
}

void Person::set_name(std::string name){
    this->name = name;
}

int Person::get_age(){
    return this->age;
}

std::string Person::get_name(){
    return this->name;
}

class Emplyee : public Person{
    std::string company;
public:
    void set_company(std::string company);
    std::string get_company();
};

void Emplyee::set_company(std::string company){
    this->company = company;
}

std::string Emplyee::get_company(){
    return this->company;
}

class Fruit{
    std::string color = "Green";

public:
    void show_color();

protected:
    int size = 20;
};

void Fruit::show_color(){
    cout << "The color of the fruit: " << this->color << endl;
}

class Orange : Fruit{

public:
    int foo(){return size;};
};

int main()
{
    Emplyee* e1 = new Emplyee();

    e1->set_age(55);
    e1->set_name("Bob");
    e1->set_company("Apple");

    cout << "Age: " << e1->get_age() << endl;
    cout << "Name: " << e1->get_name() << endl;
    cout << "Company: " << e1->get_company() << endl << endl;

    Fruit* apple = new Fruit();
    apple->show_color();

    Orange* o1 = new Orange();
    cout << o1->foo() << endl;

    return 0;
}
