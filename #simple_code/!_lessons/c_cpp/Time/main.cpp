#include <stdio.h>
#include <iostream>
using namespace std;

#include "Time.h"

class Extender{
	int m_data1;
	int m_data2;
	int m_data3;
	int m_data4;
	
	int m_data5;
	
public:
	Extender(){};
	~Extender(){};
	friend class Motor;
	void write_reg(int){
	
	};
	int read_reg(void){
		return 0;
	};
	void show_data(){
		printf("data 1 : %#x\n", this->m_data1);
		printf("data 2 : %#x\n", this->m_data2);
		printf("data 3 : %#x\n", this->m_data3);
		printf("data 4 : %#x\n", this->m_data4);
		printf("data 5 : %#x\n", this->m_data5);
	};
};

class Motor{
	int m_id;
public:
	static int count;
	Motor(){
		count++;
		m_id = count;
	};
	
	void cw(Extender* ex) {
		cout << "Motor is turning CLOCKWISE" << endl;
		if(m_id == 1){
			ex->m_data5 |= 0x000000aa;
		}
		if(m_id == 2){
			ex->m_data5 |= 0x0000aa00;
		}
		if(m_id == 3){
			ex->m_data5 |= 0x00aa0000;
		}
		if(m_id == 4){
			ex->m_data5 |= 0xaa000000;
		}
	};
	void ccw(void){
		cout << "Motor is turning COUNTERCLOCKWISE" << endl;
	};
	void stop(void){
		cout << "Motor is STOPED" << endl;
	};
	
	int get_id(){
		return m_id;
	};
};

int Motor::count = 0;

int main(int argc, char **argv)
{
	Extender* ex1 = new Extender();
	Motor* m1 = new Motor();
	Motor* m2 = new Motor();
	Motor* m3 = new Motor();
	Motor* m4 = new Motor();
	m1->cw(ex1);
	m2->cw(ex1);
	m3->cw(ex1);
	m4->cw(ex1);
	ex1->show_data();
	
	//cout << "ID:" << m1->get_id() << endl;
	//cout << "ID:" << m2->get_id() << endl;
	//cout << "ID:" << m3->get_id() << endl;
	//cout << "ID:" << m4->get_id() << endl;
	
	return 0;
}
