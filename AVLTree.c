#include<stdio.h>
#include<stdlib.h>

// Create Node structure
struct Node {
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

int max(int a, int b) {
	return (a > b) ? a : b;
}

// Calculate height
int height(struct Node *N) {
	if (N == NULL)
		return 0;
	return N->height;
}

// Create a node
struct Node *newNode(int key) {
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

// RR Rotation
struct Node *RR(struct Node *y) {
	struct Node *x = y->left;
	struct Node *node = x->right;
	x->right = y;
	y->left = node;
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}

// LL rotation
struct Node *LL(struct Node *x) {
	struct Node *y = x->right;
	struct Node *node = y->left;
	y->left = x;
	x->right = node;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

// Get balance factor
int getBalance(struct Node *N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Insert Node
struct Node *insertNode(struct Node *node, int key) {
	// find correct position to insert the node and insert
	if (node == NULL)
		return (newNode(key));
	if (key < node->key)
		node->left = insertNode(node->left, key);
	else if (key > node->key)
		node->right = insertNode(node->right, key);
	else
		return node;
	// Update balance factor of each node and balance the tree
	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getBalance(node);
	if (balance > 1 && key < node->left->key)
		return RR(node);
	if (balance < -1 && key > node->right->key)
		return LL(node);
	if (balance > 1 && key > node->left->key) {
		node->left = LL(node->left);
		return RR(node);
	}
	if (balance < -1 && key < node->right->key) {
		node->right = RR(node->right);
		return LL(node);
	}
	return node;
}

struct Node *minValueNode(struct Node *node) {
	struct Node *current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

// Delete a node
struct Node *deleteNode(struct Node *root, int key) {
	// Find the node and delete it
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		if ((root->left == NULL) || (root->right == NULL)) {
			struct Node *temp = root->left ? root->left : root->right;
			if (temp == NULL) {
				temp = root;
				root = NULL;
			} 
			else
				*root = *temp;
			free(temp);
		} else {
			struct Node *temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	if (root == NULL)
		return root;
	// Update the balance factor of each node and balance the node
	root ->height = 1 + max(height(root->left), height(root->right));
	int balance = getBalance(root);
	if (balance > 1 && getBalance(root->left) >= 0)
		return RR(root);
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = LL(root->left);
		return RR(root);
	}
	if (balance < -1 && getBalance(root->right) <= 0)
		return LL(root);
	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = RR(root->right);
		return LL(root);
	}
	return root;
}

// Print the tree
void printInOrder(struct Node *root) {
	if (root != NULL) {
		printInOrder(root->left);
		printf("%d ", root->key);
		printInOrder(root->right);
	}
}

// Action Menu
void printActions() {
	printf("\n1. Insert node");
	printf("\n2. Delete Node");
	printf("\n3. View the tree");
	printf("\n4. Exit");
	printf("\nEnter your choice: ");
}

// Read input from a file and write output to the other
void initCode() {
	#ifndef AVLTREE
	freopen("D:/Codes/C/inputC.txt", "r", stdin);
    freopen("D:/Codes/C/outputC.txt", "w", stdout);
	#endif
}

// Main Method
int main() {
	initCode();
	struct Node *root = NULL;
	int choice, key = 0;
	int exit = 0;
	while (exit != 1) {
		printActions();
		scanf("%d", &choice);
		printf("%d\n", choice);
		switch(choice) {
			case 1:
				while (key != -1) {
					printf("\nEnter -1 to stop");
					printf("\nEnter the key: ");
					scanf("%d", &key);
					printf("%d\n", key);
					if (key != -1)
						root = insertNode(root, key); 
				}
				break;
			case 2:
				printf("\nEnter the key: ");
				scanf("%d", &key);
				printf("%d\n", key);
				root = deleteNode(root, key);
				break;
			case 3:
				printf("\nThe tree is ");
				printInOrder(root);
				break;
			case 4:
				exit = 1;
				break;
			default:
				printf("\nWrong choice");
		}
	}
	/*
	root = insertNode(root, 2);
	root = insertNode(root, 1);
	root = insertNode(root, 7);
	root = insertNode(root, 4);
	root = insertNode(root, 5);
	root = insertNode(root, 3);
	root = insertNode(root, 8);
	printf("\nThe tree is\n");
	printInOrder(root);
	root = deleteNode(root, 3);
	printf("\nAfter deletion\n");
	printInOrder(root);
	*/
	return 0;
}