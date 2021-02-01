#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int i;

void search(int, int*, int);

int main() {
	int n, *array, key;
	printf("\nEnter the size of the array: ");
	scanf("%d", &n);
	array = (int*)malloc(n * sizeof(int));
	printf("\nEnter the %d elements of the array: ");
	for (i = 0; i < n; i++)
		scanf("%d", (array + i));
	printf("\nEnter the element you want to find: ");
	scanf("%d", &key);
	search(n, array, key);
	getch();
	return 0;
}

void search(int n, int *array, int key) {
	int f = 0;
	printf("\nThe array is: ");
	for (i = 0; i < n; i++)
		printf("%d ", *(array + i));
	for (i = 0; i < n; i++) {
		if (key == *(array + i)) {
			printf("\nElement found at %d index", i);
			f = f + 1;
		}
	}
	if (i == n && f == 0)
		printf("\nElement not found");
}
