#include <stdio.h>
#include<stdlib.h>

int n, i, *arr;

void read()
{
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    printf("\nEnter the %d elements of the array: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
}

void print()
{
    printf("\nThe array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", *(arr + i));
}

void selection_sort();

int main()
{
    int ret;
    read();
    selection_sort();
    printf("\n\nThe array has been sorted\n");
    print();
    return 0;
}

void selection_sort() {
    int temp, j, k, min;
    for (j = 0; j < n - 1; j++) {
        min = j;
        for (k = j + 1; k < n ; k++) // finding of the minimum element
            if (*(arr + k) < *(arr + min)) // in the array
                min = k;
        temp = *(arr + min); // swapping the value
        *(arr + min) = *(arr + j); // and arranging in ascending order
        *(arr + j) = temp;
        printf("\nPass %d: ", j + 1);
        print();
    }
    printf("\nPass %d: ", j + 1);
    print();
}
