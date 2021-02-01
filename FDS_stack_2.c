#include<stdio.h>
#include<ctype.h>

struct Stack {
	char stack[100];
	int top;
}s;

void push(char x) {
    s.stack[++s.top] = x;
}

char pop() {
    if (s.top == -1)
        return -1;
    else
        return s.stack[s.top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void convert(char *e) {
	char x;
    printf("\nPostfix Expression: ");
	while (*e != '\0') {
        if (isalnum(*e))
            printf("%c ",*e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c ", x);
        } else {
            while (priority(s.stack[s.top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    while(s.top != -1) {
        printf("%c ",pop());
    }
}

int main() {
	s.top = -1;
    char exp[20], ch;
    do {
        printf("\nInfix expression : ");
        scanf("%s",exp);
        printf("\n");
        convert(exp);
        printf("\n\nDo you want to convert more expressions(y/n): ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');
    return 0;
}
