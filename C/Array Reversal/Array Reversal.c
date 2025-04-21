#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    /*int *swaparr = (int*) malloc(num *sizeof(int));
    for(int j=num-1;j>=0;j--)
    {
        swaparr[num-j-1]=arr[j];
    }
    arr = swaparr;*/
    
    for(int i=0; i<(num/2);i++)
    {
        int temp = arr[i];
        arr[i] = arr[num-i-1];
        arr[num-i-1] = temp;
    }
    
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}