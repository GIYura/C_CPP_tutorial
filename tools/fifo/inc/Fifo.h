#ifndef __FIFO_H
#define __FIFO_H

#include "Porting.h"

#define FIFO_SIZE 0

typedef struct {
    uint8_t buffer[FIFO_SIZE];
    uint16_t head;
    uint16_t tail;
    uint16_t size;
}fifo_t;

typedef enum{
    FIFO_OK 	= 0,
    FIFO_ERROR 	= 1
}fifo_status_t;

fifo_status_t fifo_init(fifo_t* fifo, uint16_t sz);
fifo_status_t fifo_clear(fifo_t* fifo);
fifo_status_t fifo_push(fifo_t* fifo, uint8_t data);
fifo_status_t fifo_pop(fifo_t* fifo, uint8_t* data);

#endif//__FIFO_H