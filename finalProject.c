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

int menu(); //opens menu with options
struct faculty * addfaculty ( struct faculty * list , struct faculty f); //add faculty struct to list
struct student * addstudent ( struct student * list , struct student s); //add student struct to list
void faculty(); //opens option to add faculty
void student(); //opens option to add faculty
void printinvoice(); //opens option to print student tuition
void printfacultyinfo(); //opens option to print faculty information
void quit(); //opens option to quit program

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

struct faculty * addfaculty(struct faculty * list , struct faculty f )
{
    struct faculty * current = list;

    while (current != NULL) {
        if (strcmp(current->id, f.id) == 0) {
            struct faculty * newNode = malloc(sizeof(struct faculty));
            strcpy(newNode->fullName, f.fullName);
            strcpy(newNode->id, f.id);
            strcpy(newNode->department, f.department);
            strcpy(newNode->rank, f.rank);
            newNode->next = NULL;
            return list;
        }
        current = current->next;
    }
    struct faculty * newNode = malloc( sizeof (struct faculty) );
        strcpy(newNode->fullName, f.fullName);
        strcpy(newNode->id, f.id);
        strcpy(newNode->department, f.department);
        strcpy(newNode->rank, f.rank);
        newNode->next = list;
        return newNode;
}
struct student * addstudent ( struct student * list, struct student s)
{
    struct student * current = list;

    while (current != NULL) {
        if (strcmp(current->id, s.id) == 0) {
            struct student * newNode = malloc(sizeof(struct student));
            strcpy(newNode->fullName, s.fullName);
            strcpy(newNode->id, s.id);
            newNode->gpa = s.gpa;
            newNode->creditHour = s.creditHour;
            newNode->next = NULL;
            return list;
        }
        current = current->next;
    }
    struct student * newNode = malloc( sizeof (struct student) );
        strcpy(newNode->fullName, s.fullName);
        strcpy(newNode->id, s.id);
        newNode->gpa = s.gpa;
        newNode->creditHour = s.creditHour;
        newNode->next = list;
        return newNode;

}
void faculty ()
{
        struct faculty * company = NULL , tempFaculty;
        char name;
        printf("Enter Full Name: ");
        fgets(tempFaculty.fullName, 50, stdin);
        printf ("Enter Faculty ID: ");
        fgets (tempFaculty.id, 50, stdin);
        printf ("Enter Department: ");
        fgets (tempFaculty.department, 10, stdin);
        printf ("Enter Rank: ");
        fgets (tempFaculty.rank, 10, stdin);
        company = addFaculty ( company , tempFaculty);
}
void student()
{
    struct student * company = NULL , tempStudent;
        char name;
        printf("Enter Full Name: ");
        fgets(tempStudent.fullName, 50, stdin);
        printf ("Enter Faculty ID: ");
        fgets (tempStudent.id, 50, stdin);
        printf ("Enter GPA ");
        scanf("%f", &tempStudent.gpa);
        printf ("Enter Credit Hours: ");
        scanf("%d", &tempStudent.creditHour);
        company = addStudent ( company , tempStudent);
}

void printinvoice()
{

}

void printfacultyinfo()
{

}

void quit()
{

}
