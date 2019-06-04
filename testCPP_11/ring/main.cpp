#include <iostream>

#define RING_IS_VALID(this)                          \
                        ( ( this->sz > 0 &&          \
                            this->data != NULL) )


#define RING_NEXT_HEAD(this) ((this->head + 1) % this->sz)
#define RING_NEXT_TAIL(this) ((this->tail + 1) % this->sz)
#define RING_IS_FULL(this)   (RING_NEXT_HEAD(this) == this->tail)
#define RING_IS_EMPTY(this)  (this->head == this->tail)

using namespace std;

class RingBuffer{


    typedef enum{
        RING_OK,
        RING_ERROR
    }ring_status_t;

    uint16_t tail;
    uint16_t head;
    uint16_t sz;
    uint8_t* data;

public:
    typedef enum{
        LOW         = 16,//256,
        MEDIUM      = 32,//512,
        HIGH        = 64//1024
    }ring_sz_t;

    RingBuffer(ring_sz_t);
    ~RingBuffer();

    ring_status_t init(ring_sz_t);
    ring_status_t clear();
    ring_status_t push(uint8_t);
    ring_status_t pop(uint8_t*);
    ring_status_t print();
    uint8_t getData(uint8_t);
};
//
RingBuffer::ring_status_t RingBuffer::init(ring_sz_t s){
    ring_status_t status = RING_ERROR;
    if(s < LOW || s > HIGH){
        return status;
    }
    head = 0;
    tail = 0;
    sz = s;
    data = (uint8_t*)malloc(s * sizeof(uint8_t));
    if(data != NULL){
        status = RING_OK;
    }
    return status;
}
//
RingBuffer::ring_status_t RingBuffer::clear(){
    head = 0;
    tail = 0;
    if(data != NULL){
        free(data);
        return RING_OK;
    }
    return RING_ERROR;
}
//
RingBuffer::ring_status_t RingBuffer::push(uint8_t d){
    if(!RING_IS_VALID(this)){
        return RING_ERROR;
    }
    data[head] = d;
    if(RING_IS_FULL(this)){
        RING_NEXT_TAIL(this);
    }
    RING_NEXT_HEAD(this);
}
//
RingBuffer::ring_status_t RingBuffer::pop(uint8_t* d){
    if(!RING_IS_VALID(this)){
        return RING_ERROR;
    }
    *d = data[tail];
    RING_NEXT_TAIL(this);
}
//
RingBuffer::RingBuffer(ring_sz_t s){
    init(s);
}

RingBuffer::~RingBuffer(){

}

uint8_t RingBuffer::getData(uint8_t idx){
    return data[idx];
}


static RingBuffer *ring = new RingBuffer(RingBuffer::LOW);

int main()
{
    ring->data[0] = 100;
    uint8_t out;

    printf("init buffer:\n");
    for(uint16_t i = 0; i < RingBuffer::LOW; i++){
        ring->push(i);
        printf("%d ", ring->getData(i));
    }
    printf("\n");

    for(uint16_t i = 0; i < RingBuffer::LOW; i++){
        //printf("%d ", ring->getData(i));
    }




    return 0;
}
