#include <stdio.h>
#include <stdlib.h>

void jolly(void);
void deny(void);

int main()
{
    jolly();
    jolly();
    jolly();
    deny();
    return 0;
}

void jolly(void){
    printf("%s\n", "Он веселый молодец!");
}

void deny(void){
    printf("%s\n", "Никто не может это отрицать!");
}
