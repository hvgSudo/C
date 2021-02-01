#include<stdio.h>
#include<stdlib.h>

int *stack, count;

int push(int);
int pop();
void display();

int main() {
    int choice, n, ret;
    printf("\nEnter the size of the stack: ");
    scanf("%d", &n);
    stack = (int *)malloc(n * sizeof(int));
    char ch;
    do {
        printf("\n1. Push into the stack (insert)");
        printf("\n2. Pop out of the stack (remove)");
        printf("\n3. Display the stack");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                ret = push(n);
                if (ret == 1)
                    printf("\nThe stack is full");
                display();
                break;
            case 2:
                ret = pop();
                if (ret == -1)
                    printf("\nThe stack is empty");
                display();
                break;
            case 3:
                display();
                break;
            default:
                printf("\nWrong choice");
        }
        printf("\nDo you want to perform more operations(y/n): ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');
    return 0;
}

int push(int n) {
    int element;
    if (count == n)
        return 1;
    printf("\nEnter the element: ");
    scanf("%d", &element);
    *(stack + count) = element;
    count = count + 1; 
}

int pop() {
    int i;
    if (count == 0)
        return -1;
    printf("\nPopped element: %d", *(stack + count - 1));
    count = count - 1;
}

void display() {
    int i;
    printf("\nThe stack is");
    for (i = count - 1; i >= 0; i--) {
        if (i == count - 1)
            printf("\nTop --> %d", *(stack + i));
        else
            printf("\n\t%d", *(stack + i));
    }
}