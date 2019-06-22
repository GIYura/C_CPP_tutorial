#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ageYear;

    const int dayInYear = 365;
    printf("Please, enter your age in years:\n");
    scanf("%d", &ageYear);
    printf("Your age in days: %d\n", ageYear * dayInYear);

    return 0;
}
