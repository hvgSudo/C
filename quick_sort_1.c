#include<stdio.h>

void recursion(int[], int, int, int);
int sort_partition(int[], int, int, int);
void display(int[], int);
void swap(int*, int*);

int main() {
    int arr[10], s, i;
    printf("\nEnter the size of the array: ");
    scanf("%d", &s);
    printf("\nEnter the array elements: ");
    for (i = 0; i < s; i++)
        scanf("%d", &arr[i]);
    recursion(arr, 0, s - 1, s);
}

void recursion(int arr[], int low, int high, int size) {
    if (low < high) {
        int mid = sort_partition(arr, low, high, size);
        recursion(arr, low, mid - 1, size);
        recursion(arr, mid + 1, high, size);
    }
}

int sort_partition(int arr[], int low, int high, int size) {
    int i = low - 1, j = 0;
    int pivot = arr[high];
    printf("\n");
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            display(arr, size);
        }
        printf("\n");
    }
    swap(&arr[i + 1], &arr[high]);
    display(arr, size);
    return (i + 1);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
}

void display(int arr[], int s) {
    int i;
    for (int i = 0; i < s; i++)
        printf("%d ", arr[i]);
}