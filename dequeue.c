#include<stdio.h>
#include<stdbool.h>

struct queue {
	int front;
	int rear;
	int size;
	int n;
	int array[10];
} q = {-1, 0, 5, 0};

int i;

bool is_full() {
	return ((q.front == 0 && q.rear == q.size - 1) || q.front == q.rear + 1);	
}

bool is_empty() {
	return (q.front == -1);
}

void insert_front(int key) {
	if (is_full()) {
		printf("\nQueue is full");
		return;
	}
	printf("\nNumber inserted at the front");
	if (q.front == -1) { // if queue is empty
		q.front = 0;
		q.rear = 0;
	} else if (q.front == 0) // front at first position
		q.front = q.size - 1;
	else // decrease front by 1
		q.front = q.front - 1;
	q.array[q.front] = key;
	q.n++;
}

void insert_rear(int key) {
	if (is_full()) {
		printf("\nQueue is full");
		return;
	}
	printf("\nNumber inserted at the rear");
	if (q.front == -1) { // if queue is empty
		q.front = 0;
		q.rear = 0;
	} else if ( q.rear == q.size - 1) // rear at last position
		q.rear = 0;
	else // increase rear by 1
		q.rear = q.rear + 1;
	q.array[q.rear] = key;
	q.n++;
}

void delete_front()
{
	if (is_empty())
	{
		printf("\nQueue is empty");
		return;
	}
	printf("\nNumber deleted from the front");
	if (q.front == q.rear)
	{ // Dequeue has only one element
		q.front = -1;
		q.rear = -1;
	}
	else
	{ // back to the initial position
		if (q.front == q.size - 1)
			q.front = 0;
		else					   // remove current value from queue by
			q.front = q.front + 1; // increasing front by 1
	}
	q.n--;
}

void delete_rear() {
	if (is_empty()) {
		printf("\nQueue is empty");
		return;
	}
	printf("\nNumber deleted from the rear");
	if (q.front == q.rear) { // Dequeue has only one element
		q.front = -1;
		q.rear = -1;
	} else if (q.rear == 0) 
		q.rear = q.size - 1;
	else 
		q.rear = q.rear - 1;
	q.n--;
}

void display() {
	if (is_empty())
	{
		printf("\nQueue is empty");
		return;
	}
	if (q.front > q.rear && q.front < q.size)
		for (i = q.front; i < q.size; i++)
			printf(" %d ", q.array[i]);
	else if (q.front == q.size - 1)
		printf(" %d ", q.array[q.front]);
	else if (q.front == q.rear + 1)
		for (i = q.front; i < q.size; i++)
			printf(" %d ", q.array[i]);
	for (i = 0; i <= q.rear; i++)
		printf(" %d ", q.array[i]);
}

int main() {
	int choice, number;
	char ch;
	printf("\nYou can enter only 5 element in the queue");
	do {
		printf("\n1. Insert at front");
		printf("\n2. Insert at rear");
		printf("\n3. Delete from rear");
		printf("\n4. Delete from front");
		printf("\n5. Display the queue");
		printf("\n6. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\nEnter the number: ");
				scanf("%d", &number);
				insert_front(number);
				break;
			case 2:
				printf("\nEnter the number: ");
				scanf("%d", &number);
				insert_rear(number);
				break;
			case 3:
				delete_rear();
				break;
			case 4:
				delete_front();
				break;
			case 5:
				printf("\nThe queue is");
				display();
				break;
			case 6:
				printf("\nExit");
				break;
			default:
				printf("\nWrong choice");
		}
		printf("\nDo you want to perform more operations on the queue(y/n): ");
		fflush(stdin);
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');
	return 0;
}
