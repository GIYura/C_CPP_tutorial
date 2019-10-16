// exception_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Ring{
	int* pm;
public:
	Ring(int sz){
		pm = new int[sz];
	}
};

class MyException : public exception {

public:
	virtual const char* what() const throw(){
		return "Something bad happend";
	}
};

class Test {
public:
	void invoke() {
		throw MyException();
	}

};

int main()
{
	Test test;
	try
	{
		test.invoke();
	}
	catch (...)
	{
		cout << "Error: Some Exception" << endl;
	}
	
	return 0;
}