#include "Rx.h"
#include "Singleton.h"

int Rx::read(void){
	Singleton* rx = Singleton::get_instance();
	
	return rx->data.storage[0];
}