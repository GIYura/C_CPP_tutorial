#include <iostream>

#include "Queue.h"

using namespace std;
void printInfo(void);

int main()
{
    printInfo();

    while(1);

    return 0;
}

void printInfo(void){
    Buffer::Queue a, b;
    a.putQueue(10);
    a.putQueue(20);
    b.putQueue(30);
    b.putQueue(40);

    std::cout << "Queue A contains: " << a.getQueue() << std::endl;
    std::cout << "Queue A contains: " << a.getQueue() << std::endl;
    std::cout << "Queue B contains: " << b.getQueue() << std::endl;
    std::cout << "Queue B contains: " << b.getQueue() << std::endl;
}
