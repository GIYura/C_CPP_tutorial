/*
Chapter 15 - Typedef
*/

#include <stdio.h>
#include <stdlib.h>

struct Person{
    char *name;
    int age;
};

#define P struct Person

int myFunc(char *, char *);
void testFunc(void);

int main()
{
/*
Q 15.1
Are the properties od i,j,x,y in the following program the same?
A: YES
*/
    printf("Q 15.1\n");
    typedef unsigned long int uli;
    uli i, j;
    unsigned long int x, y;

/*
Q 15.2
What is the type of compare in the following code segment?
A: pointer to a function which take 2 char pointers and return int
*/
    printf("Q 15.2\n");
    typedef int (*ptr2func)(char *, char *);
    ptr2func compare = &myFunc;

    char *s1 = "Hello";
    char *s2 = " World\n";
    (*compare)(s1, s2);

/*
Q 15.3
What are the advantages of using typedef in code?
A:
*/
    printf("Q 15.3\n");

/*
Q 15.4
Are there any difference in the #define and typedef in the following code?
A: s_1, s_2, s_3 are all pointer to char, s_4 char
*/
    printf("Q 15.4\n");
    typedef char* string_t;
    #define string_d char*

    string_t s_1, s_2;
    string_d s_3, s_4;

    s_1 = "Hello";
    s_2 = "World";
    s_3 = "From";
    s_4 = 'C';

    printf("%s %s %s %c\n", s_1, s_2, s_3, s_4);

/*
Q 15.5
A: typedef can be declared localy, while #define always have global scope
*/
    printf("Q 15.5\n");
    testFunc();
    P p2;
    p2.name = "Steve";
    p2.age = 55;
    printf("%s %d\n", p2.name, p2.age);

/*
Q 15.6
Point out the error and suggest 3 solutions
A:
*/
    typedef struct node{
        int data;
        struct node *link;
    }*NODEPTR;

/*
Q 15.8
There is an error in the following declaration. Can u rectify it?
A:
*/
    printf("Q 15.8\n");

    typedef struct a *APTR;
    typedef struct b *BPTR;

    struct a{
        int data1;
        BPTR link1;
    };

    struct b{
        int data2;
        APTR link2;
    };

/*
Q 15.9
What do the following declarations mean?
A:
*/
    printf("Q 15.9\n");
    typedef char *pc;       //pc is pointer to a char
    typedef pc fpc();       //pc is function returning pointer to a char
    typedef fpc *pfpc;      //pfpc is a pointer to function returning pointer to char
    typedef pfpc fpfpc();   //fpfpc is a function returning pointer to a function returning pointer to a char
    typedef fpfpc *pfpfpc;  //pfpfpc is a pointer to function returning pointer to a function returning pointer to a
                            // function returning pointer to a char

    pfpfpc a[10];           //is an array of 10 pointers to function returning pointer to a function returning
                            //pointer to char
/*
Q 15.10
A:
*/
    printf("Q 15.10\n");
    char *(*(*vv[10])())();

    return 0;
}


int myFunc(char *a, char *b){
    printf("%s", a);
    printf("%s", b);
}

void testFunc(void){
    typedef struct{
        char *name;
        int age;
    }Tperson;

    Tperson p1;
    p1.name = "Anders";
    p1.age = 22;

    printf("%s %d\n", p1.name, p1.age);
}
