/*
Chapter 8 - Pointers (part 2)
*/

#include <stdio.h>
#include <stdlib.h>

#include "test.h"

#define GET_NAME(x) #x
#define ROWS    3
#define COLS    3

char *myStrCopy(char *, char *);
int myStrLen(char *);
void myStrReverse(char s[]);
char* myStrReverse_1(char *);

int bitReverse(short);

typedef struct {
        char lname[20];
        char fname[20];
        int age;
        float rate;
    } Tperson;

    Tperson worker;

void showInfo(Tperson *e);

int COEFF_1 = 10;

int array[] = {1,2,3,4,5,6,7};

static int var = 10;
void setVar(int );
int getVar();

int main(int argc, char *argv[])
{
    for(int i = 0; i < argc; i++){
        printf("%s ", argv[i]);
    }
/*
Q 8.1
Is the NULL pointer same as uninitialized pointer
A: NO
*/
    printf("Q 8.1\n");

/*
Q 8.2
In which header file is the NULL macro defined?
A: stdio.h stddef.h
*/
    printf("Q 8.2\n");

    char *s = "\12345s\n";
    printf("%d\n", sizeof(s));

    printf("%d ", 1 & (~1));
    printf("%d ", 23 & (~23));
    printf("%d ", 2012 & (~2012));
    printf("\n");

/*
Q 8.8
What would be the output of the following program?
A:
*/
    printf("Q 8.8\n");
    printf("%d %d\n", sizeof(NULL), sizeof(""));

/*
Q 8.17
Would the following program give any warning on compilation?
A: NO
*/
    int *p1, t = 10;
    void *p2;
    p1 = &t;
    p2 = &t;
    p1 = p2;
    p2 = p1;

/*
Q 8.18
Would the following program give any warning on compilation?
A: -
*/
    float *pf1, f = 10;
    char *pf2;
    p1 = &f;
    p2 = &f;
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        Ted Jensen: A tutorial on pointers and arrays in C
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/* Program 1.1*/
    int j,k;
    int *ptr;
    j = 1;
    k = 2;

    ptr = &k;

    printf("j has value %d and is stored at %p\n", j, &j);
    printf("k has value %d and is stored at %p\n", k, &k);
    printf("ptr has value %p and is stored at %p\n", ptr, &ptr);
    printf("The value of the integer pointed to by ptr is %d\n\n", *ptr);

/* Program 2.1*/
    int arr[] = {0,-3, 9, 1000};
    //int *parr = arr;
    int *parr;
    parr = arr;//&arr[0];

    for(int i = 0; i < 4; i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    for(int i = 0; i < 4; i++){
        //printf("parr + %d = %d\n", i, *(parr + i));
        //printf("parr + %d = %d\n", i, *parr++);
        printf("parr + %d = %d\n", i, *++parr);
        //printf("parr + %d = %d\n", i, ++*parr);
    }

    char strA[100] = "This is a string of characters";
    char strB[100];
    char *pA;
    char *pB;
    puts(strA);
    pA = strA;
    puts(pA);
    pB = strB;
    putchar('\n');

    while(*pA){
        *pB++ = *pA++;
    }
    *pB = '\0';
    pB = strB;
    puts(pB);


    char strA1[100] = "This string should be copied";
    char strB1[100];
    printf("%s\n", myStrCopy(strB1, strA1));
    printf("String %s contains %d chars\n", GET_NAME(strA1), myStrLen(strA1));

    char pStrR[] = "This string should be reversed";
    printf("\n%s\n", pStrR);
    myStrReverse(pStrR);
    printf("%s\n", pStrR);

    char *pSTR = "Hello";
    printf("%s\n", myStrReverse_1(pSTR));

    int l = 0x01;
    printf("%#0x\n", l);
    printf("%#0x\n", bitReverse(l));
/*
Chapter 5 Structures
*/
    strcpy(worker.fname, "Peter");
    strcpy(worker.lname, "Anders");
    worker.age = 55;
    worker.rate = 1.2;
    showInfo(&worker);

/*
Chapter 6 More on strings
*/
    int multi[ROWS][COLS];
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS; col++){
            multi[row][col] = row * col + 1;
        }
    }

    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS; col++){
            printf("%d ", multi[row][col]);
        }
        printf("\n");
    }

    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS; col++){
            printf("%d ", *(*(multi + row) + col));
        }
        printf("\n");
    }
    printf("%d ", multi[2][2]);
    printf("%d ", *(*(multi + 2) + 2));
    printf("\n");


    printf("Init value of static var is %d\n", getVar());
    myFuncPrint();
    printf("Modified value of static var is %d\n", getVar());

    char msg_1[6] = {'h','e','l','l','o','\0'};
    printf("%s %d %d\n", msg_1, strlen(msg_1), sizeof(msg_1));

    char msg_2[] = "HELLO";
    printf("%s %d %d\n", msg_2, strlen(msg_2), sizeof(msg_2));

    char *msg_3 = (char*)malloc(sizeof(char) * 100);
    if(NULL == msg_3){
        printf("Can't allocate memory\n");
        return EXIT_FAILURE;
    }
    msg_3[0] = 'P';
    msg_3[1] = 'R';
    msg_3[2] = 'I';
    msg_3[3] = 'V';
    msg_3[4] = 'E';
    msg_3[5] = 'T';
    msg_3[6] = '\0';
    printf("%s\n", msg_3);
    free(msg_3);

    char *msg_4 = "WORLD";
    printf("%s\n", msg_4);

    char msg_5[] = "VICTORY";
    char *pmsg5 = msg_5;
    printf("%s\n", pmsg5);

    char msg_6[] = "This is a string";
    char msg_7[20] = "string a is This";
    printf("%s\n", msg_7);
    strcpy(msg_7, msg_6);
    printf("%s\n", msg_7);

    char *msg_8 = "55";
    printf("%s\n", msg_8 + 1);
    printf("%d\n", atoi(msg_8) + 10);

    char *msg_9[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    int sx = sizeof(msg_9) / sizeof(msg_9[0]);
    for(int day = 0; day < sx; day++){
        printf("%s ", msg_9[day]);
    }

    return EXIT_SUCCESS;
}

/*


*/
char *myStrCopy(char *d, char *s){
    char *temp = d;
    while(*temp++ = *s++);
    return d;
}

int myStrLen(char *s){
    int counter = 0;
    while(*s++){
        counter++;
    }
    return counter;
}

void myStrReverse(char s[]){
    int sz = strlen(s);

    for(int i = 0; i < sz / 2; i++){
        char t = s[i];
        s[i] = s[sz - i - 1];
        s[sz - i - 1] = t;
    }
}

char* myStrReverse_1(char *s){
    int sz = 0;

    while(*s != '\0'){
        sz++;
        s++;
    }
    s--;

    char *t = (char*)malloc(sizeof(char) * (sz + 1));
    if(NULL == t){
        printf("Can't allocate memmory\n");
    }
    char *p = t;
    while(sz--){
        *p++ = *s--;
    }
    *p = '\0';
    return t;
}

int bitReverse(short num){
    static unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0;
    int i;
    for (i = 0; i < NO_OF_BITS; i++)
    {
        if((num & (1 << i)))
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
   }
    return reverse_num;
}

void showInfo(Tperson *e){
    printf("%s ", e->fname);
    printf("%s ", e->lname);
    printf("%d\n", e->age);
}

void setVar(int newVal){
    var = newVal;
}
int getVar(){
    return var;
}
