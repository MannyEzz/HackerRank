#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
  /*int d=0;
  if (n<=3)
  {
    switch (n)
    {
        case 1:
        d = a;
        break;
        
        case 2:
        d = b;
        break;
         
        case 3:
        d = c;
        break;
    }
  }
  else
  {
    d = a+b+c;
    if(n>3)
    {
        n--;
        d = find_nth_term(n,b,c,d);
    }
  }
  return d;*/

  if (n ==1)
    {
        return a;
    }
    else if (n ==2)
    {
        return b;
    }
    else if (n ==3)
    {
        return c;
    }
    else{
        return find_nth_term(n-1, b,c, a+b+c);
    }
}
int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}