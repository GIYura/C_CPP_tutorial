/*
Chapter 5 - Functions
*/

#include <stdio.h>
#include <stdlib.h>

int sumdig(int);
int func1(int, int);
float func2(float, float);
int main()
{
/*
Q 5.1
What would be the output of the following program?
A: 6 12
*/
    printf("Q 5.1\n");
    int a, b;
    a = sumdig(123);
    b = sumdig(123);
    printf("%d %d\n", a, b);

 /*
 Q 5.2
 What error would the following function give on compilation?
 A: func1 Error: redeclared as different kind of symbol
 */
    printf("Q 5.2\n");

/*
Q 5.3
There is a mistake in the following code. Add a statement to it to remove it.
A: prototype should be added
*/
    printf("Q 5.3\n");
    float x;
    x = func2(10, 3.14);
    printf("%.2f\n", x);

    main();

    return 0;
}

int sumdig(int n){
    static int s = 0;
    int d;
    if(n != 0){
        d = n % 10;
        n = (n - d) / 10;
        s = s + d;
        sumdig(n);
    } else {
        return (s);
    }
}

/*
int func1(int a, int b){
    int a;
    a = 20;
    return a;
}
*/

float func2(float aa, float bb){
    return ((float)aa + bb);
}
