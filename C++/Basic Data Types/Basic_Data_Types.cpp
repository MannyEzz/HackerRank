#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    char ch;
    int n;
    float f;
    double d;
    long l;
    
    cin>>n >> l >> ch >> f >> d;
    printf("%d\n%ld\n%c\n%.3f\n%.9lf",n,l,ch,f,d);
    return 0;
}