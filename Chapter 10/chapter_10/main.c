/*
Chapter 10 - Strings

            Task                           Status
1. copy strings                         done
2. reverse chars in a given string      done
3. reverse words in a given string      done
4. count number of chars in a string    done
5. search a given char in a string      done
6. search a substr in the string        done
7. replace spaces with a given char     done
8. compare string                       done
9. concat 2 strings                     done
10. calculate strings                   not started
11. copy strings with sort              done
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void strCopy(char *, char *);           //1
int strLength(char *);                  //4
char *charReverseV1(char *);            //2.1
void charReverseV2(char *);             //2.2
int searchCharInStr(char *, char);      //5
void replaceSpaces(char *, char);       //7
bool searchSubStr(char *, char *);      //6
bool compareStr(char *, char *);        //8
char *concatStr(char *, char *);        //9
char *reverseWords(char *);             //3

char* copyWithSort(char *, char *);

typedef int (*pFunc)(int);
int myFunc(int);


int main()
{
    pFunc ptr = myFunc;
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
    strCopy(str8, str7);
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
/*






*/
    printf("\n\n\n");

    char *src = "Init string";
    char dst[strLength(src)];

    printf("String length: %d\n", strLength(src));
    printf("Source string: %s\n", src);
    strCopy(dst, src);
    printf("Destination string: %s\n", dst);

    char *msg_1 = "this is a string";
    printf("%s\n", msg_1);
    char *msg_2 = charReverseV1(msg_1);
    printf("%s\n", msg_2);
    free(msg_2);

    char msg_3[] = "Reverse";
    printf("%s\n", msg_3);
    charReverseV2(msg_3);
    printf("%s\n", msg_3);

    char *msg_4 = "abcdefghijklm";
    char ch2Found = 'v';
    printf("%s\n", msg_4);
    int pos = searchCharInStr(msg_4, ch2Found);
    if(pos >= 0){
        printf("Char %c Found at position %d", ch2Found, pos);
    } else {
        printf("Char %c NOT found\n", ch2Found);
    }

    char msg_5[] = "this is a string with spaces";
    printf("%s\n", msg_5);
    replaceSpaces(msg_5, '_');
    printf("%s\n", msg_5);
    printf("\n\n\n");

    char *msg_6 = "In this string u have to find substring";
    char subStr[] = "string";
    printf("Init string: %s\n", msg_6);
    if(searchSubStr(msg_6, subStr)){
        printf("Substring [%s] IS INSIDE string [%s]\n", subStr, msg_6);
    } else {
        printf("Substring [%s] IS NOT inside string [%s]\n", subStr, msg_6);
    }


    printf("1. %s\n", compareStr("String", "String") ? "EQUAL" : "NOT EQUAL");
    printf("2. %s\n", compareStr("Strang", "String") ? "EQUAL" : "NOT EQUAL");
    printf("3. %s\n", compareStr("String", "Strng") ? "EQUAL" : "NOT EQUAL");
    printf("4. %s\n", compareStr("Strng", "String") ? "EQUAL" : "NOT EQUAL");
    printf("5. %s\n", compareStr("String123", "123String") ? "EQUAL" : "NOT EQUAL");


    char *msg_7 = concatStr("Programming ", "Awesome");
    printf("%s\n", msg_7);
    free(msg_7);

    char *msg_8 = concatStr("Hello ", "World");
    printf("%s\n", msg_8);
    free(msg_8);

    char *msg_10 = concatStr("C", "++");
    printf("%s\n", msg_10);
    free(msg_10);

    char *msg_11 = concatStr("C ", "programming");
    printf("%s\n", msg_11);
    free(msg_11);

    char *msg_12 = "This is a string";
    printf("%s\n", msg_12);
    char *revMsg_12 = reverseWords(msg_12);
    printf("%s\n", revMsg_12);
    free(revMsg_12);

    char *msg_13 = "abcd efgh";
    printf("%s\n", msg_13);
    char *revMsg_13 = reverseWords(msg_13);
    printf("%s\n", revMsg_13);
    free(revMsg_13);

    char *msg_14 = "Hello world";
    printf("%s\n", msg_14);
    char *revMsg_14 = reverseWords(msg_14);
    printf("%s\n", revMsg_14);
    free(revMsg_14);

    char msg_15[] = "1928374650";
	char* msg_16 = NULL;

	if (msg_16 = copyWithSort(msg_16, msg_15))
	{
		printf("%s\n", msg_15); //str1
		printf("%s\n", msg_16); //str2
	}
	else
	{
		printf("Error in copyWithSort function");
	}

	if (NULL != msg_16)
	{
		free(msg_16);
    }

    char *msg_17 = "Message 17";
    printf("%s = %d\n", msg_17, strLength(msg_17));
    printf("%s\n", msg_17);

    int gg = 10;
    printf("%d\n", gg);
    gg = (*ptr)(gg);
    printf("%d\n", gg);

    return EXIT_SUCCESS;
}

/*******************************************************
                    FUNCTIONS
********************************************************/
/*String copy*/
void strCopy(char *d, char *s){
    while(*d++ = *s++);
}
/*Count string length*/
int strLength(char *s){
    int c = 0;
    while(*s++){
        c++;
    }
    return c;
}
/*Reverse char in a string Version 1*/
char* charReverseV1(char *s){
    int c = 0;
    while(*s){
        c++;
        s++;
    }
    s--;

    char *res = (char *)malloc(sizeof(char) * (c + 1));
    if(NULL == res){
        printf("Can't allocate memory\n");
        return -1;
    }
    char *p = res;
    while(c--){
        *p++ = *s--;
    }
    *p = '\0';
    return res;
}

/*Reverse char in a string Version 2*/
void charReverseV2(char *s){
    //int c = strlen(s);
    int c = 0;
    int i = 0;
    while(s[i++] != '\0'){
        c++;
    }

    for(int i = 0; i < c/2; i++){
        char ch = s[i];
        s[i] = s[c - i - 1];
        s[c - i - 1] = ch;
    }
}

/*Search first char in a string*/
int searchCharInStr(char *s, char ch){
    int position = -1;
    char *st = s;

    while(*st){
        if(*st == ch){
            position = st - s;
            break;
        }
        st++;
    }
    return position;
}

/*Replace spaces*/
void replaceSpaces(char *s, char ch){
    while(*s){
        if(*s == ' '){
            *s = ch;
        }
        s++;
    }
}

/*Search substring in a string*/
bool searchSubStr(char *str, char *subStr){
    bool res = false;

    char *p = subStr;

    while( (*str) && (*subStr != '\0') ){
        if( (*str == *subStr) ){
            subStr++;
        } else {
            subStr = p;
        }
        str++;
    }

    if(subStr != p){
        res = true;
    }

    return res;
}

/*compare strings*/
bool compareStr(char *a, char *b){
    bool res = false;
    int lenA = strlen(a);
    int lenB = strlen(b);

    if(lenA != lenB){
        return res;
    }

    for(int i = 0; i < lenA; i++){
        if(*a++ == *b++){
            //a++;
            //b++;
        } else {
            return res;
        }
    }

    res = true;
    return res;
}

/*concatenation of 2 strings*/
char *concatStr(char *s1, char *s2){

    char *res = malloc(strlen(s1) + strlen(s2) + 1);
    if(NULL == res){
        printf("Can't allocate memory\n");
        return -1;
    }

    char *p = res;

    while(*s1){
        *p++ = *s1++;
    }

    while(*s2){
        *p++ = *s2++;
    }
    *p = '\0';
    return res;
}

/*reverse words*/
char *reverseWords(char *s){
    int c = 0;
    while(*s){
        c++;
        s++;
    }
    s--;

    char *res = malloc(sizeof(char) * (c + 1));
    if(NULL == res){
        printf("Can't allocate memory\n");
        exit(0);
    }
    char *p = res;
    char *st = s;
    char *t = s;
    int count = c;

    while(c >= 0){
        if( (*st == ' ') || (c == 0) ){
            t = st;
            st++;
            count -= c;
            for(int i = 0; i <= count; i++){
                *p++ = *st++;
            }
            count = c;
            st = t;
            p--;
            *p++ = ' ';
            count--;
        }
        st--;
        c--;
    }
    *p = '\0';
    return res;
}

/**/
char* copyWithSort(char *dst, char *src){

    int l = strlen(src);
    dst = malloc(sizeof(char) * (l + 1));


    if(NULL == dst){
        printf("Can't allocate memory\n");
        return -1;
    }
    char *t = dst;

    while(*t++ = *src++);
    *t = '\0';

    for(int i = 0; i < l - 1; i++){
        for(int j = 0; j < l - i - 1; j++){
            if(dst[j] > dst[j + 1]){
                char ch = dst[j];
                dst[j] = dst[j + 1];
                dst[j + 1] = ch;
            }
        }
    }
    return dst;
}

/**/
int myFunc(int a){
    int b = a;
    return ++b;
}
