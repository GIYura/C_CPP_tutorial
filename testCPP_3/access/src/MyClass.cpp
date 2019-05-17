#include "MyClass.h"

#include <iostream>

myClass::MyClass::MyClass(){

}

myClass::MyClass::~MyClass(){

}

void myClass::MyClass::setab(int value){
    a = value;
    b = value * value;
}

int myClass::MyClass::geta(){
    return a;
}

void myClass::MyClass::reset(){
    setab(0);
}
