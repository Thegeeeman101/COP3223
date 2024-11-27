//finalproject
//Group members: Jason Gouws, Griffin Morgan, David Jerome

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

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

int menu(struct faculty * list, struct student * list2); //opens menu with options
struct faculty * addfaculty ( struct faculty * list , struct faculty f); //add faculty struct to list
struct student * addstudent ( struct student * list , struct student s); //add student struct to list
void toUpperCase();
void faculty(); //opens option to add faculty
void student(); //opens option to add faculty
void printinvoice(); //opens option to print student tuition
void printfacultyinfo(); //opens option to print faculty information
void quit(); //opens option to quit program
void terminate();

//--------------------------

int main()
{
    struct student * students = NULL;
    struct faculty * facultys = NULL;
    printf("\t\tWelcome to PerPro\n");
    printf("\n");
    menu(facultys, students);
    return 0;
}

//--------------------------

int menu(struct faculty * list, struct student * list2)
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
            faculty(list, list2);
            break;
        case 2:
            student(list, list2);
            break;
        case 3:
            printinvoice(list, list2);
            break;
        case 4:
            printfacultyinfo(list, list2);
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

void toUpperCase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
        if(str[i] == '\n')
        {
            str[i] = '\0';
        }
    }
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

void faculty (struct faculty * list, struct student * list2)
{
    int i;
    int j;
    char dummy;
    int department;
    int rank;
    struct faculty * facultys = list , tempFaculty;
    printf("\n");
    printf("Enter the faculty's info:\n");
    printf("Name of the faculty: ");
    scanf("%c",&dummy);
    fgets(tempFaculty.fullName, 50, stdin);
    toUpperCase(tempFaculty.fullName);
    printf ("ID: ");
    fgets (tempFaculty.id, 50, stdin);
    toUpperCase(tempFaculty.id);

    do{
        if ( j == 3)
        {
            printf("You have tried too many times...");
            terminate();//THROW THE EXIT FUNCTION HERE
        }
        printf ("Rank: ");
        fgets (tempFaculty.rank, 10, stdin);
        toUpperCase(tempFaculty.rank);
        if (strcmp(tempFaculty.rank, "PROFESSOR") == 0 || strcmp(tempFaculty.department, "ADJUNCT") == 0) rank = 1;
        else
        {
            printf("Sorry entered rank (%s) is invalid. Try again.\n", tempFaculty.rank);
            rank = 0;
            j++;
        }
    }while(!rank);

     do{
        if ( i == 3)
        {
            printf("You have tried too many times...");
            terminate();//THROW THE EXIT FUNCTION HERE
        }
    
        printf ("Department: ");
        if(i == 0)
        {
            scanf("%c", &dummy);
        }
        fgets (tempFaculty.department, 10, stdin);
        toUpperCase(tempFaculty.department);

        if (strcmp(tempFaculty.department, "MATH") == 0 || strcmp(tempFaculty.department, "CS") == 0 || strcmp(tempFaculty.department, "SCIENCE") == 0) department = 1; 
        else 
        {
            printf("Sorry entered department (%s) is invalid. Try again.\n", tempFaculty.department);
            department = 0;
            i++;
        }
    }while(!department);

    facultys = addfaculty ( facultys, tempFaculty);
    printf("\n");
    printf("Thanks!");
    menu(facultys, list2);
}

void student(struct faculty * list2, struct student * list)
{
    char dummy;
    struct student * students = list , tempStudent;
    printf("\n");
    printf("Enter the student's info:\n ");
    printf("Name of Student: ");
    scanf("%c",&dummy);
    fgets(tempStudent.fullName, 50, stdin);
    toUpperCase(tempStudent.fullName);
    printf ("ID: ");
    fgets (tempStudent.id, 50, stdin);
    printf ("Gpa: ");
    scanf("%f", &tempStudent.gpa);
    printf ("Credit hours: ");
    scanf("%d", &tempStudent.creditHour);
    students = addstudent ( students , tempStudent);
    printf("\n");
    printf("Thanks!");
    menu(list2, students);
}

void printinvoice(struct faculty * list2, struct student * list) {
    char studentID[50];
    struct student *current = list;

    printf("Enter the student's ID: ");
    scanf("%s", &studentID);
    toUpperCase(studentID);

    while (current != NULL) {
        if (strcmp(current->id, studentID) == 0) {
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf(" Sorry, student with ID %s not found.\n", studentID);
    } else {
        float credit_cost = 236.45;
        float tuition = current->creditHour * credit_cost;

        if (current->gpa >= 3.85) {
            tuition *= 0.75; 
        }
        printf("\nHere is the tuition invoice for %s:\n", current->fullName);
        printf("-----------------------------------------------------------------------\n");
        printf("%s\n", current->fullName);
        printf("%s\n", current->id);
        printf("Credit Hours: %d\n", current->creditHour);
        printf("Fees: $52.00\n");
        printf("Total payment: $%.2f\n", tuition + 52.00);
        printf("-----------------------------------------------------------------------\n");
    }
    menu(list2, list);
}

void printfacultyinfo(struct faculty * list, struct student * list2) {
    char facultyID[50];
    struct faculty *current = list;

    printf("\nEnter the faculty's ID: ");
    scanf("%s", &facultyID);
    toUpperCase(facultyID);

    while (current != NULL) {
        printf("%s", current->id);
        if (strcmp(current->id, facultyID) == 0) {
            break; 
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Faculty  %s doesnt exist.\n", facultyID);
    } 
    else {
        printf("\nFaculty found:\n");
        printf("----------------------------------------------------------------\n");
        printf("%s\n", current->fullName); 
        printf("%s department, %s\n", current->department, current->rank); 
        printf("----------------------------------------------------------------\n");
        printf("\n");
    }
    menu(list, list2);
}

void quit()
{
    terminate();
}

void terminate()
{
    printf("\n");
    printf("Thank you for using PerPro. Goodbye!");
    exit(0);
}
