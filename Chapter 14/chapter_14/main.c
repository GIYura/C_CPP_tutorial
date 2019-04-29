/*
Chapter 14 - Bitwise operators
*/
/*              Tasks                                       Status
1. set bit in the given byte                                done
2. clear bit in the given byte                              done
3. inverse bit in the given byte                            done
4. output bits in reverse order in the given byte           done
5. MACRO (SET, CLR, XOR, NOT, CHECK)                        done
6. check endianess                                          done
7. check if a number is odd or even (function and MACRO)    done
8. swap 2 numbers using bitwise operation                   done
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define BITS_NUMBER(x)  (x * 8) - 1
#define SET_BIT(x, y)   x |= 1 << y
#define CLR_BIT(x, y)   x &= ~(1 << y)
#define INV_BIT(x, y)   x ^= (1 << y)
#define ODD_EVEN(x)     (x & 1)


int reverseBits(int );
bool endianess(int );
int setBit(int, int );
int clearBit(int, int );
int invBits(int );
bool oddEven(int );
void swap(int* , int* );

int main()
{
/*
Q 14.1
What would be the output of the following program?
A:
*/
    static int _Y[4];
    printf("Q 14.1\n");

    int i = 32, j = 0x20, k, l, m;
    k = i | j;
    l = i & j;
    m = k ^ l;

    printf("%d %d %d %d %d\n", i, j, k, l, m);

/*
Q 14.2
What would be the output of the following program?
A:
*/
    printf("Q 14.2\n");
    unsigned int x = 1;
    printf("Signed: %d\n", ~x);
    printf("Unsigned: %u\n", ~x);

/*
Q 14.3
What would be the output of the following program?
A:
*/
    printf("Q 14.3\n");
    unsigned int y = 0xffff;
    ~y;
    printf("%x\n", y);

/*
Q 14.4
Point out error in the following program?
A:
*/
    printf("Q 14.4\n");
    unsigned int a,b,c,d,e,f;
    a = b = c = d = e = f = 32;
    a <<= 2;
    b >>= 2;
    c ^= 2;
    d |= 2;
    e &= 2;
    //f ~= 2;
    printf("%x %x %x %x %x %x\n", a,b,c,d,e,f);

/*
Q 14.5
A:
*/
    printf("Q 14.5\n");

/*
Q 14.6
Which bitwise operation is suitable for checking whether a particular bit is on or off?
A: & bitwise AND
*/
    printf("Q 14.6\n");
    int p = 0xaa;
    for(int i = 0; i < 8; i++){
        p & (1 << i) ? printf("Bit[%d] '1'", i) : printf("Bit[%d] '0'", i);
        printf("\n");
    }

/*
Q 14.7
Which bitwise operation is suitable for turnig OFF a particular bit in the number?
A: & bitwise AND
*/
    printf("Q 14.7\n");
    int r = 0x01;
    printf("%#x\n", r);
    r &= ~(1 << 0);
    printf("%#x\n", r);

/*
Q 14.8
Which bitwise operation is suitable for turnig ON a particular bit in the number?
A: | bitwise OR
*/
    printf("Q 14.8\n");
    int u = 0x00;
    printf("%#x\n", r);
    r |= (1 << 0);
    printf("%#x\n", r);

/*
Q 14.10
Left shift a number by 1 is always equivalent to multiplying it by 2?
A: NO
*/
    printf("Q 14.10\n");
    unsigned char h = 0x20;
    printf("%#x\n", h);
    h <<= 1;
    printf("%#x\n", h);

/*
Q 14.12
What would be the output of the following program?
A:
*/
    printf("Q 14.12\n");
    unsigned char ch = 0x80;
    printf("%d\n", ch << 1);
    printf("%#x %#x\n", CHAR_MIN, CHAR_MAX);


    int test1 = 0x0002;
    printf("test1 = %#x\n", test1);
    printf("Inv test1 = %x\n", reverseBits(test1));

    int test2 = 1;
    endianess(test2) ? printf("Little endian\n") : printf("Big endian\n");

    int test3 = 0x00000000;
    printf("%#x\n", test3);
    printf("%#x\n", setBit(test3, 0));
    printf("%#x\n", setBit(test3, 15));
    printf("%#x\n", setBit(test3, 31));

    test3 = 0xFFFFFFFF;
    printf("%#x\n", clearBit(test3, 0));
    printf("%#x\n", clearBit(test3, 15));
    printf("%#x\n", clearBit(test3, 31));

    int test4 = 0x00000000;
    printf("%#x\n", SET_BIT(test4, 3));
    test4 = 0x80000000;
    printf("%#x\n", CLR_BIT(test4, 31));

    int test5 = 0;
    printf("%#x\n", INV_BIT(test5, 0));
    test5 = 1;
    printf("%#x\n", INV_BIT(test5, 0));

    int test6 = 0x5555aaaa;
    printf("%#x\n", invBits(test6));
    printf("********************************\n");
    printf("********************************\n");
    printf("********************************\n");

    int _u;
    printf("Print positive number 0 - 9\n");
    scanf("%d", &_u);

    if(oddEven(_u)){
        printf("%d = %s\n", _u, "Odd");
    } else {
        printf("%d = %s\n", _u, "Even");
    }

    if(ODD_EVEN(_u)){
        printf("%d = %s\n", _u, "Odd");
    } else {
        printf("%d = %s\n", _u, "Even");
    }

    int y1 = 45;
    int y2 = 12;
    printf("y1 = %d y2 = %d\n", y1, y2);
    swap(&y1, &y2);
    printf("y1 = %d y2 = %d\n", y1, y2);



    return 0;
}

/*

*/
/*Inverse bits function*/
int reverseBits(int a){
    int res = 0;
    char b = BITS_NUMBER(sizeof(a));

    for(int i = 0; i < b; i++){
        if(a & (1 << i)){
            res |= 1;
        }
        res = res << 1;
    }
    return res;
}

/*Check whether sysyem Big or Little Endian*/
bool endianess(int a){
    char *p = (char *)&a;
    return *p ? true : false;
}

/*set particular bit in the int*/
int setBit(int byte, int bit){
    return byte |= 1 << bit;
}

/*clear particular bit in the int*/
int clearBit(int byte, int bit){
    return byte &= ~(1 << bit);
}

/*invert all bits in a given byte*/
int invBits(int b){
    return (b ^ 0xFFFFFFFF);
}

/**/
bool oddEven(int a){
    return a & 1 ? true : false;
}

/**/
void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
