/*
Chapter 3 - Expressions
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

/*
Q 3.1
What would be the output of the following program?
A:
*/
    printf("Q 3.1\n");
    static int arr[20];
    int ii = 0;
    arr[ii] = ii++;
    printf("%d %d %d\n", arr[0], arr[1], ii);

/*
Q 3.2
What would be the output of the following program?
A:
*/
    printf("Q 3.2\n");
    int x = 3;
    x = x++;
    printf("%d\n", x);

/*
Q 3.3

A:
*/
    printf("Q 3.3\n");

/*
Q 3.4
What would be the output of the following program?
A: the output may vary from compiler to compiler
*/
    printf("Q 3.4\n");
    int t = 2;
    printf("%d %d\n", ++t, ++t);

/*
Q 3.5
What would be the output of the following program?
A: (a < b) < c 1. b>a ? true 1, then 1 < c true the answer is 1
*/
    printf("Q 3.5\n");
    int a = 10, b = 20, c = 5, res;
    res = a < b < c;
    printf("%d\n", res);

/*
Q 3.6
Are the following 2 statements same?
a <= 20 ? b = 30 : c = 30
(a <= 20) ? b : c = 30

A: no
*/
    printf("Q 3.6\n");

/*
Q 3.13
What would be the output of the following program?
A:
*/
    printf("Q 3.13\n");
    int i = -3, j = 2, k = 0, m;
    m = ++i && ++j || ++k;

    printf("%d %d %d %d\n", i,j,k,m);

/*
Q 3.14
What would be the output of the following program?
A:
*/
    printf("Q 3.14\n");
    int i1 = -3, j1 = 2, k1 = 0, m1;
    m1 = ++j1 && ++i1 || ++k1;
    printf("%d %d %d %d\n", i1,j1,k1,m1);

/*
Q 3.15
What would be the output of the following program?
A:
*/
    printf("Q 3.15\n");
    int i2 = -3, j2 = 2, k2 = 0, m2;
    m2 = ++i2 || ++j2 && ++k2;
    printf("%d %d %d %d\n", i2,j2,k2,m2);

/*
Q 3.16
What would be the output of the following program?
A:
*/
    printf("Q 3.16\n");
    int i3 = -3, j3 = 2, k3 = 0, m3;
    m3 = ++i3 && ++j3 && ++k3;
    printf("%d %d %d %d\n", i3,j3,k3,m3);

    return 0;
}
