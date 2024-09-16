#include <stdio.h>
#define SIZE 10

int main()
{
  int array[SIZE] = {10, 40, 30, 10, 14, 72, 81, 90, 100, 57};
  int largestValue = array[0];
  float average = 0.0;
  int index = 0;
  int sum = 0;


  while ( index < SIZE)
  {
      if( array[index] > largestValue)
      {
          largestValue = array[index];
      }
      sum += array[index];
      index++;
  }

  average = (float)sum / SIZE;
  printf("The largest value in the array is %d\n", largestValue);
  printf("The average value of the array is %.2f\n" , average);


}
