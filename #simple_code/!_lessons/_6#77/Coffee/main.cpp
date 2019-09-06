#include <iostream>
#include <cstring>

using namespace std;

class CoffeeGrinder{
    bool checkVoltage(){
        return false;
    }

public:
    void start(){
        if(checkVoltage()){
            cout << "Start" << endl;
        } else {
            cout << "Beep Beep" << endl;
        }
    }
};

#pragma pack(push, 1)
typedef struct{
	    uint8_t alert_1 : 1;
	    uint8_t alert_2 : 1;
	    uint8_t	    : 6;
	} motor_alert_t;


        typedef struct{
	    uint16_t motor_1_a1 : 1;
	    uint16_t motor_1_a2 : 1;

	    uint16_t motor_2_a1 : 1;
	    uint16_t motor_2_a2 : 1;

	    uint16_t motor_3_a1 : 1;
	    uint16_t motor_3_a2 : 1;

	    uint16_t motor_4_a1 : 1;
	    uint16_t motor_4_a2 : 1;

	    uint16_t motor_5_a1 : 1;
	    uint16_t motor_5_a2 : 1;

	    uint16_t motor_6_a1 : 1;
	    uint16_t motor_6_a2 : 1;


        }alert_t;
        alert_t m_alert;

        motor_alert_t m_alert_1[6];
#pragma pack(pop)

        void foo(uint16_t);
int main()
{
    uint8_t al_1 = 0xff;
    uint8_t al_2 = 0xff;
    uint16_t al = 0x00;

    al = al_1;
    al = al << 8;
    al |= al_2;

    printf("%#x\n", al);

    foo(al);

    return 0;
}

void foo(uint16_t alert){
//    for(uint8_t i = 0; i < 6; i++){
//        for(uint8_t j = 0; j < 2; j++){

//        }
//    }

    memcpy((void*)&m_alert, (void*)&alert, sizeof(alert));
}
