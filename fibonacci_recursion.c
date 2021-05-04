#include<stdio.h>
int fib(int);

int main() {
    int i, n, j = 0; 
    printf("Enter the number: ");
    scanf("%d", &n);
    for (i = 0; i < n + 1; i++) {
        printf("%d  ", fib(j));
        j += 1;
    }
    return(0);
}

int fib(int n) {
    if (n <= 1) {
        return(n);
    } else {
        return(fib(n-1) + fib(n-2));
    }
}