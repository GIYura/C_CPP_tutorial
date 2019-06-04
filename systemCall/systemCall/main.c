#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>

int main()
{
    //char cmd[50];
    //strcpy(cmd, "ls -l ");
    //system(cmd);

    printf("%d\n", SYS_write);

    return 0;
}
