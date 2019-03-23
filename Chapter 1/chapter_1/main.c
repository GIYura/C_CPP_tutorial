/*
Chapter 1: Declaration & Initialization
*/

#include <stdio.h>
#include <stdlib.h>


 struct emp_{
        char name[20];
        int age;
    };

void f(struct emp_);

int x = 40;

int func(void);

int main()
{
/*
Q 1.1
What would be the output of the following program?
A: sizeof pointer depends on the system architecture. 64 bit - sizeof = 8 byte, 32 bit - sizeof = 4 byte
*/
    printf("Q 1.1\n");
    char *s1, *s2;
    printf("%d %d\n", sizeof(s1), sizeof(s2));

/*
Q 1.2
What would be the output of the following program?
A: Global and local vars
*/
    printf("Q 1.2\n");
    int x = 20;
    printf("%d\n", x);

/*
Q 1.3
What would be the output of the following program?
A: In case of a conflict between local vars, the once which is more local that gets the priority
*/
    printf("Q 1.3\n");
    int y = 40;
    {
        int y = 20;
        printf("%d\n", y);
    }
    printf("%d\n", y);

/*
Q 1.4
Is the following statement a declaration or difinition?
    extern int i;
A: Declaration
*/
    printf("Q 1.4\n");

/*
Q 1.5
What would be the output of the following program?
A: Error, undefined reference to i
*/
    printf("Q 1.5\n");
    extern int i;
    //i = 20;
    printf("%d\n", sizeof(i));

/*
Q 1.6
Is it true that global vars may have several declarations, but only one definition?
A: Yes
*/
    printf("Q 1.6\n");

/*
Q 1.7
Is it true that function may have several declarations, but only one definition?
A: Yes
*/
    printf("Q 1.7\n");

/*
Q 1.8
In the following program where is the var a getting defined and where is getting declared?
A:
*/
    printf("Q 1.8\n");
    extern int a;           //declaration
    printf("%d\n", a);

/*
Q 1.9
What would be the output of the following program
A:
*/
    printf("Q 1.9\n");
    extern int b;           //declareation
    printf("%d\n", b);

/*
Q 1.10
What is the difference bertween a definition and declaration of a variable?
A:  Declaration - specify type and name of a var (no memory allocation)
    Definition - memory allocation and value
*/
    printf("Q 1.10\n");
/*
Q 1.11
If the definition of an external var occurs in the source file before its use in a particular function,
then there is no need for an external declaration in the function?
A: TRUE.
*/
    printf("Q 1.11\n");

/*
Q 1.12
A:
*/
    printf("Q 1.12\n");

/*
Q 1.13
A:
*/
    printf("Q 1.13\n");

/*
Q 1.14
A:
*/
    printf("Q 1.14\n");

/*
Q 1.15
Why does the following program report a redeclaration error of func display()?
A: display() used before declaration
*/
    printf("Q 1.15\n");
    display();

/*
Q 1.16
What would be the output of the following program
A:
*/
    printf("Q 1.16\n");
    extern int fun(float);
    int s;
    s = fun(3.14);
    printf("%d\n", s);

/*
Q 1.17
Point out the error, if any, in the following program
A: There is no ';' after struct
*/
    printf("Q 1.17\n");
    struct emp{
        char name[20];
        int age;
    };

    int funn(int aa){
        int bb;
        bb = aa * aa;
        return (bb);
    }

    int yy;
    yy = funn(20);
    printf("%d\n", yy);

/*
Q 1.18
A:
*/
    printf("Q 1.18\n");

/*
Q 1.19
How would u rectify the error in the following program?
A: declare the struct before prototype
*/
    printf("Q 1.19\n");
    struct emp_ e = {"Peter", 34};
    f(e);

/*
Q 1.20
A:
*/
    printf("Q 1.20\n");

/*
Q 1.21
A:
*/
    printf("Q 1.21\n");

/*
Q 1.22
What would be the output of the following program?
A: 0 0 0
*/
    printf("Q 1.22\n");
    int arr[5] = {2,3};
    printf("%d %d %d\n", arr[2], arr[3], arr[4]);

/*
Q 1.23
What would be the output of the following program?
A: 0 0
*/
    printf("Q 1.23\n");

    struct empP{
        char name[20];
        int age;
        float sal;
    };
    struct empP ee = {"Tiger"};
    printf("%d %f\n", ee.age, ee.sal);

/*
Q 1.24
A:
*/
    printf("Q 1.24\n");

/*
Q 1.25
Point out the error, if any, in the following program
A: ????
*/
    printf("Q 1.25\n");
    int (*pF)(void) = func;
    (*pF)();

/*
Q 1.26
Point out the error, if any, in the following program
A: 255 255
*/
    printf("Q 1.26\n");

    union U{
        int i;
        char c[2];
    };

    union U zz;
    printf("%d %d\n", zz.c[0], zz.c[1]);

/*
Q 1.27
What do u mean by the scope of a var? What are the 4 different type of scopes that a var can have?
A:  - file
    - block
    - function
    - protptype
*/
    printf("Q 1.27\n");

/*
Q 1.28
What are the different type of linkage?
A: external, internal, none
*/
    printf("Q 1.28\n");


    return 0;
}
/*
========================================================================================
========================================================================================
========================================================================================
*/
    int a = 20;            //definition
    int b = 29;            //definition

void display(void)
{
    printf("Hi\n");
}

int fun (float aa)
{
    return ((int)aa);
}

void f(struct emp_ ee){
    printf("%s %d\n", ee.name, ee.age);
}

int func(void){
    printf("HiHI\n");
    return 0;
}
