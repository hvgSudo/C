#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("\nThe list is ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void printMenu() {
    printf("\n1. ");
}

int insert(struct Node*, int);
int remove(struct Node*, int);

int main() {
    struct Node* head;
    return 0;
}