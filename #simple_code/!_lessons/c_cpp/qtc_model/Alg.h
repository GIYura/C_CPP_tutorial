#ifndef __ALG
#define __ALG
#include "Types.h"
	
class Alg{
	cmd_t cmd;
public:
	Alg(){};
	void foo(void){
		std::cout << "Foo is working" << std::endl;
		std::cout << "Size of cmd: " << sizeof(cmd) << std::endl;
	};
};
#endif