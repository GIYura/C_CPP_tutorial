#ifndef __TX_H
#define __TX_H

#include <iostream>

class Tx{
	
public:
	Tx(){};
	
	void write(int data);
	
	void show_info(){
		std::cout << "Tx this: " << this << std::endl;
	};
};

#endif //__TX_H