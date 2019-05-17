#include <iostream>

#include "MyClass.h"

using namespace std;

int main()
{
    myClass::MyClass ob;

    ob.setab(5);
    std::cout << "a = " << ob.geta() << std::endl;
    std::cout << "b = " << ob.b << std::endl;

    ob.b = 9;
    std::cout << "a = " << ob.geta() << std::endl;
    std::cout << "b = " << ob.b << std::endl;

    ob.reset();
    std::cout << "a = " << ob.geta() << std::endl;
    std::cout << "b = " << ob.b << std::endl;

    return 0;
}
