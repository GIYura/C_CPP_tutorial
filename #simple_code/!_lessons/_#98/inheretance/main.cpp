//INHERETANCE
#include <iostream>

using namespace std;

class Human{

public:
    string name;
};

class Student : public Human{
public:
    string group;

    void learn(void){
        cout << "I'm learning" << endl;
    };
};

class Professor : public Human{
public:
    string subject;
};

class Extrastudent : public Student{
public:
    void learn(void){
        cout << "I'm extra" << endl;
    };
};

int main()
{
    Professor p1;

    p1.name = "Petrov";

    Student s1;
    s1.name = "Ivanov";
    s1.group = "PP";
    s1.learn();

    cout << "Professor: " << p1.name << endl;
    cout << "Student: " << s1.name << endl;


    Extrastudent st2;
    st2.learn();
    return 0;
}
