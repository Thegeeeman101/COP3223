//unit4.hw
//Group members: Jason Gouws, Griffin Morgan, David Jerome

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define FALSE 0
# define TRUE 1

int main()
{
  int * array;
  array = malloc (SIZE * sizeof(int));
  int i;
  for(i = 0; i < SIZE; i++)
  {
    array[i] = (rand() % 100);
    printf("%d\n", array[i]);
  }
  int largestValue = array[0];
  float average = 0.0;
  int index = 0;
  int sum = 0;
  int duplicates = FALSE;


  while ( index < SIZE)
  {
      if( array[index] > largestValue)
      {
          largestValue = array[index];
      }
      sum += array[index];
      index++;
  }

  for(int i = 0; i < SIZE - 1; i++)
  {
    for(int j = 0; j < SIZE - 1; j++)
    {
      if(i == j)
      {
        continue;
      }
      else if(array[i] == array[j])
      {
        duplicates = TRUE;
      }
    }
  }

  average = (float)sum / SIZE;
  printf("The largest value in the array is %d\n", largestValue);
  printf("The average value of the array is %.2f\n" , average);
  if(duplicates == TRUE)
  {
    printf("The array has duplicates.");
  }
  else
  {
    printf("The array does not duplicates.");
  }


}
