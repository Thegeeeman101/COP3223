//unit2.hw
//Group members: Jason Gouws, Griffin Morgan, David Jerome

#include <stdio.h>
#include <ctype.h>

int main()
{
    char tryAgain;
    do
    {
        float hwScore = -1.0;
        float prScore = -1.0;
        float lbScore = -1.0;
        float mdOneScore = -1.0;
        float mdTwoScore = -1.0;
        float finalScore = -1.0;
        float averageScore = -1.0;
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
        

        if(hwScore <= 100 && hwScore >= 0)
        {
            counter = 0;
            printf("\nEnter the project average score: ");
            scanf("%f", &prScore);
            
            while ((prScore > 100 || prScore < 0) && counter < 2)
            {
                counter++;
                printf("Invalid score. Try again: ");
                scanf("%f", &prScore);
            }
        }

        if(prScore <= 100 && prScore >= 0)
        {
            counter = 0;
            printf("\nEnter lab average score: ");
            scanf("%f", &lbScore);

            while ((lbScore > 100 || lbScore < 0) && counter < 2)
            {
                counter++;
                printf("Invalid score. Try again: ");
                scanf("%f", &lbScore);
            }
        }

        if(lbScore <= 100 && lbScore >= 0)
        {
            counter = 0;
            printf("\nEnter midterm1, midterm2 and the final: ");
            scanf("%f %f %f", &mdOneScore, &mdTwoScore, &finalScore);
            if(!(mdOneScore <= 100 && mdOneScore >= 0))
            {
                while ((mdOneScore > 100 || mdOneScore < 0) && counter < 2)
                {
                    counter++;
                    printf("Invalid midterm1. Try again: ");
                    scanf("%f", &mdOneScore);
                }
                printf("\n");
            }
            counter = 0;
            if(!(mdTwoScore <= 100 && mdTwoScore >= 0))
            {
                while ((mdTwoScore > 100 || mdTwoScore < 0) && counter < 2)
                {
                    counter++;
                    printf("Invalid midterm2. Try again: ");
                    scanf("%f", &mdTwoScore);
                }
                printf("\n");
            }
            counter = 0;
            if(!(finalScore <= 100 && finalScore >= 0))
            {
                while ((finalScore > 100 || finalScore < 0) && counter < 2)
                {
                    counter++;
                    printf("Invalid final. Try again: ");
                    scanf("%f", &finalScore);
                }
                printf("\n");
            }
            else
            {
                //oh ah
            }
        }

        if(mdOneScore <= 100 && mdOneScore >= 0 && mdTwoScore <= 100 && mdTwoScore >= 0 && finalScore <= 100 && finalScore >= 0)
        {
            printf("\nHere are all your average scores:");
            printf("\n\tHW\t\t: %.2f", hwScore);
            printf("\n\tPROJECTS\t: %.2f", prScore);
            printf("\n\tLABS\t\t: %.2f", lbScore);
            printf("\n\tMIDTERM1\t: %.2f", mdOneScore);
            printf("\n\tMIDTERM2\t: %.2f", mdTwoScore);
            printf("\n\tFINAL\t\t: %.2f", finalScore);
            averageScore = (hwScore * 0.2) + (prScore * 0.2) + (lbScore * 0.05) + ((mdOneScore + mdTwoScore + finalScore) / 3 * 0.55);
            
            printf("\n------------------------------------");
            printf("\nOVERALL AVERAGE : %.2f", averageScore );
            printf("\n(%.2f*.2 + %.2f*.2 + %.2f*.05 + (%.2f+%.2f+%.2f)*.55/3 is %.2f", hwScore, prScore, lbScore, mdOneScore, mdTwoScore, finalScore, averageScore);
            printf("\n------------------------------------");


            if (averageScore >= 0 && averageScore <= 100)
            {
                if(averageScore > 93.5)
                {
                    letterGrade[0] = 'A';
                    letterGrade[1] = ' ';
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
                    letterGrade[1] = ' ';
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
                    letterGrade[1] = ' ';
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
                    letterGrade[1] = ' ';
                }
                else if(averageScore > 60.5)
                {
                    letterGrade[0] = 'D';
                    letterGrade[1] = '-';
                }
                else
                {
                    letterGrade[0] = 'F';
                    letterGrade[1] = ' ';
                }
                printf("\n\n\t\tFINAL LETTER GRADE: %s\n", letterGrade);
            }   
        }
        

        if (counter >= 2)
        {
            printf("\nI'm sorry...You tried too many time.");
        }

        printf("\n\nWould you like start over? (Y/N): ");
        scanf("\n%c", &tryAgain);
            
        counter = 0;   
        while (tolower(tryAgain) != 'y' && tolower(tryAgain) != 'n' && counter < 2)
        {
            counter++;
            printf("Invalid input. Please enter Y or N: ");
            scanf(" %c", &tryAgain);
        }
        if(counter > 2)
        {
            break;
        }
        if(tolower(tryAgain) == 'y')
        {
            printf("*************************************");
            printf("\n\n");
        }
    } while (tolower(tryAgain) == 'y');

    if(tolower(tryAgain) != 'n' && tolower(tryAgain) != 'y')
    {
        printf("\n");
        printf("\t\t\tProgram terminated!");
    }
    else
    {
        printf("\n");
        printf("\t\tGood-bye!");
    }

   
}
    




