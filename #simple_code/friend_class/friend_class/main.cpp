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
	friend class IC_1;
	friend class IC_2;
public:
	Interface(int porta, int pina, int portb, int pinb){
		this->port_a = port_a;
		this->pin_a = pin_a;
		this->port_b = port_b;
		this->pin_b = pin_b;
	};
	
	
};

class IC_1{
	int a;
	int b;
	int c;
	int d;
public:
	Interface* comm;
	void send(void){
		comm->send_data(&a, b);
	};
	void receive(void){
		comm->receive_data(&c, d);
	};
};

class IC_2{
	int x;
	int y;
	int z;
	int t;
public:
	Interface* comm;
	void send(void){
		comm->send_data(&x, y);
	};
	void receive(void){
		comm->receive_data(&z, t);
	};
};

class IC_3{
	int l;
	int m;
public:

	IC_3(Interface& i){};
};

//
int main(int argc, char **argv)
{
	IC_1 ic1;
	ic1.send();
	ic1.receive();
	
	IC_2 ic2;
	ic2.send();
	ic2.receive();
	
	Interface i(1,2,3,4);
	IC_3 ic3(i);

	return 0;
}
