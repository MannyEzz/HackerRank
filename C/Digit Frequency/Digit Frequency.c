#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char num[1000];
    scanf("%[^\n]%*c", num);
    int arr[10] = {0};
    
    for (int i=0;i<strlen(num);i++)
    {
        if(num[i] >= '0' && num[i] <= '9' )
        {
            arr[num[i] - '0']++;
        }
    }
    
    for (int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}
