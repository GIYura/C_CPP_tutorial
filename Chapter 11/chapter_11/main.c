/*
Chapter 11 - Structures, Unions, Enumerations
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POINTS_NUMBER   10
#define NAME_LENGTH     32

typedef struct{
    int x;
    int y;
}TCoords;
TCoords point_1;
TCoords point_3[POINTS_NUMBER];

void setPoint(TCoords*, int, int);
TCoords getPoint();

typedef struct{
    char fName[NAME_LENGTH];
    char lName[NAME_LENGTH];
    int age;
}Tperson;

typedef struct student Tstudent;
struct student{
    char fName[NAME_LENGTH];
    char lName[NAME_LENGTH];
    int age;
    Tstudent *next;
};

struct emp{
    char name[20];
    int age;
};
void modify(struct emp*);

struct emp1{
    int len;
    char *name;
};
/*

*/
int main()
{
/*
Q 11.1
What is the similarity between a struct, union enum?
A: All of them let you define new data types
*/
    printf("Q 11.1\n");

/*
Q 11.2
Would the following declaration work?
A: yes
*/
    printf("Q 11.2\n");
    typedef struct s{
        int a;
        float b;
    }s;

/*
Q 11.3
Can a structure contains a pointer to itself?
A: yes
*/
    printf("Q 11.3\n");

/*
Q 11.4
Point out the error, if any, in the folloing code?
A: yes
*/
    printf("Q 11.4\n");

    typedef struct node *NODEPTR;
    struct node {
        int data;
        NODEPTR link;
    };
    printf("-------------------------------\n");
    setPoint(&point_1, 100, 200);
    printf("%d %d\n", point_1.x, point_1.y);

    printf("-------------------------------\n");
    TCoords point_2 = getPoint();
    printf("%d %d\n", point_2.x, point_2.y);

    for(int i = 0; i < POINTS_NUMBER; i++){
        point_3[i].x = i + 1;
        point_3[i].y = i + 2;
    }
    printf("-------------------------------\n");
    TCoords *point_4 = (TCoords*)malloc(sizeof(TCoords));
    if(NULL == point_4){
        printf("Can't allocate memory\n");
        return EXIT_FAILURE;
    }
    (*point_4).x = 56;
    point_4->y = 65;
    printf("%d %d\n", (*point_4).x, (*point_4).y);
    free(point_4);

    printf("-------------------------------\n");
    Tperson *person = (Tperson*)malloc(sizeof(Tperson) * 2);
    if(NULL == person){
        printf("Can't allocate memory\n");
        return EXIT_FAILURE;
    }
    strcpy(person[0].fName, "Julia");
    strcpy(person[0].lName, "Anders");
    person[0].age = 40;

    strcpy(person[1].fName, "Phil");
    strcpy(person[1].lName, "Richards");
    person[1].age = 43;

    for(int i = 0; i < 2; i++){
        printf("%s \t %s \t %d\n", person[i].fName, person[i].lName, person[i].age);
    }
    free(person);

    printf("-------------------------------\n");
    Tstudent *student_1 = (Tstudent*)malloc(sizeof *student_1);
    if(NULL == student_1){
        printf("Can't allocate memory\n");
        return EXIT_FAILURE;
    }
    strcpy(student_1->fName, "Peter");
    strcpy(student_1->lName, "Twister");
    student_1->age = 25;

    Tstudent *student_2 = (Tstudent*)malloc(sizeof *student_2);
    if(NULL == student_2){
        printf("Can't allocate memory\n");
        return EXIT_FAILURE;
    }

    student_1->next = student_2;

    strcpy(student_2->fName, "Michael");
    strcpy(student_2->lName, "Schumacher");
    student_2->age = 55;
    student_2->next = NULL;

    for(Tstudent *q = student_1; q != NULL; q = q->next){
        printf("First Name: %s\n", q->fName);
        printf("Last Name: %s\n", q->lName);
        printf("Age: %d\n\n", q->age);
    }
    printf("-------------------------------\n");
    free(student_1);
    free(student_2);
/*
Q 11.6
Point out the error, if any, in the following code.
A:
*/
    printf("Q 11.6\n");

    struct emp e = {"Santa", 22};
    printf("%s \t %d\n", e.name, e.age);
    modify(&e);
    printf("%s \t %d\n", e.name, e.age);

/*
Q 11.7
Would the following code work?
A:
*/
    printf("Q 11.7\n");
    char newName[] = "Ralf";
    struct emp1 *p = (struct emp1*)malloc(sizeof (struct emp1));   //(struct emp1*)malloc(sizeof(struct emp1) - 1 +
                                                                    //  strlen(newName) + 1);
    p->len = strlen(newName);
    p->name = malloc(p->len + 1);
    strcpy(p->name, newName);
    printf("%s %d\n", p->name, p->len);
    free(p->name);
    free(p);

/*
Q 11.11
What would be the output of the followinf program?
A:
*/
    printf("Q 11.11\n");

    struct emp3{
        char *n;
        int age;
    };
    struct emp3 E1 = {"Thomas", 55};
    struct emp3 E2 = E1;
    printf("%s %s\n", E1.n, E2.n);

/*
Q 11.12
Point out the error, if any
A:
*/
    struct emp4{
        char n[20];
        int age;
    };
    struct emp4 e4 = {"VASA", 22};
    struct emp4 e5 = e4;
    if(e4 == e5){
        printf("The structs are equal\n");
    }

    return 0;
}

/*

*/
void setPoint(TCoords *p, int newX, int newY){
    p->x = newX;
    p->y = newY;
}

TCoords getPoint(){
    TCoords t;
    t.x = 50;
    t.y = 20;
    return t;
}

void modify(struct emp *p){
    p->age = p->age + 2;
    strcpy(p->name, "Moon");
}
