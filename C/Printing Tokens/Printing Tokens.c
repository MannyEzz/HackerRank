#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    /*int i=0,j =0;
    for (i=0;i<=strlen(s);i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            for (j;j<i;j++)
            {
                printf("%c",s[j]);   
            }
            printf("\n");
            j = j+1;
        }
    }*/
    int string_length = strlen(s);
    for (int i = 0; i < string_length; i++) {
        if (s[i] == ' ') {
            printf("\n");
        } 
        else {
            printf("%c", s[i]);
        }
    }
    return 0;
}