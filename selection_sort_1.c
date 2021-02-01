#include<stdio.h>

void selection_sort(int[], int);
void display(int[], int);
void swap(int*, int*);

int main() {
    int i, arr[10], size;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);
    printf("\nEnter the array elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    selection_sort(arr, size);
    return 0;
}

void selection_sort(int arr[], int s) {
    int i, min, j;
    for (i = 0; i < s - 1; i++) {
        min = i;
        for (j = i + 1; j < s; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[min], &arr[i]);
        display(arr, s);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int s) {
    int i;
    printf("\n");
    for (i = 0; i < s; i++)
        printf("%d ", arr[i]);
}