#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Buffer::Queue a, b;
    a.init();
    b.init();

    a.putQueue(1);
    a.putQueue(3);

    b.putQueue(2);
    b.putQueue(4);

    std::cout << "Queue A contains: " << std::endl;
    std::cout << a.getQueue() << std::endl;
    std::cout << a.getQueue() << std::endl;

    std::cout << "Queue B contains: " << std::endl;
    std::cout << b.getQueue() << std::endl;
    std::cout << b.getQueue() << std::endl;

    return 0;
}
