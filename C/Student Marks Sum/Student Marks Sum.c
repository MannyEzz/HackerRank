#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
  int result=0;
  
  if (number_of_students == 1) 
  {
    result = 0;
  }
  else if(gender == 'g')
  {
    for(int i=1;i<number_of_students;(i+=2))
    {
        result+= marks[i];
    }  
  }
  else if(gender == 'b')
  {
    for(int i=0;i<number_of_students;(i+=2))
    {
        result+= marks[i];
    } 
  }
  return result;
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}