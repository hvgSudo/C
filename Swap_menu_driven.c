#include<stdio.h>

void value(int, int);
void reference(int*, int*);

int main() {
    int a, b, choice = 0;
    while(choice != 3) {
        printf("\n1. Call by value");
        printf("\n2. Call by reference");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
                printf("\nEnter Number 1: ");
                scanf("%d", &a);
                printf("Enter Number 2: ");
                scanf("%d", &b);
                value(a, b);
                break;
        case 2:
                printf("\nEnter Number 1: ");
                scanf("%d", &a);
                printf("Enter Number 2: ");
                scanf("%d", &b);
                reference(&a, &b);
                printf("\nNumber 1: %d \nNumber 2: %d\n", a, b);
                break;
        default: 
                if (choice == 3) {
                    printf("\nExit Successful");
                } else {
                printf("\nWrong choice");
                }
        }
    }
}

void value(int x, int y) {
    int t;
    t = x; 
    x = y;
    y = t;
    printf("Number 1: %d \nNumber 2: %d\n", x, y);
}

void reference(int *x, int *y) {
    int t;
    t = *x;
    *x = *y;
    *y = t;
}