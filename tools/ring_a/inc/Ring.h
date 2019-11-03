#ifndef __RING_H
#define __RING_H

#include "Porting.h"

typedef struct {
    uint8_t* buffer;
    uint16_t head;
    uint16_t tail;
    uint16_t size;
}ring_t;

typedef enum{
    RING_OK		= 0,
    RING_ERROR 	= 1
}ring_status_t;

ring_status_t ring_init(ring_t* ring, uint16_t sz);
ring_status_t ring_clear(ring_t* ring);
ring_status_t ring_push(ring_t* ring, uint8_t* data);
ring_status_t ring_pop(ring_t* ring, uint8_t* data);

#endif //__RING_H