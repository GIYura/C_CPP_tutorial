#include <stdio.h>
#include <stdlib.h>

void one_three(void);
void two(void);

int main()
{
    printf("Start:\n");
    one_three();
    printf("Ok");
    return 0;
}

void one_three(void){
    printf("one\n");
    two();
    printf("three\n");
}

void two(void){
    printf("two\n");
}
