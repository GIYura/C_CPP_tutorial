#include "Singleton.h"

Singleton* Singleton::p_instance = nullptr;

Singleton* Singleton::get_instance(){
	if(p_instance == nullptr){
		p_instance = new Singleton();
	}
	return p_instance;
}

Singleton::Singleton(){
	
}