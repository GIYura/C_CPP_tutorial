#ifndef __RX_H
#define __RX_H

#include <iostream>

class Rx{
	
public:
	Rx(){};
	
	int read(void);
	
	void show_info(){
		std::cout << "Rx this: " << this << std::endl;
	};
};

#endif //__RX_H