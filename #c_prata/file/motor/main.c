#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include <string.h>

typedef enum{
    FAULT = 0,
    UP,
    DOWN,
    MIDDLE
}motor_state_t;

typedef union{
    struct{
        uint16_t m1 : 2;
        uint16_t m2 : 2;
        uint16_t m3 : 2;
        uint16_t m4 : 2;
        uint16_t m5 : 2;
        uint16_t m6 : 2;
        uint16_t    : 4;
    }bf;
    uint16_t motor_state;
}motor_control_t;

motor_control_t motor_control;

int main()
{
    printf("Hello world!\n");
    motor_control.bf.m1 = UP;


    uint16_t motor_state = 0;

    memset(&motor_control.motor_state, motor_state, sizeof(motor_control));

    return 0;
}
