//unit6.hw
//Group members: Jason Gouws, Griffin Morgan, David Jerome


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char most_occuring_character ( char *str);
void count_low_up_digit ( char *str, int *lower, int *upper , int *digit);
char * Up_letters ( char *str);


char most_occuring_character ( char *str)
{
    char most_occur = '\0';
    int maxCount = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        count = 0;
        for (int j = 0; str[j] != '\0'; j++)
        {
            if(str[i] == str[j])
            {
                count++;
            }

        }
        if (count > maxCount)
        {
            maxCount = count;
            most_occur = str[i];
        }
    }
    return most_occur;
}
void count_low_up_digit ( char *str, int *lower, int *upper , int *digit)
{
    
    *lower = 0;
    *upper = 0;
    *digit = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'a' && str[i] <= 'z') {
            (*lower)++; }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            (*upper)++; }
        else if (str[i] >= '0' && str[i] <= '9') {
            (*digit)++; }
    }
        
    
}
char * Up_letters ( char *str)
{
    int i, x = 0, y = 0;
    char *cap;
    cap = malloc (strlen(str) * sizeof(char));
    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
        {
            cap[y] = str[i];
            y++;
        }
    }

    cap[y] = '\0';

    int count = strlen(cap);

    for(i = 0; i < count; i++)
    {
        cap[i] = toupper(cap[i]);
    }

    for(i = 0; i < count - 1; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            if (cap[i] > cap[j]) 
            {
                char temp = cap[i];
                cap[i] = cap[j];
                cap[j] = temp;
            }
        }
    }

    return cap;
}



//the following main function is to remain UNCHANGED!


int main() 
{
    char str[50] ="";
    char *upper_sorted;
    char most_occur = -1;
    int lower_case=0 , upper_case=0, digits=0;

    printf("Enter your string: ");
    gets(str);

    most_occur = most_occuring_character ( str );
    if ( most_occur == -1 ) printf ("All characters appears once\n");
    else printf ("The most occuring character is: %c \n", most_occur);

    count_low_up_digit ( str, &lower_case, &upper_case , &digits );
    printf ("There is/are %d lower case letter(s)\n", lower_case);
    printf ("There is/are %d upper case letter(s)\n", upper_case);
    printf ("There is/are %d digit(s)\n", digits);

    upper_sorted = Up_letters ( str );
    printf ("%s\n", upper_sorted);
    printf ("%s\n", str);
    
    return 0;
}

