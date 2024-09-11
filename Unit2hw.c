#include <stdio.h>

int main()
{
    float hwScore = 0.0;
    float prScore = 0.0;
    float lbScore = 0.0;
    float mdOneScore = 0.0;
    float mdTwoScore = 0.0;
    float finalScore = 0.0;
    float averageScore = 0.0;
    char letterGrade[2];
    int counter = 0;

    printf("Enter the hw average score: ");
    scanf("%f", &hwScore);

    while ((hwScore > 100 || hwScore < 0) && counter < 2)
    {
        counter++;
        printf("Invalid score. Try again: ");
        scanf("%f", &hwScore);

    }
    if (hwScore > 100 || hwScore < 0)
    {
        printf("I'm sorry...You tried too many time.");
    }


    printf("\nEnter the project average score: ");
    scanf("%f", &prScore);

    printf("\nEnter lab average score: ");
    scanf("%f", &lbScore);

    printf("\nEnter midterm1, midterm2 and the final: ");
    scanf("%f %f %f", &mdOneScore, &mdTwoScore, &finalScore);

    printf("\nHere are all your average scores:");
    printf("\n\tHW\t\t: %.2f", hwScore);
    printf("\n\tPROJECTS\t: %.2f", prScore);
    printf("\n\tLABS\t\t: %.2f", lbScore);
    printf("\n\tMIDTERM1\t: %.2f", mdOneScore);
    printf("\n\tMIDTERM2\t: %.2f", mdTwoScore);
    printf("\n\tFINAL\t\t: %.2f", finalScore);
    printf("\n------------------------------------");
    printf("\nOVERALL AVERAGE : %.2f", averageScore );
    printf("\n(%.2f*.2 + %.2f*.2 + %.2f*.05 + (%.2f+%.2f+%.2f)*.55/3 is %.2f", hwScore, prScore, lbScore, mdOneScore, mdTwoScore, finalScore, averageScore);
    printf("\n------------------------------------");


    if (averageScore >= 0 && averageScore <= 100)
    {
        if(averageScore > 93.5)
        {
            letterGrade[0] = 'A';
        }
        else if(averageScore > 89.5)
        {
            letterGrade[0] = 'A';
            letterGrade[1] = '-';
        }
        else if(averageScore > 86.5)
        {
            letterGrade[0] = 'B';
            letterGrade[1] = '+';
        }
        else if(averageScore > 83.5)
        {
            letterGrade[0] = 'B';
        }
        else if(averageScore > 79.5)
        {
            letterGrade[0] = 'B';
            letterGrade[1] = '-';
        }
        else if(averageScore > 76.5)
        {
            letterGrade[0] = 'C';
            letterGrade[1] = '+';
        }
        else if(averageScore > 73.5)
        {
            letterGrade[0] = 'C';
        }
        else if(averageScore > 69.5)
        {
            letterGrade[0] = 'C';
            letterGrade[1] = '-';
        }
        else if(averageScore > 66.5)
        {
            letterGrade[0] = 'D';
            letterGrade[1] = '+';
        }
        else if(averageScore > 63.5)
        {
            letterGrade[0] = 'D';
        }
        else if(averageScore > 60.5)
        {
            letterGrade[0] = 'D';
            letterGrade[1] = '-';
        }
        else
        {
            letterGrade[0] = 'F';
        }
    }

    printf("\n\n\t\tFINAL LETTER GRADE: %s\n", letterGrade);



}
