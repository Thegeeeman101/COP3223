//finalproject
//Group members: Jason Gouws, Griffin Morgan, David Jerome

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//--------------------------

struct student
{
    char fullName[50];
    char id[50];
    float gpa;
    int creditHour;
    struct student * next;
};

struct faculty
{
    char fullName[50];
    char id[50];
    char department[10];
    char rank[10];
    struct faculty * next;
};

//--------------------------

int menu();
struct faculty * addfaculty ( struct faculty * list , struct faculty f);
struct student * addstudent ( struct student * list , struct student s);
void faculty();
void student();
void printinvoice();
void printfacultyinfo();
void quit();

//--------------------------

int main()
{
    menu();
    return 0;
}

//--------------------------

int menu()
{
    int option;
    printf("Choose one of the options:\n" );
    printf("\n");
    printf("1- Add a new faculty member\n");
    printf("2- Add a new student\n");
    printf("3- Print tuition invoice for a student\n");
    printf("4- Print information of a faculty\n");
    printf("5- Exit Program\n");
    printf("\n");
    printf("\tEnter your selection: ");
    scanf("%d", &option);
    switch(option)
    {
        case 1: 
            faculty();
            break;
        case 2:
            student();
            break;
        case 3:
            printinvoice();
            break;
        case 4:
            printfacultyinfo();
            break;
        case 5:
            quit();
            break;
        default:
            while(option > 5 || option < 1)
            {
                printf("\tInvalid entry- please try again.\n");
                printf("\tEnter your selection: ");
                scanf("%d", &option); 
            }
    }
    return 0;
}