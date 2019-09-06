#ifndef __TIME_H
#define __TIME_H

#include <iostream>
using namespace std;

class Time{
public:
	Time();
	void set_time(int, int, int);
	void print_universal(void);
	void print_standard(void);
	
private:
	int second = 0;
	int minute;
	int hour;
};
#endif //__TIME_H