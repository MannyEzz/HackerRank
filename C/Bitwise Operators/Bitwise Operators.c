#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int ANDMAX=0,ORMAX=0,XORMAX=0;
  for (int i=1; i<=n; i++)
  {
      for (int j=(i+1); j<=n; j++)
      {
          int AND = i&j;
          int OR = i|j;
          int XOR = i^j;
          if ( ANDMAX<AND && k> AND)
          {
            ANDMAX = AND;
          }
          if ( ORMAX<OR && k> OR)
          {
            ORMAX = OR;
          }
          if ( XORMAX<XOR && k> XOR)
          {
            XORMAX = XOR;
          }
      }
  }
  printf("%d \n",ANDMAX);
  printf("%d \n",ORMAX);
  printf("%d \n",XORMAX);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
