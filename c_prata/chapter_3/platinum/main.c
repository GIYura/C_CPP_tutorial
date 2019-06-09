#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define COEFF   14.5833
#define COST    1700

int main()
{
    float weight;
    printf("Input your weight in kilos\n");
    scanf("%f", &weight);

    if(weight < 0){
        printf("Incorrect number\n");
        return -1;
    }

    printf("Platinum equivalent = %.2f", weight * COEFF * COST);

    return 0;
}
