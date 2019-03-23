/*
Chapter 10 - Strings
*/

#include <stdio.h>
#include <stdlib.h>

void strcpy(char *, char *);

int main()
{
/*
Q 10.1
What would be the output of the following program?
A: mile
*/
    printf("Q 10.1\n");
    printf(5 + "Fascimile\n");

/*
Q 10.2
What would be the output of the following program?
A: NOT Equal
*/
    printf("Q 10.2\n");
    char str1[] = "Hello123";
    char str2[] = "Hello456";
    if(str1 == str2){
        printf("EQual\n");
    } else {
        printf("NOT EQual\n");
    }

/*
Q 10.3
What would be the output of the following program?
A:
*/
    printf("Q 10.3\n");
    printf("%c\n", "abcdefgh"[4]);

/*
Q 10.4
What would be the output of the following program?
A:
*/
    printf("Q 10.4\n");
    char str3[7] = "Strings";
    printf("%s\n", str3);

/*
Q 10.5
How would u output \n on the screen?
A:
*/
    printf("Q 10.5\n");
    printf("\\n");

/*
Q 10.6
What would be the output of the following program?
A:
*/
    printf("\nQ 10.6\n");
    char ch = 'A' + 255;
    printf("%c\n", ch);
    printf("%d %d\n", sizeof(ch), sizeof('A'));
    printf("%d %d %d\n", sizeof('3'), sizeof("3"), sizeof(3));

/*
Q 10.8
Is the following code correct?
A:
*/
    printf("Q 10.8\n");
    char str4[20] = "United";
    char *str5 = "Front";
    char *str6;
    str6 = strcat(str4, str5);
    printf("%s\n", str6);

/*
Q 10.10
In the following code which func would get colled the user-defined of in the standard library?
A:
*/
    char str7[] = "Keep India beautiful ...";
    char str8[40];
    strcpy(str8, str7);
    printf("%s\n", str8);

    char str9[] = {'a', 'b', 'c', 'd', '\0'};
    int sz = strlen(str9);
    printf("%s %d\n", str9, sz);

    struct st{
        char c;
        int i;
    };

    struct st1{
        char c;
        int i;
    };

    struct st s;
    s.c = 10;
    s.i = 11;
    printf("%3d %3d %3d\n", s.c, s.i, sizeof(s));

    struct st1 s1;
    s1.c = 5;
    s1.i = 22;
    printf("%3d %3d %3d\n", s1.c, s1.i, sizeof(s1));

    union u{
        int i;
        char c[5];
    };
    union u u1;
    printf("%d\n", sizeof(u1));

/*
Q 10.12
What would be the output of the following program?
A:
*/
    printf("Q 10.12\n");
    char *str10[] = {"Frogs", "Do", "Not", "Die", "They", "Croak"};
    int u = sizeof(str10);
    int u12 = sizeof(str10[0]);
    printf("%d %d\n", sizeof(str10), sizeof(str10[0]));

/*
Q 10.13
How would u find the length of each string in 10.12?
A:
*/
    printf("Q 10.13\n");
    for(int i = 0; i < 6; i++){
        printf("%d ", strlen(str10[i]));
    }
    printf("\n");

/*
Q 10.14
What is the difference in the following declaration?
A:
*/
    printf("Q 10.14\n");

    char a[] = "Samuel";
    char *p = "Samuel";

    a[0] = 'F';

    printf("%s %s\n", a, ++p);

    char bbb = 'B';
    printf("%d %d\n", sizeof(bbb), sizeof('B'));

    return EXIT_SUCCESS;
}


void strcpy(char *d, char *s){
    while(*d++ = *s++);
}
