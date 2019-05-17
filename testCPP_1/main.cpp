#include <iostream>
#include "Person.h"

#include "Emploee.h"

using namespace std;

int main()
{
    Person per1("Ivanov", 33);
    cout << "Age is = " << per1.getAge() << endl;
    cout << "Name is = " << per1.getName() << endl;

    Emploee emp("Petrov", 44);

    return 0;
}
