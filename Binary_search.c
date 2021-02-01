#include<stdio.h>

int binary_search(int array[], int n, int number) {
	int beg = 0, end = n - 1;
	int mid = 0;
	while (beg <= end) {
		mid = (beg + end) / 2;
		if (array[mid] == number) 
			return mid;
		else if (array[mid] < number)
			beg = mid + 1;
		else
			end = mid - 1;
	}
	
	return -1;
}

int main() {
	int I, n, number, array[10], result = 0;
	char ch;
	printf("\nEnter the length of the array: ");
	scanf("%d", &n);
	printf("\nEnter the elements of the array in ascending or descending order: ");
	for (I = 0; I < n; I ++)
		scanf("%d", &array[I]);
	do {
		
		printf("\nEnter the number to be found: ");
		scanf("%d", &number);
		result = binary_search(array, n, number);
		if (result != -1)
			printf("\nThe number found at %d position", result + 1);
		else
			printf("\nThe number not found in the array");
		printf("\nDo you want to find more numbers(y/n): ");
		fflush(stdin);
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');
return 0;
}

