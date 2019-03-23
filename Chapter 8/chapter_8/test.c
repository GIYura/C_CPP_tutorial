#include <stdio.h>

extern int COEFF_1;

void myFuncPrint(){
    printf("Hello from test file\n");
    printf("%d\n", COEFF_1+1);

    setVar(55);
}
