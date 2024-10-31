//unit6.hw



char most_occuring_character ( char *str);
void count_low_up_digit ( char *str, int *lower, int *upper , int *digit);
char * Up_letters ( char *str);


char most_occuring_character ( char *str)
{
    //Your code goes here
}
void count_low_up_digit ( char *str, int *lower, int *upper , int *digit)
{
    //Your code goes here
}
char * Up_letters ( char *str)
{
    //Your code goes here
}



//the following main function is to remain UNCHANGED!


int main() {
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

