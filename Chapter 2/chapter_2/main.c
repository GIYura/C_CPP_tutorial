/*
Chapter 2: Control Instructions
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
Q 2.1
What would be the output of the following program?
A:
*/
    printf("Q 2.1\n");
    int i = 4;
    switch(i){
        default:
            printf("A mouse is the elephant built by the Japanese\n");
        case 1:
            printf("Breeding rabbits is a hare raising experience\n");
            break;
        case 2:
            printf("Friction is a drag\n");
        break;

        case 3:
            printf("If practice makes perfect, nobody's perfect\n");
    }

/*
Q 2.2
Point out the error, if any, in the for loop
A: No error
*/
    printf("Q 2.2\n");
    int a = 1;
    for(;;){
        printf("%d ", a++);
        if(a > 10)
            break;
    }
    printf("\n");

/*
Q 2.3
Point out the error, if any, in the for loop
A: the condition in the while loop is a MUST
*/
    printf("Q 2.3\n");
    int y = 1;
    while(1){
        printf("%d ", y++);
        if(y > 10){
            break;
        }
    }
    printf("\n");

/*
Q 2.4
Point out the error, if any, in the while loop
A: goto could not take control to a different function
*/
    printf("Q 2.4\n");
    int e = 1;
    //while(e <= 5) //{
    //    printf("%d", e);
    //    if(e > 2){
            //goto here;
    //    }
    //}

/*
Q 2.5
Point out the error, if any, in the following program
A: case expression should be constant
*/
    printf("Q 2.5\n");
    const int u = 4, r = 2;
    switch(u){
        case 1:
            printf("Bla-bla\n");
        break;

        case 2:
            printf("Blu-Blu\n");
        break;
    }

/*
Q 2.6
Point out the error, if any, in the following program
A: no error
*/
    printf("Q 2.6\n");
    int q = 1;
    switch(q){
        case 1:
            printf("MMMM\n");
        break;

        case 1 * 2 + 4:
            printf("mmm\n");
        break;
    }

/*
Q 2.7
Point out the error, if any, in the following program
A: no error
*/
    printf("Q 2.7\n");
    int w = 1;
    switch(w){

    }
    printf("GGGG\n");

/*
Q 2.8
Point out the error, if any, in the following program
A: printf("Hello\n"); never prints it should belong to any case
*/
    printf("Q 2.8\n");
    int p = 1;
    switch(p){
        printf("Hello\n");
        case 1:
            printf("Hello_1\n");
        break;

        case 2:
            printf("Hello_2\n");
        break;
    }

/*
Q 2.9
A:
*/
    printf("Q 2.9\n");

/*
Q 2.10
Point out the error, if any, in the following program
A: Remember that the = operator is an assignment operator and its precedence
is less than that of the ternary operator. Which means that x > y ? x : x = y is equivalent to (x >
y ? x : x) = y . As you may have guessed, the ternary operation cannot be an lvalue and then
generates a compilation error.
*/
    printf("Q 2.10\n");
    int l = 10, b;
    l >= 5 ? b = 100 : (b = 200);
    printf("%d\n", b);

/*
Q 2.11
What would be the output of the following program?
A:
*/
    printf("Q 2.11\n");
    char str[] = "Part-time musicians are semiconductors";
    int xx = 5;
    printf(xx > 10 ? "%50s" : "%s", str);
    return 0;
}

void fun(){
        here:
            printf("If it works, don't fix it");
    }
