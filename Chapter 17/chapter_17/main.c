/*
Chapter 17 - Memory allocation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fun();

int main()
{
/*
Q 17.1
What would be the output of the following code?
A:
*/
    printf("Q 17.1\n");
    char *s;
    //char *fun();
    s = fun();
    printf("%s\n", s);
    free(s);
    return 0;
}


char *fun(){
    char *p = malloc(10);
    if(NULL == p){
        printf("can't allocate memory\n");
        return -1;
    }
    //char buffer[30];
    strcpy(p, "RAM");
    return p;
}
