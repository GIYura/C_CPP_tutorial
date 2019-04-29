/*
Chapter 13 - Command line arguments
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *env[])
{
/*
Q 13.1
What do the 'c' and 'v' in argc and argv stand for?
A:  'argc' - argument counter. contains the number of arguments passed to the program
    'agrv' - argument vactor. vecto is a one-dimensional array of strings.
*/
    printf("Q 13.1\n");

    /*if(argc > 1){
        *argv++;
        for(int i = 1; i < argc; i++){
            printf("argv[%d] = %s\n", i, *argv++);
        }
    } else {
        printf("Not enough params\n");
    }*/

/*
Q 13.6
What would be the output of the following code
A: error
*/
    printf("Q 13.6\n");
    /*int i;
    i = argv[1] + argv[2] + argv[3];
    printf("%d\n", i);*/

/*
Q 13.7
What would be the output of the following code
A:
*/
    /*printf("Q 13.7\n");
    int i, res;
    for(i = 0; i < argc; i++){
        res = res + atoi(argv[i]);
    }
    printf("%d\n", res);
    */

/*
Q 13.10
What would be the output of the following code
A:
*/
    printf("Q 13.10\n");
/*
    printf("%s\n", *++argv);
    printf("%c\n", ++**++argv);
*/
/*
Q 13.13
What would be the output of the following code
A:
*/
    printf("Q 13.13\n");
    /*for(int i = 1; i < argc; i++){
        printf("%s ", argv[i]);
    }*/

/*
Q 13.22
What would be the output of the following code
A:
*/
    printf("Q 13.22\n");

    /*while(--argc > 0){
        printf("%s ", *++argv);
    }
    printf("\n");
    */

/*
Q 13.23
What would be the output of the following code
A:
*/
    printf("Q 13.23\n");
    printf("%c ", (*++argv)[0]);
    return 0;
}
