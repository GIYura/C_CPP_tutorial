///RING BUFFER

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#define BUFFER_SIZE     16

#define RING_NEXT_HEAD(ring)    ((ring->head + 1) % ring->size)
#define RING_NEXT_TAIL(ring)    ((ring->tail + 1) % ring->size)
#define RING_IS_FULL(ring)      (RING_NEXT_HEAD(ring) == ring->tail)
#define RING_IS_EMPTY(ring)     (ring->head == ring->tail)

typedef struct {
    uint8_t* buffer;
    uint16_t head;
    uint16_t tail;
    uint16_t size;
} ring_buffer_t;

ring_buffer_t* ringInit(uint8_t*, uint16_t);
void ringFree(ring_buffer_t*);
void ringReset(ring_buffer_t*);
bool ringIsEmpty(ring_buffer_t*);
bool ringIsFull(ring_buffer_t*);
uint16_t ringSize(ring_buffer_t*);
void ringStatus(ring_buffer_t*);
void ringPush(ring_buffer_t* , uint8_t);
int ringPop(ring_buffer_t*, uint8_t*);

int main()
{
    uint8_t* buffer = malloc(BUFFER_SIZE * sizeof(uint8_t));
    ring_buffer_t* ring = ringInit(buffer, BUFFER_SIZE);
    ringStatus(ring);

    for(uint8_t i = 0; i < BUFFER_SIZE; i++){
        ringPush(ring, i);
        printf("Size is: %d\n", ringSize(ring));
    }
    ringStatus(ring);


    return 0;
}

///
ring_buffer_t* ringInit(uint8_t* br, uint16_t sz){
    assert(br && sz);
    ring_buffer_t* rb = malloc(sizeof(ring_buffer_t));
    rb->buffer = br;
    rb->head = 0;
    rb->tail = 0;
    rb->size = sz;
    return rb;
}

///
void ringFree(ring_buffer_t* rb){
    assert(rb);
    free(rb);
}

///
void ringReset(ring_buffer_t* rb){
    assert(rb);
    rb->head = 0;
    rb->tail = 0;
}

///
bool ringIsEmpty(ring_buffer_t* rb){
    assert(rb);
    return RING_IS_EMPTY(rb);
}

///
bool ringIsFull(ring_buffer_t* rb){
    assert(rb);
    return RING_IS_FULL(rb);
}

///
uint16_t ringSize(ring_buffer_t* rb){
    assert(rb);
    uint16_t size = rb->size;

    if(!RING_IS_FULL(rb)){
        if(rb->head >= rb->tail){
            size = rb->head - rb->tail;
        } else {
            size = (rb->size + rb->head) - rb->tail;
        }
    }
    printf("size: %d ", size);
    return size;
}

///
void ringStatus(ring_buffer_t* rb){
    printf("Full %d; Empty %d; Size %d\n", ringIsFull(rb), ringIsEmpty(rb), ringSize(rb));
}

///
void ringPush(ring_buffer_t* rb, uint8_t data){
    assert(rb);
    printf("data: %d ", data);
    rb->buffer[rb->head] = data;
    if(RING_IS_FULL(rb)){
        rb->tail = RING_NEXT_TAIL(rb);
    }
    rb->head = RING_NEXT_HEAD(rb);
    printf("head: %d  ", rb->head);
    printf("tail: %d  ", rb->tail);
}

///
int ringPop(ring_buffer_t* rb, uint8_t* data){
    assert(rb);
    int res = -1;
    if(!RING_IS_EMPTY(rb)){
        *data = rb->buffer[rb->tail];
        RING_NEXT_TAIL(rb);
        res = 0;
    }
    return res;
}
