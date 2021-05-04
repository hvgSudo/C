#include<stdio.h>

int fib_recursion(int);
int fib(int);

int main() {
    int n, i, choice = 0;
    while(choice != 3) {
        printf("\n\n1. Fibonacci using recursion");
        printf("\n2. Fibonacci Series without using recursion");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                    printf("\nEnter the number of terms: ");
                    scanf("%d", &n);
                    printf("Fibonacci Series: \n");
                    for (i = 0; i < n + 1; i++) {
                        printf("%d  ", fib_recursion(i));
                    }
                    break;
            case 2:
                    printf("\nEnter the number of terms: ");
                    scanf("%d", &n);
                    printf("Fibonacci Series: \n");
                    fib(n);
                    break;
            default:
                    if (choice == 3) {
                        printf("\nExit Successful");
                    } else {
                        printf("\nWrong choice");
                    }
        }
    }
    return(0);
}

int fib_recursion(int n) {
    if (n <= 1) {
        return(n);
    } else {
        return(fib_recursion(n - 1) + fib_recursion(n - 2));
    }
}

int fib(int n) {
    int d, i = 0, a = 0, b = 1;
    while (i <= n) {
        printf("%d  ", a);
        d = a + b;
        a = b;
        b = d;
        i++;
    }
}