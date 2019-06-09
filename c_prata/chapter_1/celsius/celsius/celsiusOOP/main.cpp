#include <iostream>

using namespace std;

typedef enum{
        CELSIUS,
        FARENHEIT
    } name_t;

class Convert{

public:
    double celsius_farenheint(double);
    double farenheint_celsius(double);
    void promt(name_t);
};

int main()
{
    Convert *convert = new Convert();
    name_t n;

    return 0;
}

double Convert::celsius_farenheint(double celsius){
    return (celsius * 9 / 5) + 32;
}

double Convert::farenheint_celsius(double farenheit){
    return (farenheit - 32) * 5 / 9;
}

void Convert::promt(name_t n){
    switch(n){
        case CELSIUS:
            cout << "Please, enter temperature in Celsius" << endl;
        break;

        case FARENHEIT:
            cout << "Please, enter temperature in Farenheit" << endl;
        break;

        default :
            cout << "Incorrect type" << endl;
        break;
    };

}

