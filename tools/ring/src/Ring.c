#include "Ring.h"

#define RING_NEXT_HEAD(ring)    ((ring->head + 1) % ring->size)
#define RING_NEXT_TAIL(ring)    ((ring->tail + 1) % ring->size)
#define RING_IS_FULL(ring)      (RING_NEXT_HEAD(ring) == ring->tail)
#define RING_IS_EMPTY(ring)     (ring->head == ring->tail)

//
ring_status_t ring_init(ring_t* ring, uint16_t sz){
    assert(ring && sz);
    ring->head = 0;
    ring->tail = 0;
    ring->size = sz;
    return RING_OK;
}

//
ring_status_t ring_clear(ring_t* ring){
    assert(ring);
    ring->head = 0;
    ring->tail = 0;
	memset(ring->buffer, 0, RING_SIZE);
	return RING_OK;
}

//
ring_status_t ring_push(ring_t* ring, uint8_t* data){
    assert(ring);
    ring->buffer[ring->head] = *data;
    if(RING_IS_FULL(ring)){
        ring->tail = RING_NEXT_TAIL(ring);
    }
    ring->head = RING_NEXT_HEAD(ring);
    return RING_OK;
}

//
ring_status_t ring_pop(ring_t* ring, uint8_t* data){
    assert(ring);
    if(RING_IS_EMPTY(ring)){
		return RING_ERROR;
    }
    *data = ring->buffer[ring->tail];
    ring->tail = RING_NEXT_TAIL(ring);        
    return RING_OK;
}