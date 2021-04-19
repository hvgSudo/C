#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

void inorder(struct node *current) {
    if (current != NULL) {
        inorder(current->left);
        printf("%d ", current->data);
        inorder(current->right);
    }
}

void insert(struct node **);
void delete(int);

int main() { // Main method
    return 0;
}

void insert(struct node **temp) {
    struct node *newNode;
    int data;
    char ch;
    do {
        printf("\nEnter the number: ");
        scanf("%d", &data);
        if (*temp == NULL) {
            (*temp)->data = data;
        } else {
            while (1) {
                if (data > (*temp)->data) 
                    (*temp) = (*temp)->right;
                else
                    (*temp) = (*temp)->left;
            }
            (*temp)->data = data;
        }
        printf("\nDo you want to enter more elements(y/n): ");
        scanf("%c", &ch);
        fflush(stdin);
    }while(ch == 'y' || ch == 'Y');
}