/* Application
Read file entered by user and print to console
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    char ch;

    if(argc != 2){
        printf("Please, enter file name\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if(NULL == fp){
        printf("Can't open file\n");
    }

    while( (ch = fgetc(fp)) != EOF ){
        printf("%c ", ch);
        //putc(ch, stdout);
    }
    printf("\n");
    return 0;
}
