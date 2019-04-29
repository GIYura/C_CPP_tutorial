/*
Chapter 12 - Input/output
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){
/*
Q 12.1
What would be the output of he following code?
A:
*/
    printf("Q 12.1\n");
    int a = 250;
    printf("%1d\n", a);

/*
Q 12.2
What would be the output of he following code?
A:
*/
    printf("Q 12.2\n");
    float b = 3.15429;
    printf("1. %6.2f\n", b);
    printf("2. %6.3f\n", b) ;
    printf("3. %5.4f\n", b);
    printf("4. %2.1f\n", b);
    printf("5. %0.0f\n", b);

/*
Q 12.3
In the following code pf points to?
A: A structure which contains a char pointer which points to the first character in the file
*/
    printf("Q 12.3\n");
    FILE *pf = fopen("trial.txt", "w+");
    fprintf(pf, "Test...\n");
    fclose(pf);

/*
Q 12.4
Point out the error, if any, in the following program.
A:
*/
    printf("Q 12.4\n");
    int c;
    FILE *fptr = fopen("trial.txt", "r");
    while((c = fgetc(fptr)) != EOF){
        printf("%c ", c);
    }
    printf("\n");
    fclose(fptr);

/*
Q 12.6
Point out the error, if any, in the following program.
A:
*/
    printf("Q 12.5\n");
    char str[60];
    FILE *fp = fopen("trial.txt", "r");
    if(NULL == fp){
        printf("Can't open file\n");
        return EXIT_FAILURE;
    }
    printf("%s\n", fgets(str, 10, fp));

/*
Q 12.8
To print out a and b given below, which printf would use?
A:
    printf:

    %f -> double
    %Lf -> long double.
*/
    printf("Q 12.8\n");
    float x = 3.14;
    double y = 3.14;
    long double z = 3.14;
    printf("%f %f\n", x, y);
    printf("%f %lf\n", x, y);
    printf("%f %Lf\n", x, z);

/*
Q 12.9
To print out a and b given below, which printf would use?
A:
    scanf:

    %f -> float
    %lf -> double
    %Lf -> long double.
*/
    printf("Q 12.9\n");
    float m;
    double n;
    //scanf("%f %lf", &m, &n);
    printf("m = %f n = %lf;\n", m, n);

/*
Q 12.10
Point out the error in the following code/
A:
*/
    printf("Q 12.10\n");
    FILE *p_File;
    char s_s[100];

    p_File = fopen("test.txt", "r");

    if(NULL == p_File){
        printf("File doesn't exist\n");
        return EXIT_FAILURE;
    }

    while(!feof(p_File)){
        fgets(s_s, 100, p_File);
        puts(s_s);
    }
    fclose(p_File);

/*
Q 12.11
Piont out the error in the following code/
A:
*/
    printf("Q 12.11\n");
    int i1;
    char ch1;
    scanf(" %d", &i1);
    scanf(" %c", &ch1);
    printf("%c %d\n", ch1, i1);

/*
Q 12.12
What would be the output of the following code?
A:
*/
    printf("Q 12.12\n");
    printf("%%%\n");

/*
Q 12.14
What would be the output of the following code?
A:
*/
    printf("Q 12.14\n");
    int t = 5;
    printf("t = %*d", t,t);



    return 0;
}
