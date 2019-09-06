#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Image{
public:
	
private:
	class Pixel{
	public:
		Pixel(int r, int g, int b){
			this->r = r;
			this->g = g;
			this->b = b;
		}
		
		string get_info(){
			return "Pixel: r = " + to_string(r) + "g" + to_string(g) + "b" + to_string(b);
		}
	private:
		int r;
		int g;
		int b;
	};
};

class Sensor{
	int m_id;
public:
	Sensor(int id) : m_id(id){};
	void show_if(){
		cout << "ID: " << m_id << endl;
	};
};

class Bus{
public:
	Sensor m_s1;
	Sensor m_s2;
	Bus(int id1, int id2) : m_s1(id1), m_s2(id2){};
};

class Eq{
	Bus* m_bus;
public:
	Eq(Bus* bus) : m_bus(bus){};
};

class Task{
	Eq* m_eq;
public:
	Task(Eq* e) : m_eq(e){};
};

#define MOTOR_CW 	0x01
#define MOTOR_CCW 	0x02
#define MOTOR_STOP 	0x03

int convert(char byte);

typedef struct{
	uint8_t alert_1 : 1;
	uint8_t alert_2 : 1;
	uint8_t	    : 6;
} motor_alert_t;

typedef struct{            
	motor_alert_t motor_1;
	motor_alert_t motor_2;
	motor_alert_t motor_3;
	motor_alert_t motor_4;
	motor_alert_t motor_5;
	motor_alert_t motor_6;   
}alert_t;
alert_t m_alert;

void set_alert(int alert);

int main(int argc, char **argv)
{
//	Bus b1(1,2);
//	Eq q1(&b1);
//	Task t1(&q1);
	char cmd = 0x00;
	int res = convert(cmd);
	cout << res << endl;
	
	char alert_1 = 0xaa;
	char alert_2 = 0xaa;
	
	int al = 0x00;
	al |= alert_1;
	al = al << 8;
	al |= alert_2;
	
	set_alert(al);
	
	return 0;
}


int convert(char byte){
	int res;
	
	for(int i = 0; i < 6; i++){
		if(byte & (1 << i)){
			res |= MOTOR_CW;
		}
	}
	
	return 0;
}

void set_alert(int alert){
	memcpy((void*)&m_alert, (void*)&alert, sizeof(alert));
}