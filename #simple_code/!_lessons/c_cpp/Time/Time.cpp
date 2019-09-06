#include "Time.h"

#include <iomanip>
using std::setfill;
using std::setw;

Time::Time(){
	this->second = 0;
	this->minute = 0;
	this->hour = 0;
}

void Time::set_time(int s, int m, int h){
	this->hour = (h >= 0 && h < 24) ? h : 0;
	this->minute = (m >= 0 && m < 24) ? m : 0;
	this->second = (s >= 0 && s < 24) ? s : 0;
}

void Time::print_universal(void){
	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
}