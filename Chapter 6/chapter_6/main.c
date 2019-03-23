/*
Chapter 6 - Preprocessor
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SQR(x)  ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define SWAP(a,b,c) c t; t = a, a = b, b = t;
#define SWAP_(x,y) x = x + y; y = x - y; x = x - y;

#define MESS "Junk"
#define INFINITELOOP    while(1)

#define MAX(a, b) (a > b ? a : b)
#define MIN(a,b)    (a < b ? a : b)

#define PRINT(int)  printf("%d ", int)
#define PRINT_(int)  printf("int = %d ", int)
#define PRINT__(int)  printf(#int " = %d ", int)
#define MAKE_STR(s) #s

#define DEBUG(var, fmt) printf("DEBUG:" #var "=" #fmt "\n", var)
#define DEBUG_(var1, var2, var3) printf(#var1 "= %d " #var2 "= %d " #var3 "= %d ", var1, var2, var3)

#define STR(x)  #x
#define X_STR(x)    STR(x)
#define OPER    MULTIPLY

#define GET_VAR_NAME(x) #x

#define MUL(a,b) (a * b)
#define MUL_(a,b) ((a) * (b))

char* convert(short);
void convert_(short);

#define MAX(a,b)    ((a > b) ? (a) : (b))

static inline int fun(int d){
    return d++;
}

static inline int maxFunc(int a, int b){
    return ((a > b) ? a : b);
}

void swap(int *, int *);

int main()
{
/*
Q 6.3
What would be the output of the following code?
A:  #define SQR(x)  (x * x) -> (b + 2 * b + 2) = 11
    #define SQR(x)  ((x) * (x)) -> ( (b + 2) * (b + 2) ) = 25
*/
    printf("Q 6.3\n");
    int a, b = 3;
    a = SQR(b + 2);
    printf("%d\n", a);

/*
Q 6.5
What would be the output of the following code?
A: 27 6
The behaviour is UNDEFINED the better solution to avoid this MACRO
*/
    printf("Q 6.5\n");
    int x, y = 3;
    x = CUBE(y);
    printf("%d %d\n", x, y);

/*
Q 6.6
A:
*/
    printf("Q 6.6\n");
    int q = 10, w = 20;
    printf("q = %d w = %d\n", q, w);
    SWAP(q,w,int);
    printf("q = %d w = %d\n", q, w);
    SWAP_(q, w);
    printf("q = %d w = %d\n", q, w);

    float r = 5.55;
    float p = 33.088;
    printf("%f %f\n", r, p);
    SWAP_(r, p);
    printf("%f %f\n", r, p);

    int n = 44;
    int m = 55;
    printf("n = %d m = %d\n", n, m);
    swap(&n, &m);
    printf("n = %d m = %d\n", n, m);


    int *ip, ih;
    printf("%d %d\n", sizeof(ip), sizeof(ih));

/*
Q 6.18
What would be the output of the following code?
A: pay attantion to ""
*/
    printf("Q 6.18\n");
    printf(MESS);

/*
Q 6.19
Would the following program print the message infinite number number of times?
A: YES
*/
    printf("Q 6.19\n");
    //INFINITELOOP
        printf("Red haired\n");

/*
Q 6.20
What would be the output of the following code?
A:
*/
    printf("Q 6.20\n");
    int max, min;
    max = MAX(3+2, 2+7);
    printf("max = %d\n", max);
    min = MIN(3+2, 2+7);
    printf("min = %d\n", min);

/*
Q 6.21
What would be the output of the following code?
A:
*/
    printf("Q 6.21\n");
    int _1 = 1;
    int _2 = 2;
    int _3 = 3;
    PRINT(_1);
    PRINT(_2);
    PRINT(_3);
    printf("\n");
/*
Q 6.22
What would be the output of the following code?
A:
*/
    printf("Q 6.22\n");
    int _11 = 1;
    int _22 = 2;
    int _33 = 3;
    PRINT_(_11);
    PRINT_(_22);
    PRINT_(_33);
    printf("\n");

    int oop = 10;
    printf(MAKE_STR(oop));
    printf("\n");

    int s = 1;
    int d = 2;
    int f = 3;
    PRINT__(s);
    PRINT__(d);
    PRINT__(f);
    printf("\n");
/*
Q 6.23
Would the following code compile successfully?
A:
*/
    printf("Q 6.23\n");
    printf("Tips" "Traps");
    printf("\n");

/*
Q 6.25
A:
*/
    printf("Q 6.25\n");
    int k = 10;
    float l = 3.14;
    char ch = 'A';
    DEBUG(k, %d);
    DEBUG(l, %f);
    DEBUG(ch, %c);

/*
Q 6.26
A:
*/
    printf("Q 6.27\n");
    char *opername = X_STR(OPER);
    printf("%s\n", opername);
    printf("\n");
/*
Q 6.27
A:
*/
    printf("Q 6.27\n");
    int tt = 10, rr = 20, ii = 30;
    int tt1 = 10, rr1 = 20, ii1 = 30;
    DEBUG_(tt,rr,ii);
    printf("\n");
    DEBUG_(tt1,rr1,ii1);
    printf("\n");

    printf("%s\n", GET_VAR_NAME(tt));

/*
Q 6.28(Add)
A:
*/
    int T = 10;
    int P = 20;
    printf("\nInit values are: %s = %d %s = %d\n", GET_VAR_NAME(T), T, GET_VAR_NAME(P), P);
    printf("\nMAX is: %d\n", MAX(T++, P++));
    printf("\nModified values are: %s = %d %s = %d\n", GET_VAR_NAME(T), T, GET_VAR_NAME(P), P);
    printf("\n**************************************************\n");

    T = 10;
    P = 20;
    printf("\nInit values are: %s = %d %s = %d\n", GET_VAR_NAME(T), T, GET_VAR_NAME(P), P);
    printf("\nMAX is: %d\n", maxFunc(T++, P++));
    printf("\nModified values are: %s = %d %s = %d\n", GET_VAR_NAME(T), T, GET_VAR_NAME(P), P);
    printf("\n**************************************************\n");

    return 0;
}

void swap(int *a, int *b){

    int t = *a;
    *a = *b;
    *b = t;
}
