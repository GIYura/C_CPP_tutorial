#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
    public:
        Person(string, int);
        virtual ~Person();

        string getName();
        int getAge();

    protected:

    private:
        string name;
        int age;
};

#endif // PERSON_H
