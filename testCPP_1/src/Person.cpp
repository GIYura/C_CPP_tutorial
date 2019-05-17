#include "Person.h"

Person::Person(string n, int a)
{
    age = a;
    name = n;
}

Person::~Person()
{
    //dtor
}

int Person::getAge(){
    return this->age;
}

string Person::getName(){
    return this->name;
}
