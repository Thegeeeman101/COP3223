//unit8.hw
//Group members: Jason Gouws, Griffin Morgan, David Jerome

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct employee {
    int id;
    char name[50];
    float salary;
    int numberOfDependents;
    //---------------------
    struct employee * next;
    struct employee * below;
};

//----------------------- FUNCTION PROTOTYPES ---------------------------
//0.
int getId ( char * name);
/*
returns the sum of the ascii codes of the letters of name.
*/

//1.
void printEmployee ( struct employee );
/*
prints an employee in the format [id,name,net salary], where:
Net salary = salary*0.91 + (numberOfDependent *0.01*salary)
Examples: [562,AaBc xYz,1253.56] [562,bAac ZyX,6253.06]
*/

//2.
void printAllEmployees ( struct employee * list);
/*
prints all employees in the list. Loops through list and calls
printEmployee for each employee in list
*/

//3.
struct employee * addEmployee ( struct employee * list , struct employee e);
/*
adds e to list.
*/

//4.
int searchEmployee ( struct employee * list , char * name);
/*
returns 1 if name is found in list. Otherwise, it returns 0
*/

//5.
float highestNetSalary ( struct employee * list);
/*
returns the highest net salary.
*/

//----------------------- FUNCTION DEFINITIONS ---------------------------
//0.
int getId ( char * name ){
    int sum = 0;
    printf ("COMING UP\n");
    for(int i = 0; i < strlen(name); i++)
    {
        sum += (int) toupper(name[i]);
    }
    return sum;
}
//1.
void printEmployee ( struct employee emp){
    printf("COMING UP\n");
    printf("[%d, %s, %.2f]\n", emp.id, emp.name, ((emp.salary*0.91) + (emp.numberOfDependents * 0.01 * emp.salary)));
}
//2.
void printAllEmployees ( struct employee * list){
    printf ("COMING UP\n");
    struct employee * current = list;
    while (current != NULL){
        printEmployee(*current);
        struct employee *belowCurrent = current->below;
        while (belowCurrent != NULL) 
        {
            printEmployee(*belowCurrent);
            belowCurrent = belowCurrent->below;
        }
        current = current->next;
    }
}
//3.
struct employee * addEmployee ( struct employee * list , struct employee e){
    printf ("COMING UP\n");
    struct employee *current = list;
    while (current != NULL) {
        if (current->id == e.id) {
            struct employee *newNode = malloc(sizeof(struct employee));
            newNode->id = e.id;
            strcpy(newNode->name, e.name);
            newNode->salary = e.salary;
            newNode->numberOfDependents = e.numberOfDependents;
            newNode->next = NULL;
            newNode->below = current->below;
            current->below = newNode;
            return list;
        }
        current = current->next;
    }
    struct employee * newNode = malloc( sizeof (struct employee) );
    newNode -> id = e.id;
    strcpy(newNode->name, e.name);
    newNode->salary = e.salary;
    newNode->numberOfDependents = e.numberOfDependents; 
    newNode->next = list;
    newNode->below = NULL;
    return newNode;
}
//4.
int searchEmployee ( struct employee * list , char * name){
    printf ("COMING UP\n");
    while (list != NULL) {
        if(list->name[strlen(list->name) - 1] == '\n')
        {
            list->name[strlen(list->name) - 1] = '\0';
        }
        if (strcmp(list->name , name ) == 0)
        {
            return 1; 
        }
        list = list->next;
    }
    return 0;
}
//5.
float highestNetSalary ( struct employee * list){
    printf ("COMING UP\n");
    float highestSalary = list->salary;
    while (list != NULL)
    {
        if (highestSalary < list->salary)
        {
            highestSalary = list->salary;
        }
        list = list->next;
    }
    return highestSalary;
}
//DO NOT CHANGE ANYTHING IN main
int main() {
    struct employee * company = NULL , tempEmployee;
    int tempInt = 0;
    char tempName [50] = "Allal Kamch";
    char dummy;

    printf ("Enter 1 to add a new employee, 0 to stop: ");
    scanf ("%d", &tempInt);

    while ( tempInt == 1 ){
        printf("Enter Full Name: ");
        scanf("%c",&dummy);
        fgets(tempEmployee.name, 50, stdin);
        tempEmployee.id = getId ( tempEmployee.name );
        printf ("Enter salary-numberOfDependents: ");
        scanf ("%f-%d", &tempEmployee.salary, &tempEmployee.numberOfDependents);
        company = addEmployee ( company , tempEmployee );
        printf ("Enter 1 to add a new employee, 0 to stop: ");
        scanf ("%d", &tempInt);
    }

    printAllEmployees ( company );

    printf ("Highest Net Salary = %.2f\n", highestNetSalary(company) );

    tempInt = searchEmployee ( company , tempName);

    if ( tempInt == 1 ) printf ("%s is found!\n", tempName);
    else printf ("%s is NOT found!\n", tempName);

    return 0;
}
