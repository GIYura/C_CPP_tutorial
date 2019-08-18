#include <iostream>

using namespace std;

class Person{
private:
    typedef struct{
        int age;
        char* name;
    }person_info_t;

    Person();
    static Person* instance;
public:
    person_info_t person_info;
    static Person* get_instance();
};

Person* Person::instance = 0;

Person* Person::get_instance(){
    if(instance == 0){
        instance = new Person();
    }
    return instance;
}

Person::Person(){

}

int main()
{
    Person* p1 = Person::get_instance();
    Person* p2 = Person::get_instance();
    Person* p3 = Person::get_instance();

    p1->person_info.age = 99;
    p1->person_info.name = "Hummels";

    p2->person_info.age = 222;
    p2->person_info.name = "Mark";

    p3->person_info.age = 88;
    p3->person_info.name = "Ben";

    cout << "Person name: " << p1->person_info.name << endl;
    cout << "Person age: " << p1->person_info.age << endl;
    cout << "---------------------" << endl;

    cout << "Person name: " << p2->person_info.name << endl;
    cout << "Person age: " << p2->person_info.age << endl;
    cout << "---------------------" << endl;

    cout << "Person name: " << p3->person_info.name << endl;
    cout << "Person age: " << p3->person_info.age << endl;
    cout << "---------------------" << endl;



    return 0;
}
