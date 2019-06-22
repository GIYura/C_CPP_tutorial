#include <stdio.h>
#include <stdlib.h>

void smile(void);

int main()
{
    /*smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();*/

    for(int i = 3; i > 0; i--){
        for(int j = i; j > 0; j--){
            smile();
        }
        printf("\n");
    }
    return 0;
}

void smile(void){
    printf("Smile!");
}
