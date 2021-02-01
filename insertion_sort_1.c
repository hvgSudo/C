#include<stdio.h>

void insertion_sort(int[], int);
void display(int[], int);

int main() {
    int arr[10], size, i;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);
    printf("\nEnter the array elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    insertion_sort(arr, size);
    return 0;
}

void insertion_sort(int arr[], int s) {
    int i, j, key; 
    for (i = 1; i < s; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printf("\n");
        display(arr, s);
    }
}

void display(int arr[], int s) {
    int i;
    for (i = 0; i < s; i++) 
        printf("%d ", arr[i]);
}