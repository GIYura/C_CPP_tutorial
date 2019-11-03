#include <stdio.h>
/*
1. "If the operand that has unsigned integer type has rank greater or equal to the rank of the type of the other operand,
 then the operand with signed integer type is converted to the type of the operand with unsigned integer type."

2. If an int can represent all values of the original type, the value is converted to an int; otherwise, it is converted to an unsigned int.
 * These are called the integer promotions. All other types are unchanged by the integer promotions.
*/
int main(int argc, char **argv)
{
	int i = -1;
	unsigned int j = 1;
	
	printf("i: %#x\n", i);
	printf("j: %#x\n", j);
	
	if(i < j){
		printf("i < j\n");
	} else {
		printf("i > j\n");
	}
	
	printf("-----------------------\n");
	
	unsigned char a = 0xff;
	char b = 0xff;
	
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	
	printf("c: %d\n", a == b);
	
	printf("-----------------------\n");
	
	char x = 0xfb;
	unsigned char y = 0xfb;
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	if(x == y){
		printf("x and y ARE the same\n");
	} else {
		printf("x and y ARE NOT the same\n");
	}
	
	printf("-----------------------\n");
	
	unsigned int c = 65535;
	c = c + 1;
	printf("C: %d\n", c);
	
	printf("-----------------------\n");
	
	long f = -1;
	
	printf("Value: %#x\n", f);

    if (f < sizeof(f)) {
		printf("OK\n");
    }
    else {
		printf("error\n");
    }
	
	return 0;
}
