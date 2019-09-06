#include "Tx.h"
#include "Singleton.h"

void Tx::write(int data){
	Singleton* tx = Singleton::get_instance();
	
	tx->data.storage[0] = data;
}