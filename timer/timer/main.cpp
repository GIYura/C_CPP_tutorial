#include <iostream>

using namespace std;

//
typedef enum{
   TIMER_0,
   TIMER_1,
   TIMER_2,
   TIMER_NUMBER
}timer_idx_t;

//
typedef enum{
    ACTIVE,
    DISACTIVE,
    EXPIRED,
    UNEXPIRED,
    INVALID
}timer_state_t;

class SwTimer{
      timer_state_t state;
      uint32_t ticks;
public:
    SwTimer(uint32_t);
    ~SwTimer(void);


    timer_state_t setState(timer_state_t);
    timer_state_t getState(void);
    uint32_t getTicks(void);

    timer_state_t swTimerIsTimeOut(void);
    void swTimerProcess(void);
};

//
timer_state_t SwTimer::setState(timer_state_t newState){
    if(newState == ACTIVE || newState == DISACTIVE){
        this->state = newState;
        return this->state;
    }
    return INVALID;
}

//
timer_state_t SwTimer::getState(void){
     return this->state;
}

//
uint32_t SwTimer::getTicks(void){
    return this->ticks;
}

//
SwTimer::SwTimer(uint32_t t){
    this->state = ACTIVE;
    this->ticks = t;
}

//
SwTimer::~SwTimer(void){
    this->state = DISACTIVE;
    this->ticks = 0;
}

timer_state_t swTimerIsTimeOut(void){
    if(getState() == ACTIVE){
        return getTicks() ? UNEXPIRED : EXPIRED;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
