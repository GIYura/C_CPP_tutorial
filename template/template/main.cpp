///Template example

#include <iostream>

#define BUFF_SIZE          100

using namespace std;

template <class Buff_t> class RingBuffer{
    Buff_t buff[BUFF_SIZE];
    int head, tail;
public:
    RingBuffer() { head = 0; tail = 0; }
    void push(Buff_t);
    Buff_t pop();
};

///
template <class Buff_t> void RingBuffer<Buff_t>::push(Buff_t data){
    if(head == BUFF_SIZE){
        cout << "The ring is full\n" << endl;
        return;
    }
    head++;
    buff[head] = data;
}

///
template <class Buff_t> Buff_t RingBuffer<Buff_t>::pop(){
    if(head == tail){
        cout << "The ring is empty" << endl;
        return 0;
    }
    tail++;
    return buff[tail];
}


int main()
{
    RingBuffer<int> ringA;
    RingBuffer<char> ringB;
    RingBuffer<double> ringC;

    for(int i = 0; i < 5; i++){
        ringA.push(i);
    }

    for(int i = 0; i < 5; i++){
        cout << "Ring A: " << ringA.pop() << endl;
    }
        cout << "----------------------" << endl;
    for(int i = 0; i < 6; i++){
        ringB.push(i + 'A');
    }
    for(int i = 0; i < 6; i++){
        cout << "Ring B: " << ringB.pop() << endl;
    }
        cout << "----------------------" << endl;
    for(int i = 0; i < 7; i++){
        ringC.push(i + 3.14);
    }
    for(int i = 0; i < 7; i++){
        cout << "Ring C: " << ringC.pop() << endl;
    }





    return 0;
}
