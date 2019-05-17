#include "Queue.h"

#include <iostream>

Buffer::Queue::Queue(){

}

Buffer::Queue::~Queue(){

}

void Buffer::Queue::init(){
    head = 0;
    tail = 0;
}

void Buffer::Queue::putQueue(int value){
    if(head == 100){
        std::cout << "Queue is full" << std::endl;
        return;
    }
    head++;
    q[head] = value;
}

int Buffer::Queue::getQueue(){
    if(tail == head){
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }
    tail++;
    return q[tail];
}


