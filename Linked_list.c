#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **, int);
void insert_after(struct node*, int);
void append(struct node**, int);
void print(struct node *); 

int main() {
    struct node *head = NULL;
    int i, d, n;
    printf("\nHow many values do you want to enter: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter data %d: ", i + 1);
        scanf("%d", &d);
        if (i == 0)
            insert(&head, d);
        else if (i != 0)
            append(&head, d);
    }
    printf("\nElements entered into the list");
    printf("\nThe list is: ");
    print(head);
    return 0;
}

void insert(struct node **head_ref, int data) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = (*head_ref);
    (*head_ref) = new;
}

void insert_after(struct node *prev, int new_data) {
    if (prev == NULL) {
        printf("Previous node cannot be null");
        return;
    }
    struct node *ins = (struct node*)malloc(sizeof(struct node));
    ins->data = new_data;
    ins->next = prev;
    prev->next = ins;
}

void append(struct node **head, int new_data) {
    struct node *app = (struct node*)malloc(sizeof(struct node));
    struct node *last = *head;
    app->data = new_data;
    app->next = NULL;
    if (*head == NULL) {
        *head = app;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = app;
    return;
}

void print(struct node *read) {
    while (read != NULL) {
        printf(" %d ->", read->data);
        read = read->next;
    }
    printf("\n");
}