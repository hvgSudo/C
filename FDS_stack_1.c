#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack_operations {
char stack[20];
 int stack_1[20];
int top, top_1;
}s;

void push(char, int, int);
void pop(int);
char peek(int);
void display();
void decimal_to_binary(int);
int well_formedness(char[], int);

int main() {
    int choice = 0, length, i, j, k = 0;
    int ret, decimal_number;
    char string[20];
    s.top = -1;
    s.top_1 = -1;
    while(choice != 4) {
        printf("\n1. Stack using array");
        printf("\n2. Decimal to binary");
        printf("\n3. Check well formedness of brackets");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the string/number/expression: ");
                fflush(stdin);
                gets(string);
                fflush(stdin);
                length = strlen(string);
                printf("\nPush Operations \n");
                for (i = 0; i < length; i++) {
                    push(string[i], 1, 0);
                    printf("\n\n\tPass");
                    display();
                }
                printf("\nPop Operations"); // Pop operations on a stack using array
                while (s.top != -1) {
                    if (s.top >= 0)
                        display();
                    printf("\nPopped element: %c", peek(1));
                    pop(1);
                }
                break;
            case 2:
                printf("\nEnter the decimal number: ");
                scanf("%d", &decimal_number);
                decimal_to_binary(decimal_number);
                break;
            case 3:
                printf("\nEnter the paranthesis expression: ");
                fflush(stdin);
                gets(string);
                fflush(stdin);
                length = strlen(string);
                ret = well_formedness(string, length);
                if (ret == 1)
                    printf("\nBrackets are well formed");
                else
                    printf("\nBrackets are not well formed");
                break;
            case 4:
                choice = 4;
                break;
            default:
                printf("\nWrong choice");
            }
        }
    return 0;
}

void push(char item, int stack, int item_1) {
    if (stack == 1)
        s.stack[++s.top] = item;
    else if (stack == 2)
        s.stack_1[++s.top_1] = item_1;
}

void pop(int stack) {
    if (stack == 1)
        s.top = s.top - 1;
    else if (stack == 2)
        s.top_1 = s.top_1 - 1;
}

char peek(int ch) {
    if (ch == 1)
        return s.stack[s.top];
    else if (ch == 2)
        return s.stack_1[s.top_1];
}

void display() {
    int i;
    for (i = s.top; i >= 0; i--) {
        if (i == s.top)
            printf("\nTop --> %c", s.stack[i]);
        else
            printf("\n\t%c", s.stack[i]);
    }
}

void decimal_to_binary(int decimal_number) {
    int a;
    printf("\n%d = ", decimal_number);
    while (decimal_number != 0) {
        a = decimal_number % 2;
        push('n', 2, a);
        decimal_number = decimal_number / 2;
    }
    while (s.top_1 != -1) {
        printf("%d", peek(2));
        pop(2);
    }
}

int well_formedness(char str[], int size) {
    int i, conclusion = 1;
    char ret;
    for (i = 0; i < size; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i], 1, 0);
            continue;
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (str[i] == ')')
                if (peek(1) == '(')
                    pop(1);
            else {
                conclusion = 0;
                break;
            }
            if (str[i] == '}')
                if (peek(1) == '{')
                    pop(1);
            else {
                conclusion = 0;
                break;
            }
            if (str[i] == ']')
                if (peek(1) == '[')
                    pop(1);
            else {
                conclusion = 0;
                break;
            }
        }
    }
    while (s.top > -1)
        pop(1);
    if (s.top == -1 && conclusion != 0)
        conclusion = 1;
    return conclusion;
}
