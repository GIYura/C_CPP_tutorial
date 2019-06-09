#include "stdio.h"

#define RATIO	2.54

int main(int argc, char const *argv[])
{
	double inch;

	printf("Please, input value in inches\n");
	scanf("%lf", &inch);
	printf("Value in centimeters = %4.2f\n", inch * RATIO);

	return 0;
}