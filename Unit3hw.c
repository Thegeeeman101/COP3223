#include <stdio.h>
#define SIZE 10

int main()
{
  int array[SIZE] = {10, 40, 30, 10, 14, 72, 81, 90, 100, 57};
  int largestValue = array[0];
  float average;
  int index = 0;


  while ( index < SIZE)
  {
      if( array[index] > largestValue)
      {
          largestValue = array[index];
      }
      index++;
  }
    printf("The largest value in the array is %d\n", largestValue);


}
