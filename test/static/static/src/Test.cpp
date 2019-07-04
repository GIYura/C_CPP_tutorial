#include "Test.h"
#include <iostream>
using namespace std;

int Test::x = 10;

Test::Test()
{
    //ctor
}

Test::~Test()
{
    //dtor
}

void Test::prinfInfo(void){
    cout << Test::x << endl;
}
