/*
Chapter 16 - Const
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 128

int get(void);
const char *fun(void);

int main()
{
/*
Q 16.1
Point out the error in the following program
A: const should be init where it is declared
*/
    printf("Q 16.1\n");
    const int x = 128;
    printf("%d\n", x);

/*
Q 16.2
What would be the output of the following program?
A:
*/
    printf("Q 16.2\n");
    int y = 125;
    const int z = y;
    printf("%d\n", z);

/*
Q 16.3
What would be the output of the following program?
A:
*/
    printf("Q 16.3\n");
    const int s = get();
    printf("%d\n", s);

/*
Q 16.4
Point out the error, if any, in the following code
A: array size must be positive number
*/
    printf("Q 16.4\n");
    const int max = 128;
    char array[max];
    char string[MAX];
    array[0] = string[0] = 'A';
    printf("%c %c\n", array[0], string[0]);

/*
Q 16.5
Point out the error, if any, in the following code
A:  ptr is constant, it is error to modify it
*/
    printf("Q 16.5\n");
    char myBuff[] = "BlaBla";
    char yourBuff[] = "MlaMla";
    char *const ptr = myBuff;
    *ptr = 'A';
    //ptr = yourBuff; //error

/*
Q 16.6
Point out the error, if any, in the following code
A: ptr in NOT const, but data is, so it is error to modify const data
*/
    printf("Q 16.6\n");
    char myBuff1[] = "BlaBla";
    char yourBuff1[] = "MlaMla";
    const char *ptr1 = myBuff1;
    //*ptr1 = 'A';            //error
    ptr1 = yourBuff1;

 /*
 Q 16.7
 Point out the error, if any, in the following code
 A: p is a constant pointer to constant char, it is error to modify pointer and data
 */
    printf("Q 16.7\n");
    char myBuff2[] = "BlaBla";
    const char * const p = "Hello";
    //p = myBuff2;        //error
    //*p = 'S';           //error

 /*
 Q 16.8
 What does the following prototype indicate: strcpy(char *target, const char *source);
 A: inside strcpy pointers target and source can be modified, but the object to which source is pointing cannot be modified
 */
    printf("Q 16.8\n");

 /*
 Q 16.9
 What does the following prototype indicate: const char *change(char *, int);
 A: function change() get a char pointer and int and returns a pointer to constant char
 */
    printf("Q 16.9\n");

/*
 Q 16.10
 Point out the error, if any, in the following code
 A:
 */
    printf("Q 16.10\n");
    char *ptr2 = fun();
    printf("%s\n", ptr2);

/*
Q 16.11
Is there any error in the following code?
A: NO
*/
    printf("Q 16.11\n");
    const char *fun1();
    char *ptr3 = fun1();
    printf("%s\n", ptr3);

/*
Q 16.12
Point out the error if any in the following code?
A: fun2() return pointer to a const char which cannot be modified
*/
    printf("Q 16.12\n");
    const char *fun2();
    //*fun2() = 'A';

/*
Q 16.14
What would be the output of the following program?
A: 10
*/
    printf("Q 16.14\n");
    const int a = 5;
    int *ptra;
    ptra = &a;
    *ptra = 10;
    printf("%d\n", a);

/*
Q 16.15
What would be the output of the following program?
A:
*/
    printf("Q 16.15\n");
    const int b = 5;
    const int *ptrb;
    ptrb = &b;
    //*ptrb = 10;     //error ptrb is const pointer
    printf("%d\n", b);

/*
Q 16.16
Point out the error in the following program?
A:
*/
    printf("Q 16.16\n");
    const int k = 7;
    int *const q = &k;
    printf("%d\n", *q);

    return 0;
}


int get(void){

    return (20);
}

const char *fun(void){
    return "Hello_0";
}

const char *fun1(void){
    return "Hello_1";
}

const char *fun2(void){
    return "Hello_2";
}

/*
int *p                          p is a pointer to int
const int * const p             p is a constant pointer to constant int
const int *p OR int const *p    p is pointer to int constant
int *const p                    p is constant pointer to int

int const  *ptr; // ptr is a pointer to constant int
int *const ptr;  // ptr is a constant pointer to int

*/
