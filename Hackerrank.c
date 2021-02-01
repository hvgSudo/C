#include<stdio.h>

void swap(int*, int*);
void bubble_sort(int, int[]);

int main() {
        int n, arr[20];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) 
                scanf("%d", &arr[i]);
        bubble_sort(n, arr);
        return 0;
}

void swap(int *a, int *b) { 
        int temp = *a; 
        *a = *b;
        *b = temp;
}

void bubble_sort(int size, int num[]) {
        int count = 0;
        for (int i = 0; i < size; i++) {
                if (num[i] > num[i + 1]) {
                        swap(&num[i], &num[i + 1]);
                        count = count + 1;
                }
        }
        printf("Array is sorted in %d swaps.", count);
        printf("\nFirst Element: %d", num[0]);
        printf("\nLast Element: %d\n", num[size - 1]);
}
