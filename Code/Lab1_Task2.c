#include<stdio.h>

long long int FindFactorial(int n) {
    if (n>=1)
        return n*FindFactorial(n-1);
    else
        return 1;
}

int main() {
    int n;
    printf("Input: ");
    scanf("%d",&n);
    printf("Output = %d", FindFactorial(n));
    return 0;
}



