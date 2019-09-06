#ifndef __BLE
#define __BLE
#include "Types.h"
#include "Alg.h"

class Ble{
	cmd_t cmd;
	Alg* m_alg;
public:
	
	Ble(Alg& alg) : m_alg(&alg){};
	void f(void){
		m_alg->foo();
	};
};

#endif