// composition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://www.researchgate.net/post/What_is_a_difference_in_Is-a_and_has-a_relationship_of_inheritance_of_c
/*
IS-A relationship is inheretance;
HAS-A relationship doesn't related to inheretance
//
1. One class HAS another class (embedded class) 
2. One class contains a pointer to another class (strong containment)
3. One class contains a pointer to another class (weak containment)
4. One class contains a reference to another class (weak containment)
//
*/
#include <iostream>
using namespace std;

static int created = 0;
static int destroyed = 0;

//1. CASE
class Engine {
	string m_type;
	int m_power;
public:
	Engine(string type) : m_type(type){
		cout << " +++ Engine created" << endl;
		this->m_power = 1000;
		this->show();
		created++;
	}

	virtual ~Engine(){
		cout << " --- Engine destroyed" << endl;
		destroyed++;
	};

	void show(void) {
		cout << "The engine type is: " << this->m_type << endl;
		cout << "The engine power is: " << this->m_power << endl;
	}

	void on(void) {
		cout << "The engine STARTED" << endl;
	}

	void off(void) {
		cout << "The engine STOPPED" << endl;
	}
};

class Car {
	Engine m_engine;
	string m_make;
public:
	Car(string make, string engine_type) : m_make(make), m_engine(engine_type) {
		cout << " +++ The car is created" << endl;
		created++;
	}

	virtual ~Car(){
		cout << " --- The car is destroyed" << endl;
		destroyed++;
	}

	void show() {
		cout << "The car make is: " << this->m_make << endl;
	}

	void start_engine(void) {
		this->m_engine.on();
	}

	void stop_engine(void) {
		this->m_engine.off();
	}
};

//2. CASE
class CPU {
	string m_brand;
	int m_freq;
public:
	CPU(string brand, int freq) : m_brand(brand), m_freq(freq) {
		cout << " +++ The CPU is created" << endl;
		created++;
	}

	virtual ~CPU() {
		cout << " --- The CPU is destroyed" << endl;
		destroyed++;
	}
};

class Laptop {
	CPU* cpu;
	string m_brand;
public:
	Laptop(string brand) : m_brand(brand){
		cout << " +++ The laptop is created" << endl;
		this->cpu = new CPU("Intel", 3000);
		created++;
	}

	virtual ~Laptop() {
		cout << " --- The laptop is destroyed" << endl;
		delete cpu;
		destroyed++;
	};
};

//3. CASE
class Employee {
	string m_name;
	int m_age;
public:
	Employee(string name, int age) : m_name(name), m_age(age) {
		cout << " +++ The employee is created" << endl;
		created++;
	}

	virtual ~Employee() {
		cout << " --- The employee is destroyed" << endl;
		destroyed++;
	}
};

class Company {
	Employee* m_employee_1;
	Employee* m_employee_2;
	Employee* m_employee_3;
	Employee* m_employee_4;
public:
	Company(Employee* e1, Employee* e2, Employee* e3, Employee* e4) :	m_employee_1(e1), 
																		m_employee_2(e2),
																		m_employee_3(e3),
																		m_employee_4(e4)
	{
		cout << " +++ The company is created" << endl;
		created++;
	}
	virtual ~Company() {
		cout << " --- The comapany is destroyed" << endl;
		destroyed++;
	}
};

//4. CASE
class Author {
	string m_name;
public:
	Author(string name) : m_name(name){
		cout << " +++ The Author created" << endl;
		this->show();
		created++;
	}
	virtual ~Author() {
		cout << " --- The author destroyed" << endl;
		destroyed++;
	}

	void show(void) {
		cout << "Author name is: " << this->m_name << endl;
	}
};

class Book {
	Author& m_author;
	string m_title;
public:
	Book(Author& author, string title) : m_author(author), m_title(title) {
		cout << " +++ The Book created" << endl;
		created++;
	}

	virtual ~Book() {
		cout << " --- The Book destroyed" << endl;
		destroyed++;
	}

	void show(void) {
		cout << "The book title is: " << this->m_title << endl;
	}
};

//
//
//
//MAIN
int main()
{
	cout << "HAS_A: STRONG CONTAINMENT (embedded)" << endl;
	Car* car = new Car("BMW", "DIESEL");
	car->show();
	car->start_engine();
	car->stop_engine();
	cout << "------------------" << endl;

	cout << "HAS_A: STRONG CONTAINMENT" << endl;
	Laptop laptop("Huawei");

	cout << "------------------" << endl;
	cout << "HAS_A: WEAK CONTAINMENT" << endl;
	Employee* e1 = new Employee("Steven", 23);
	Employee* e2 = new Employee("Peter", 45);
	Employee* e3 = new Employee("Bob", 33);
	Employee* e4 = new Employee("Monica", 34);
	Company company(e1, e2, e3, e4);
	cout << "------------------" << endl;
	cout << "HAS_A: WEAK CONTAINMENT" << endl;

	Author author("Stroustrup");
	Book book(author, "C++");
//
	delete car;
	delete e1;
	delete e2;
	delete e3;
	delete e4;
	cout << "------------------" << endl << endl;

	cout << "Created objects number\t: " << created << endl;
	cout << "Destroyed objects number\t: " << destroyed << endl;

	return 0;
}