#include <stdio.h>
#include <stdlib.h>

typedef enum{
    FIRST_NAME,
    SECOND_NAME,
    THIRD_NAME,
    NAME_NUM
} fio_t;

char *credentials[] = {"Hlotov", "Yura", "Nikolaevich"};

void print(fio_t);

int main()
{
    for(fio_t fio = FIRST_NAME; fio < NAME_NUM; fio++){
        print(fio);
    }
    return 0;
}

void print(fio_t f){
    if(f > NAME_NUM){
        return;
    }
    printf("%s\n", credentials[f]);
}
