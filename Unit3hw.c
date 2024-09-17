//unit3.hw
//Group members: Jason Gouws, Griffin Morgan, David Jerome

#include <stdio.h>
#define SIZE 10
#define FALSE 0
# define TRUE 1

int main()
{
  int array[SIZE] = {10, 40, 30, 10, 14, 72, 81, 90, 100, 57};
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
