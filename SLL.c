#include <stdio.h>
#include <stdlib.h>

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

void insert(struct Node*, int, int, int); 
void display(struct Node*, int);
void remove(struct Node*, int, int); 

void printMenu() {
    printf("\n1. Insert data into linked list");
    printf("\n2. View the linked list");
    printf("\n3. Remove data from linked list");
    printf("\n4. Exit");
}

// Main method
int main() {
    struct Node* head;
    return 0;
}

// insert node into linked list
void insert (struct Node* head, int data, int choice, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp;
    int count = 0;
    switch (choice) {
        case 1:
            if (head == NULL) {
                head->data = data;
                head->next = NULL;
            } else {
                temp = head;
                while (temp) 
                    temp = temp->next;
                temp->data = data;
                temp->next = NULL;
            }
            break;
        case 2:
            if (head == NULL) {
                head->data = data;
                head->next = NULL;
            } else {
                temp = head;
                while (count < position) {
                    temp = temp->next;
                    count;
                }
                temp->data = data;
                temp->next = NULL;
            }
            break;
    }
}