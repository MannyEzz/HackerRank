#include <iostream>
#include <cstdio>
using namespace std;

const char *lUP[] ={"one","two","three","four","five",
"six","seven","eight","nine"};

int main() {
    // Complete the code.
    int a,b;
    cin>> a >> b;
    
    for(int i=a; i<=b;i++){
        if (i<=9){
            printf("%s \n",lUP[i-1]);
        }
        else{
            if(i%2 == 0){
                printf("even \n");
            }
            else{
                printf("odd \n");
            }
        }
    }
    return 0;
}