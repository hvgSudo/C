#include<stdio.h>
#include<stdlib.h>

int n, i, *ptr;

void read() {
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("\nEnter the %d elements of the array: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", ptr + i);
}

void print() {
    printf("\nThe array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", *(ptr + i));
}

void insertion_sort();

int main() {
    int ret;
    read();
    insertion_sort();
    printf("\n\nThe array has been sorted\n");
    print();    
    return 0;
}

void insertion_sort() {
    int temp, j, k;
    for (j = 1; j < n; j++) {
        temp = *(ptr + j);
        k = j - 1;
        while (k >= 0 && *(ptr + k) > temp) {
            *(ptr + k + 1) = *(ptr + k);
            k = k - 1;
        }
        *(ptr + k + 1) = temp;
        printf("\nPass %d: ", j);
        print();
    }
}