#include <iostream>

#include "Alg.h"
#include "Ble.h"

#include "Tx.h"
#include "Rx.h"

using namespace std;

class Gpo{
public:
    Gpo(){};
    virtual~Gpo(){};
    enum mode_t
    {
        kModeNone,        //pin mode undefined
        kModeInput,       //pin mode input
        kModeOutput,      //pin mode output
        kModeOd,          //pin mode open-drain
    };

    enum port_t
    {
        kPortA,           //*port 0
        kPortB,           //*port 1
    };

    enum pin_t
    {
        kPin0,
        kPin1,
        kPin2,
        kPin3,
        kPin4,
        kPin5,
        kPin6,
        kPin7,
        kPin8,
        kPin9
    };

};

class Heater{
    int h_relay;
    int h_triac;
    Gpo* m_gpo;
public:
    Heater(Gpo* gpo = nullptr) : m_gpo(gpo){

    }
    virtual ~Heater(){};

    void on(void){
        cout << "Heater ON" << endl;
    };
    void off(void){
        cout << "Heater OFF" << endl;
    };
    void show_info(){
        cout << "Heater connected: " << h_relay << ", " << h_triac << endl;
    }
};

class Pump{
    int p_relay;
    int p_triac;
public:
    Pump(int p_relay, int p_triac){
        this->p_relay = p_relay;
        this->p_triac = p_triac;
    }

    virtual ~Pump(){};

    void on(void){
        cout << "Pump ON" << endl;
    };
    void off(void){
        cout << "Pump OFF" << endl;
    };
    void show_info(){
        cout << "Pump connected: " << p_relay << ", " << p_triac << endl;
    }
};

class Valve{
    int v_pos;
    int v_neg;
public:
    Valve(int v_pos, int v_neg){
        this->v_pos = v_pos;
        this->v_neg = v_neg;
    }
    virtual ~Valve(){};

    void open(void){
        cout << "Valve OPEN" << endl;
    }

    void close(void){
        cout << "Valve CLOSE" << endl;
    }
    void show_info(void){
        cout << "Valve connected: " << v_pos << ", " << v_neg << endl;
    }
};

class Temperature{
    int temp;
public:
    int get_t(){
        return temp;
    }
    void update_temp(){
        temp++;
    }
};

class Accelerometer{
    int axis_x;
    int axis_y;
    int axis_z;
public:
    int get_x(){
        cout << "Axis X: " << axis_x << endl;
        return axis_x;
    }

    int get_y(){
        cout << "Axis Y: " << axis_y << endl;
        return axis_y;
    }

    int get_z(){
        cout << "Axis Z: " << axis_z << endl;
        return axis_z;
    }

    void update_x(){
        cout << "Change X: " << endl;
        axis_x++;
    }

    void update_y(){
        cout << "Change Y: " << endl;
        axis_y++;
    }

    void update_z(){
        cout << "Change Z: " << endl;
        axis_z++;
    }
};

class Control{
    Gpo gpo;
public:
 //   Heater heater(Gpo&);
    Pump pump;
    Valve fill_valve;
    Valve drain_valve;

    Control() : pump(3, 4),
                fill_valve(5, 6),
                drain_valve(7, 8)

    {};
    virtual ~Control(){};
};

class Measurement{

public:
    Temperature an_temp;
    Accelerometer acc;

    Measurement() : an_temp(),
                    acc()
    {};
    virtual ~Measurement(){};
};

class System_Info{
    int heater_state;
    int pump_state;
    typedef struct{
        int fill_valve_state         :  1;
        int fill_valve_feedback      :  1;
        int drain_valve_state        :  1;
        int drain_valve_feedback     :  1;
    }valve_t;
    valve_t valve;

public:
    friend class Command_Manager;
};

class Command_Manager{
    Control control;
    Measurement measurement;

    void get_temp(){
        measurement.an_temp.get_t();
    }
    void get_acc(){
        measurement.acc.get_x();
        measurement.acc.get_y();
        measurement.acc.get_z();
    }

    void set_heater(int state){
        switch(state){
            case 0:

                break;
            case 1:
                //control.heater.on();
                break;
        }
    }

    void set_pump(int state){
        switch(state){
            case 0:
                control.pump.off();
                break;
            case 1:
                control.pump.on();
                break;
        }
    }

    void set_fill_valve(int state){
        switch(state){
            case 0:
                control.fill_valve.close();
                break;
            case 1:
                control.fill_valve.open();
                break;
        }
    }

    void set_drain_valve(int state){
        switch(state){
            case 0:
                control.drain_valve.close();
                break;
            case 1:
                control.drain_valve.open();
                break;
        }
    }
public:

    System_Info sys_info;

    void exec_command(int cmd){
        switch(cmd){
            case 0:
                get_temp();
                break;
            case 1:
                get_acc();
                break;
            case 2:
                set_heater(1);
                sys_info.heater_state = 1;
                break;
            case 3:
                set_pump(1);
                break;
            case 4:
                set_fill_valve(1);
                sys_info.valve.fill_valve_state = 1;
                break;
            case 5:
                set_drain_valve(1);
                break;
        }
    };
};

class Esp{

public:
    Esp(){
        cout << "Esp init..." << endl;
    }

    void send(void){
        cout << "Esp send" << endl;
    };
    void receive(void){
        cout << "Esp receive" << endl;
    };
};

class Server{
    Esp* m_esp;
public:

    Server(Esp* esp) : m_esp(esp){

    }
    void send_req(void){
        m_esp->send();
    };
    void receive_req(void){
        m_esp->receive();
    };
};

class Twi{
public:
    Twi(){

    };

    virtual ~Twi(){};
    void send(){
        cout << "Twi send data" << endl;
    };
    void receive(){
        cout << "Twi receive data" << endl;
    };
};

class IC_1{
	Twi* m_twi;
public:
    IC_1(Twi* twi) : m_twi(twi){

    }
    void get_data(){
		m_twi->receive();
	}
};

class IC_2{
	Twi* m_twi;
public:
    IC_2(Twi* twi) : m_twi(twi){

    }
    void get_data(){
		m_twi->receive();
	}
};

class IC_3{
	Twi* m_twi;
public:
    IC_3(Twi* twi) : m_twi(twi){

    }
    void set_data(){
		m_twi->send();
	}
};

class ObjCreate{
public:
	static Esp* esp_1;
	static Twi* twi_1;
	ObjCreate(){
		
	}
};








int main()
{
	ObjCreate obj;

	
    Esp* esp = new Esp();
	Twi* twi = new Twi();
	
    Server* server = new Server(esp);
    server->send_req();
    server->receive_req();

    IC_1* ic1 = new IC_1(twi);
    ic1->get_data();
	
	IC_2* ic2 = new IC_2(twi);
    ic2->get_data();
	
	IC_3* ic3 = new IC_3(twi);
	ic3->set_data();
	
	typedef struct{
		int a;
		int b[10] = { 0 };
	}cmd_t;
	cmd_t* cmd;
	
	cout << sizeof(cmd) << endl;
	
	Alg alg;
	Ble ble(alg);
	
	ble.f();
/////////////////////////////////////////	
	cout << "====================="<< endl;
	Tx* sender = new Tx();
	Rx* receiver = new Rx();
	
	sender->show_info();
	receiver->show_info();
	
	sender->write(22);
	cout << "Data: "  << receiver->read() << endl;
	
    return 0;
}
