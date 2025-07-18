#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b,a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a =0, count_b = 0;
    int freq_a[26] = {0}, freq_b[26] = {0};
    
    for(int i=0;i<strlen(a);i++)
    {
        if(freq_a[a[i]-'a'] == 0)
        {
            count_a++;
            freq_a[a[i]-'a'] = 1;
        }
    }
    
    for(int i=0;i<strlen(b);i++)
    {
        if(freq_b[b[i]-'a'] == 0)
        {
            count_b++;
            freq_b[b[i]-'a'] = 1;
        }
    }
    
    if (count_a == count_b){
        if (strcmp( a, b) < 0)
        {
            return 0;
        }
        else{
            return 1;
        }
    }
    else {
        return (count_a - count_b);
    }
}

int sort_by_length(const char* a, const char* b) {
    if(strlen(a) == strlen(b))
    {
        return strcmp(a,b);
    }
    else {
        return strlen(a) - strlen(b);
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    
    for(int i=0; i<len-1 ; i++)
    {
        int min_idx = i;
        for(int j=i+1; j<len; j++)
        {
            if(cmp_func(arr[min_idx],arr[j]) > 0)
            {
                min_idx = j;
            }
        }
        char *temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}