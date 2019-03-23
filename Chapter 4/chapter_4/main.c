/*
Chapter 4: Floating Point Issues
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LETTER_BOX_SIZE 12

int main()
{
/*
Q 4.1
What would be the output of the following program?
A: actually the value of a is 0.6999988, it is less than 0.7, so condition is TRUE
*/
    printf("Q 4.1\n");
    float a = 0.7;
    if(a < 0.7){                //a is comparing to double which is more precise, condition is TRUE
        printf("\"C\"\n");
    } else{
        printf("\"C++\"\n");
    }

/*
Q 4.2
What would be the output of the following program?
A: if 'f' is specified it means float, otherwise it means double
*/
    printf("Q 4.2\n");
    float b = 0.7;

    if(b < 0.7f){               //b is comparing to float, the condition id FALSE
        printf("\tC\n");
    } else {
        printf("C++\n");
    }

/*
Q 4.3
What would be the output of the following program?
A:
*/
    printf("Q 4.3\n");
    printf("%f\n", sqrt(36.0));

/*
Q 4.4
Would this program give proper result?
A: <math.h> should be included
*/
    printf("Q 4.4\n");
    printf("%.2f\n", log(36.0));

/*
Q 4.5
Would the following printf prints the same value for any value of g?
A:
*/
    printf("Q 4.5\n");
    float g;
    //scanf("%f", &g);
    printf("%f\n", g + g + g);
    printf("%f\n", 3 * g);

/*
Q 4.7
Which error are u likely to get when u run the following program?
A: Floating point formats not linked ONLY For Turbo C
*/
    printf("Q 4.7\n");

    struct emp{
        char name[20];
        float sal;
    };

    struct emp e[10];
    int i;
    for(i = 0; i< 2; i++){
        //scanf("%s %f", e[i].name, &e[i].sal);
    }
    for(i = 0; i< 2; i++){
        printf("%s %f", e[i].name, e[i].sal);
    }

/*
Q 4.13
What would be the output of the following program?
A:
*/
    printf("\nQ 4.13\n");
    printf("%d %d %d\n", sizeof(3.14f), sizeof(3.14), sizeof(3.14l));
    printf("%d %d %d\n", sizeof(float), sizeof(double), sizeof(long double));
    printf("%d\n", sizeof(short int));
    printf("%d\n", sizeof(int ));

    printf("%d");

    printf("\nQ 4.14\n");
    int x,y,z,d;
    x = 10;
    y = 20;
    z = 100;
    d = x / y * 100;
    d -= x * z / y;
    printf("d = %d\n", d);

    #pragma pack(push, 1)
    typedef struct{
        int a;
        char b;
    } s;
    #pragma pack(pop)

    typedef struct{
        char b;
        int a;
    } p;

    typedef union{
        char a;
        int b;
        //double d;
    } _u;

    printf("size of s = %d\n", sizeof(s));
    printf("size of p = %d\n", sizeof(p));
    printf("size of union = %d\n", sizeof(_u));

    static const unsigned char Letter_Box[LETTER_BOX_SIZE] =
    {
        '!',
        'd',
        'l',
        'r',
        'o',
        'w',
        ' ',
        'o',
        'l',
        'l',
        'e',
        'H'
    };
    signed int y1;
    for(y1 = LETTER_BOX_SIZE - 1; y1 >= 0; y1--){
        printf("%c", Letter_Box[y1]);
    }
    printf("\n");

    for(int i = 0; i < 5; ++i){
        printf("%0X ", i);
    }
    printf("\n");

    for(int i = 0; i >  -5; --i){
        printf("%0X ", i);
    }
    printf("\n");



    return 0;
}
