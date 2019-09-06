#include <stdio.h>
#include <iostream>
using namespace std;

class Interface{
	int port_a;
	int port_b;
	int pin_a;
	int pin_b;
	void send_data(int* data, int len);
	void receive_data(int* data, int len);

public:
	Interface(/*int porta, int pina, int portb, int pinb*/){
		//this->port_a = port_a;
		//this->pin_a = pin_a;
		//this->port_b = port_b;
		//this->pin_b = pin_b;
	};


	friend class IC_1;
	friend class IC_2;
};

class IC_1{
	int a;
	int b;
	int c;
	int d;
public:
	Interface comm;
	void send(void){
		comm.send_data(&a, b);
	};
	void receive(){
		comm.receive_data(&c, d);
	};
};

class IC_2{
	int a;
	int b;
public:
	Interface comm;
	void send(void){
		comm.send_data(&a, b);
	};
};

//
int main(int argc, char **argv)
{
	IC_1 ic1;

	return 0;
}
