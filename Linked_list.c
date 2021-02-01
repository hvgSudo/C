#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **, int);
void print(struct node *); 

int main() {
    struct node *head = NULL;
    int i, d, n;
    printf("\nHow many values do you want to enter: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter data %d: ", i + 1);
        scanf("%d", &d);
        push(&head, d);
    }
    printf("\nElements entered into the list");
    printf("\nThe list is: ");
    print(head);
    return 0;
}

void push(struct node **head_ref, int data) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = (*head_ref);
    (*head_ref) = new;
}

void print(struct node *read) {
    while (read != NULL) {
        printf(" %d ->", read->data);
        read = read->next;
    }
    printf("\n");
}