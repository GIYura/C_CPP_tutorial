/*
Chapter 7: Pointers (part 1)
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
/*
Q 7.1
Can u combine the following two statements into one?
A: Yes.
The malloc() function reserves a block of memory of the specified number of bytes.
And, it returns a pointer of type void which can be casted into pointer of any form.
*/
    printf("Q: 7.1\n");
    int *p = (int*)malloc(1000 * sizeof(int));

    if(NULL == p){
        printf("%s\n", "Can't allocate memory");
        return -1;
    }

    for(int i = 0; i < 10; ++i){
        *(p + i) = 10 * i;
        /*
            *p++ -  incorrect, because in this way the origina pointer is "moving" and
                    when print it the result is the memory after 10 elements.
                    And free(p) in this case also doesn't work, because try to free not the orignal pointer
        */
    }

    for(int i = 0; i < 10; ++i){
        printf("%d ", *(p + i));
    }
    printf("\n");
    free(p);

/*
Q 7.2
Can u split the following statement into two statements?
A: Yes.
This problem tests whether you know that it islegal to typecastan integer to a pointer
in order to access an absolute location. The exact syntax varies depending upon one's style.
However, Iwould typically be looking for something like this:
*/
    printf("Q: 7.2\n");
    char *src;
    src = (char *)0xB8000000L;
    printf("\n");
/*
Q 7.3
Are the expression *ptr++ and ++*ptr same?
A: No.
*ptr++ derefence the Pointer, then increment the Pointer
++*ptr derefence the Pointer, then increment th VALUE the pointer points to
*/
    printf("Q: 7.3\n");
    char *sPtr;
    char s[] = "Hello";
    sPtr = s;
    printf("%c ", *sPtr++);
    printf("%c ", ++*sPtr);
    printf("\n");
/*
Q 7.4
Can u write another expression which does the same job as ++*ptr?
A: *(ptr)++
*/
    printf("Q: 7.4\n");

/*
Q 7.5 What would be the equivalent pointer expression for refering the same element as a[i][j][k][l]?
A: *(*(*(*(a + i) + j) + k) + l)
*/
    printf("Q: 7.5\n");
/*
Q 7.6
What would be the output of the following program?

*/
    printf("Q: 7.6\n");
    int arr[] = {12,13,14,15,16};
    int *pArr = arr;
    printf("Size of CHAR = %d\n", sizeof(char));
    printf("Size of INT = %d\n", sizeof(int));
    printf("Size of ARR = %d\n", sizeof(arr));
    printf("Size of *CHAR = %d\n", sizeof(char*));
    printf("Size of *INT = %d\n", sizeof(int*));
    printf("Size of *pArr = %d\n", sizeof(pArr));
    printf("%d %d %d\n", sizeof(arr), sizeof(*arr), sizeof(arr[0]));

/*
Q 7.7
What would be the output of the following program assuming that the array begins at location 1002?
A: ???
*/
    printf("Q: 7.7\n");
    int a[3][4] = {
                    1,2,3,4,
                    5,6,7,8,
                    9,10,11,12
                };
    int x = a[0];
    int y = a[1];
    int y1 = a[2];

    /**/
    const int t = 10;
    printf("%d\n", t);
    int *pt = &t;
    *pt = 20;
    printf("%d\n", t);
    /*
    To make a pointer read only, just place the modifier const after the asterisk
    */
    int *const ptr = (int *)malloc(10 * sizeof(int));
    if(NULL == ptr){
        printf("Can't allocate memory\n");
        return - 1;
    }
    int var = 10;
    //ptr = &var;   //error: assigment of read-only location
    free(ptr);
    /*
    The following example makes the object pointed to by the pointer q read-only
    */
    int const *q = (int *)malloc(10 * sizeof(int));
    if(NULL == q){
        printf("Can't allocate memory\n");
        return - 1;
    }
    // *q = 10;     //error: assigment of read-only location
    free(q);

    printf("%u %u %u\n", a[0] + 1, *(a[0] + 1), *(*(a + 0) + 1));

/*
Q 7.8
What would be the output of the following program assuming that the array begins at location 1002?
A:???
*/
    printf("Q: 7.8\n");
    int array[2][3][4] =  {
                            {
                                1,2,3,4,
                                5,6,7,8,
                                9,10,11,12,
                                13,14,15,16
                            },
                            {
                                21,22,23,24,
                                25,26,27,28,
                                29,30,31,32,
                                33,34,35,36
                            }
                        };

    printf("%u %u %u %d\n", array, *array, **array, ***array);
/*
Q 7.9
In the following program how would u print 50 using p?
A:
*/
    printf("Q: 7.9\n");
    int arrt[] = {10,20,30,40,50};
    char *parrt;
    parrt = (char*)arrt;
    printf("%d\n", *((int*)parrt + 4));

/*
Q 7.10
Where can one think of using pointers?
A:
 - call by reference
 - dynamic memory allocation
*/
    printf("Q: 7.10\n");

/*
Q 7.11
In the following program add a statement in the funnction fun() such that address of a gets stored in j.
A:
*/
    printf("Q: 7.11\n");
    int *j;
    fun(&j);

/*
Q 7.12
How would u declare an array of 3 function pointers where each function receives 2 ints an return a float?

A: float (*func[3])(int, int);
*/
    printf("Q: 7.12\n");

/*
Q 7.13
Would the following program give an error or warning?
A: NO.
*/
    printf("Q: 7.13\n");
    float i = 10, *_j;
    void *k;
    k = &i;
    _j = k;
    printf("%.2lf\n", *_j);

/*
Q 7.14
Would the following program compile?
A: ???
*/
    printf("Q: 7.14\n");
    int _a = 10, *__j;
    void *_k;
    __j = _k = &_a;
    __j++;
    _k++;
    printf("%u %u", __j, _k);

/*
Q 7.15
Would the following code compile successfully?
A: Yes. Output is 'm'
*/
    printf("Q: 7.15\n");
    printf("%c\n", 7["Sundaram"]);
    return 0;
}

/**/

void fun(int **k){
    int a = 10;
    *k = &a;
}
