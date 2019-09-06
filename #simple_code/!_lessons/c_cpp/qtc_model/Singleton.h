#ifndef __SINGLETON_H
#define __SINGLETON_H

class Singleton{
	
	typedef struct{
		int storage[100] = { 0 };
	}data_t;
	
	static Singleton* p_instance;
	Singleton();
public:
	data_t data;
	static Singleton* get_instance();
};

#endif //__SINGLETON_H