#include "Fifo.h"

#define FIFO_NEXT_HEAD(fifo)    ((fifo->head + 1) % fifo->size)
#define FIFO_NEXT_TAIL(fifo)    ((fifo->tail + 1) % fifo->size)
#define FIFO_IS_FULL(fifo)      (FIFO_NEXT_HEAD(fifo) == fifo->tail)
#define FIFO_IS_EMPTY(fifo)     (fifo->head == fifo->tail)

//
fifo_status_t fifo_init(fifo_t* fifo, uint16_t sz){
    assert(fifo && sz);
	fifo->buffer = (uint8_t*)malloc(sz * sizeof(uint8_t));
	assert(fifo->buffer);
    fifo->head = 0;
    fifo->tail = 0;
    fifo->size = sz;
    return FIFO_OK;
}

//
fifo_status_t fifo_clear(fifo_t* fifo){
    assert(fifo);
    fifo->head = 0;
    fifo->tail = 0;
    memset(fifo->buffer, 0, fifo->size);
    return FIFO_OK;
}

//
fifo_status_t fifo_push(fifo_t* fifo, uint8_t data){
    assert(fifo);
    if(FIFO_IS_FULL(fifo)){
        return FIFO_ERROR;
    }
    fifo->buffer[fifo->head] = data;
    fifo->head = FIFO_NEXT_HEAD(fifo);
    return FIFO_OK;
}

//
fifo_status_t fifo_pop(fifo_t* fifo, uint8_t* data){
    assert(fifo);
    if(FIFO_IS_EMPTY(fifo)){
		return FIFO_ERROR;
    }
    *data = fifo->buffer[fifo->tail];
    fifo->tail = FIFO_NEXT_TAIL(fifo);
    return FIFO_OK;
}