/*
Chapter 9 - Arrays
*/

#include <stdio.h>
#include <stdlib.h>

void fun(int **);

int main()
{
/*
Q 9.1
What would be the output of the following program?
A:
*/
    printf("Q 9.1\n");
    char a[] = "Visual C++";
    char *b = "Visual C++";
    printf("%d %d\n", sizeof(a), sizeof(b));
    printf("%d %d\n", sizeof(*a), sizeof(*b));

/*
Q 9.2
For the following statements would arr[3] and ptr[3] fetch the same char?
A:
*/
    printf("Q 9.2\n");
    char arr[] = "Hello";
    char *parr = "Hello";
    printf("%c %c\n", arr[3], parr[3]);

/*
Q 9.4
What would be the output of the following code?
A:
*/
    printf("Q 9.4\n");
    int q[] = {1,2,3,4,5};
    printf("%d %d\n", q, sizeof(q));
    printf("%u %u\n", q, &q);
    printf("%u %u\n", q + 1, &q + 1);

/*
Q 9.10
Would the following program compile successfully?
A:
*/
    printf("Q 9.10\n");
    char w[] = "Sunstroke";
    char *u = "Coldwave";
    //w = "Coldwave";
    u = "Sunstroke";
    printf("%s %s\n", w, u);

/*
Q 9.11
What would be the output of the following code?
A:
*/
    printf("Q 9.11\n");
    float rr[] = {1.2, 3.3, 6.6, 7.44, 8.01};
    printf("%d\n", sizeof(rr) / sizeof(rr[0]));
    printf("%d\n", sizeof(float));

/*
Q 9.13
What would be the output of the following code?
A:
*/
    printf("Q 9.13\n");
    int h[3][4] =   {
                        1,2,3,4,
                        4,3,2,1,
                        7,8,9,0
                    };

    printf("%u %u\n", h + 1, &h + 1);

/*
Q 9.14
What does the following statement mean?
int (*ptr)[10];
A: указатель на массив из 10 int
    pointer to an array of 10 int
*/
    printf("Q 9.14\n");

/*
Q 9.17
What would be the output of the following code?
A:
*/
    printf("Q 9.17\n");
    int h1[3][4] =   {
                        1,2,3,4,
                        4,3,2,1,
                        7,8,9,0
                    };

    int *ph1;
    ph1 = &h1[0][0];
    fun(&ph1);

    char greeting[] = "Hello";
    char *pGreeting = greeting;

    char *greet = "Hello";
    //greet = 'A';

    while(*greet){
        printf("%c ", *greet++);
    }

    while(*pGreeting){
        printf("%c ", *pGreeting++);
    }

    int sz = strlen(greeting);

    for(int i=0; i< sz; ++i){
        printf("%c ", greeting[i]);
    }

    greeting[0] = 'M';
    pGreeting = greeting;
    while(*pGreeting){
        printf("%c ", *pGreeting++);
    }


    return EXIT_SUCCESS;
}


void fun(int **p){
    printf("%d\n", **p);
}
