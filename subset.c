#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void subset(int, int*);

int main() {
	int n, *array, i;
	printf("\nEnter the size of array: ");
	scanf("%d", &n);
	array = (int*) malloc(n * sizeof(int));
	printf("\nEnter %d elements of the array: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", (array + i));
	printf("\nThe array is: ");
	for (i = 0; i < n; i++)
		printf("%d ", *(array + i));
	subset(n, array);
	getch();
	return 0;
}

void subset(int n, int *array) {
	int i, j;
	printf("\nSubsets are: \n");
	for (i = 0; i < n; i++)
		printf("%d\t", *(array + i));
	for (i = 0; i < n; i++) {
		printf("\n\n");
		for (j = 0; j < i; j++)
			printf("%d\t", *(array + j));
	}
}
