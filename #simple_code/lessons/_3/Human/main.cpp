#include <iostream>

using namespace std;

class Human{
public:

    int age;
    int weight;
    string name;

    void show_info(){
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Weight: " << this->weight << endl;
    };
};

int main()
{
    setlocale(LC_ALL, "ru");
    Human h1, h2;

    h1.age = 10;
    h1.name = "Пертов";
    h1.weight = 333;
    h1.show_info();
    cout << "=========================" << endl;

    h2.age = 33;
    h2.name = "Иванов";
    h2.weight = 444;
    h2.show_info();
    return 0;
}
