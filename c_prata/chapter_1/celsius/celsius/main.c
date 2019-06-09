#include <stdio.h>
#include <stdlib.h>

double celsius_farenheit(double);
double farenheit_celsius(double);

int main()
{
    double celsius, farenheit;

    printf("Please, enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    printf("The temperature in Fahrenheit: %4.2f\n", celsius_farenheit(celsius));

    printf("Please, enter temperature in Farenheit: ");
    scanf("%lf", &farenheit);
    printf("The temperature in Celsius: %4.2f\n", farenheit_celsius(farenheit));

    return 0;
}

//
double celsius_farenheit(double celsius){

    return (celsius * 9 / 5) + 32;
}

//
double farenheit_celsius(double farenheit){
    return (farenheit - 32) * 5 / 9;
}
