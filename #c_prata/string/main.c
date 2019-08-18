#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int a;
    int b;
    int c[10];
}st_t;

void function(char* ch);

void function_1(st_t* );

char* reverse(char*);

char** search(char*, char);

int main()
{
    char* str = "Hello world";
    function(str);
    puts(str);

    st_t test = {0,0,{1,2,3}};
    function_1(&test);

    char note[] = "See you in cafe tomorrow";
    char *ptr;

    ptr = note;
    puts(ptr);
    puts(++ptr);
    note[7] = '\0';
    puts(ptr);
    puts(++ptr);

    char food[] = "Bon apetit";
    char* ptr_1;

    ptr_1 = food + strlen(food);
    while(--ptr_1 >= food){
        putchar(*ptr_1);
    }

    puts(reverse("hello"));

    printf("\n");
    char* string = "Hello world";
    char cs = 'w';
    char* p = search(string, cs);

    printf("%c ", *p);



    return 0;
}

void function(char* ch){
    while(*ch){
        putchar(*ch++);
    }
}

void function_1(st_t* t){
    printf("%d\n", *(t->c));
    printf("%d\n", *t->c+1);
    printf("%d\n", *t->c+2);


}

char* reverse(char* s){
    char* res = "Hello";

    return res;
}

char** search(char* s, char c){


    for( ; *s; ++s ) {
        if( *s == c ) break;
    }
    //printf("%c", *s);
    return (char*)s;

}
