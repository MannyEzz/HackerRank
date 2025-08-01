#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    int flag1 = -1;
    for (int i =0; i<n-1;i++)
    {
        if(strcmp(s[i],s[i+1]) <0)
        {
            /*change the flag so it indicate that this is the index of the smaller string*/
            flag1 = i;
        }
    }
    /*check if the first string is at the end and no more moves to make*/
    if (flag1 == -1){
        return 0;
    }
    
    int flag2 = -1;
    for(int j=flag1+1;j<n;j++)
    {
        if(strcmp(s[flag1],s[j]) <0)
        {
            flag2 = j;
        }
    }
    
    char *temp = s[flag1];
    s[flag1] = s[flag2];
    s[flag2] = temp;
    
    int i = flag1 + 1 ;
    int j = n-1;
    
    while(i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    return 1; 
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}