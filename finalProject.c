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
void quit(struct faculty * list, struct student * list2); //opens option to quit program
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
            quit(list, list2);
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
    printf("Thanks!\n");
    printf("\n");
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
    toUpperCase(tempStudent.id);
    printf ("Gpa: ");
    scanf("%f", &tempStudent.gpa);
    printf ("Credit hours: ");
    scanf("%d", &tempStudent.creditHour);
    students = addstudent ( students , tempStudent);
    printf("\n");
    printf("Thanks!\n");
    printf("\n");
    menu(list2, students);
}

void printinvoice(struct faculty * list2, struct student * list) {
    char studentID[50];
    struct student *current = list;

    printf("Enter the student's ID: ");
    scanf("%s", &studentID);
    toUpperCase(studentID);

    while (current != NULL) {
        printf("%s", current->id);
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
        float discount = 0;

        if (current->gpa >= 3.85) {
            discount = tuition * 0.25;
            tuition *= 0.75; 
        }
        printf("\nHere is the tuition invoice for %s:\n", current->fullName);
        printf("-----------------------------------------------------------------------\n");
        printf("%s                                      (%s)\n", current->fullName, current->id);
        printf("Credit Hours: %d ($%.2f/credit hour)\n", current->creditHour, credit_cost);
        printf("Fees: $52.00\n\n");
        printf("Total payment: $%.2f                    ($%.2f discount applied)\n", tuition + 52.00 , discount);
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

void quit(struct faculty * list, struct student * list2)
{
    char printReportChoice, sortChoice, sortChoice2, dummy;

    struct faculty *temp = NULL;
    struct faculty *current = list;
    struct faculty *next = list->next;

    struct student *temp2 = NULL;
    struct student *current2 = list2;
    struct student *next2 = list2->next;

    printf("Would you like to print the final report (Y/N): ");
    //scanf("%c",&dummy);
    scanf(" %c", &printReportChoice);

    if(printReportChoice == 'Y' || printReportChoice == 'y') 
    {
        printf("\nN or n to sort the faculty by name\n");
        printf("D or d to sort the faculty by department\n");
        printf("R or r to sort the faculty by rank\n");
        printf("Make your sort selection: ");
        //scanf("%c", &dummy);
        scanf(" %c", &sortChoice);

        if (sortChoice == 'N' || sortChoice == 'n')
        {
            while(current != NULL && next != NULL)
            {
                printf("%s - %s\n", current->fullName, next->fullName);
                if (strcmp(current->fullName, next->fullName) > 0) 
                {
                    temp = current; //this doesn't swap the nodes
                    current = next;
                    next = temp;
                }
                current = current->next;
            }
            printf("%s - %s\n", current->fullName, next->fullName);
        } 
        else if (sortChoice == 'D' || sortChoice == 'd')
        {
            while(current != NULL && next != NULL)
            {
                if (strcmp(current->department, next->department) > 0) 
                {
                    temp = current;
                    current = next;
                    next = temp;
                }
                current = current->next;
            }
        } 
        else if (sortChoice == 'R' || sortChoice == 'r') 
        {
            while(current != NULL && next != NULL)
            {
                if (strcmp(current->rank, next->rank) > 0) 
                {
                    temp = current;
                    current = next;
                    next = temp;
                }
                current = current->next;
            }
        }
        printf("\nN or n to sort the students by name\n");
        printf("G or g to sort the students by GPA\n");
        printf("Make your sort selection: ");
        //scanf("%c", &dummy);
        scanf(" %c", &sortChoice2);

        if (sortChoice2 == 'N' || sortChoice2 == 'n') 
        {
            while(current2 != NULL && next2 != NULL)
            {
                if (strcmp(current2->fullName, next2->fullName) > 0) 
                {
                    temp2 = current2;
                    current2 = next2;
                    next2 = temp2;
                }
                current2 = current2->next;
            }
        } 
        else if (sortChoice2 == 'G' || sortChoice2 == 'g') 
        {
            while(current2 != NULL && next2 != NULL)
            {
                if (current2->gpa < next2->gpa) 
                {
                    temp2 = current2;
                    current2 = next2;
                    next2 = temp2;
                }
                current2 = current2->next;
            }
        }
    }

    printf("Here is your report....\n\n");
    printf("\t------ L I S T  O F  F A C U L T Y -----\n");
    while(current != NULL)
    {
        printf("\t\t%s - %s\n", current->fullName, current->department);
        current = current->next;
    }
    printf("\n");
    printf("\t------ L I S T  O F  S T U D E N T S -----\n");
    while(current2 != NULL)
    {
        printf("\t\t%s (GPA = %.2f)\n", current2->fullName, current2->gpa);
        current2 = current2->next;
    }
    terminate();
}

void terminate()
{
    printf("\n");
    printf("Thank you for using PerPro. Goodbye!");
    exit(0);
}
