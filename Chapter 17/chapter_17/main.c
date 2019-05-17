/*
Chapter 17 - Memory allocation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SZ 10

char *fun();

void fillArray(int *, int, int(*pFun)(void));
int getRandValue(void);
int getZeroValue(void);
void printArray(int *, int);

void myCallback(void);
void myCallbackReg(char *, void(*pF)(void));

typedef struct{
    //int x;
    //int y;
    int (*fun_1)();
}Tpoint;

int fun_1(void);
Tpoint fun_2(void);

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

/*
Q 17.4
How would you dynamically allocate a 1-D array of integer?
A:
*/
    printf("Q 17.4\n");
    int *p = (int *)malloc(sizeof(int) * ARR_SZ);
    for(int i = 0; i < ARR_SZ; i++){
        p[i] = i;
        printf("%d ", p[i]);
    }
    printf("\n\n");

    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    printArray(array, 10);
    fillArray(array, 10, getRandValue);
    printArray(array, 10);
    fillArray(array, 10, getZeroValue);
    printArray(array, 10);
//
//
//
//
    myCallbackReg("Yura", &myCallback);

    Tpoint point = fun_2();
    printf("%d\n", point.fun_1());

/*
Q 17.5
How would you dynamically allocate a 2-D array of integer?
A:
*/
    printf("Q 17.5\n");
    #define MAXCOL      3
    #define MAXROW      4
    int *pi = (int*)malloc(MAXCOL * MAXROW * sizeof(int));
    for(int i = 0; i < MAXCOL; i++){
        for(int j = 0; j < MAXROW; j++){
            pi[i * MAXCOL + j] = i;
            printf("%d ", pi[i * MAXCOL + j]);
        }
        printf("\n");
    }


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

void fillArray(int *arr, int arrSz, int(*pFun)(void)){
    for(int i = 0; i< arrSz; i++){
        arr[i] = (*pFun)();
    }
}

int getRandValue(void){
    return (unsigned char)rand();
}

int getZeroValue(void){
    return 0;
}

void printArray(int *a, int arrSz){
    for(int i = 0; i < arrSz; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
/*
Three things should be implemented in callback functions developing:
1. callback definition
2. callback registration
3. callback execution
===================================================================
1. Defining a callback is simple. It’s the same as any other function. An example callback function for a watchdog timer might look something like the following:

void Watchdog_ExpiredCallback(void)
{

}
*/

void myCallback(void){
    printf("Hello from callback\n");
}

void myCallbackReg(char *name, void(*pF)(void)){
    printf("%s, ", name);
    (*pF)();

}

int fun_1(void){
    return 0;
}

Tpoint fun_2(void){
    Tpoint p;
    p.fun_1 = &fun_2;
    return p;
}
