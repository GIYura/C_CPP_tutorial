/*Конструктор копирования*/
#include <stdio.h>
#include <iostream>
using namespace std;

class MyClass{
	int size;
public:
	int* data;
	MyClass(int size){
		this->size = size;
		this->data = new int [size];
		for(int i = 0; i < size; i++){
			data[i] = i;
		}
		//cout << "C: The constructor started: " << data << endl;
		cout << "C: The address of the object: " << this << endl;
	};
	
	~MyClass(){
		//cout << "The destructor started: " << data << endl;
		cout << "D: The address of the object: " << this << endl;
		delete[] data;
	};
	void show_info(){
		cout << "Data: " << data << endl;
	}
	
	MyClass(const MyClass &other){
		cout << "C_C: The address of the object: " << this << endl;
		
		this->size = other.size;
		this->data = new int [other.size];
		for(int i = 0; i < other.size; i++){
			this->data[i] = other.data[i];
		}
	}
};

void Foo(MyClass value){	
	cout << "The FOO" << endl;
}

MyClass Foo_1(){
	MyClass temp(33);
	cout << "The FOO_1" << endl;
	return temp;
}

int main(int argc, char **argv)
{
	MyClass m1(5);
	MyClass m2(m1);
//	cout << "Data 1: " << m1.data << endl;
//	cout << "Data 2: " << m2.data << endl;
//	Foo(m1);
//	Foo_1();
	return 0;
}
