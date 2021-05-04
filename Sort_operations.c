// Sorting in ascending order using bubble, insertion and selection sort

#include <stdio.h>
#include <stdlib.h>

int n, i, *arr;

void read() {
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("\nEnter the %d elements of the array: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
}

void print() {
    printf("\nThe array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", *(arr + i));
}

void bubble_sort();
void insertion_sort();
void selection_sort();

int main() {
    int ret, choice;
    char ch;
    do {
        printf("\n\nSorting will be done in ascending order");
        printf("\n1. Bubble sort");
        printf("\n2. Insertion sort");
        printf("\n3. Selection sort");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                read();
                bubble_sort();
                printf("\nThe array has been sorted\n");
                print();
                break;
            case 2:
                read();
                insertion_sort();
                printf("\nThe array has been sorted\n");
                print();
                break;
            case 3:
                read();
                selection_sort();
                printf("\nThe array has been sorted\n"); 
                print();
                break;
            default:
                printf("\nWrong choice");
        }
        printf("\nDo you want to perform more operations(y/n): ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');
    return 0;
}

void bubble_sort() {
    int k, j, b = 0, c = 0;
    for (k = 0; k < n; k++) {
        c = c + 1;
        printf("\nPass %d: ", c);
        for (j = k + 1; j < n; j++) {
            if (*(arr + k) > *(arr + j)) {
                b = *(arr + k);
                *(arr + k) = *(arr + j);
                *(arr + j) = b;
            }
            print();
        }
    }
}

void insertion_sort() {
    int temp, j, k;
    for (j = 1; j < n; j++) {
        temp = *(arr + j);
        k = j - 1;
        while (k >= 0 && *(arr + k) > temp) { // finding the correct position of element 
            *(arr + k + 1) = *(arr + k); // in the array and creating space to insert it
            k = k - 1; // in the array
        }
        *(arr + k + 1) = temp; // inserting the element at the created position
        printf("\nPass %d: ", j);
        print();
    }
}

void selection_sort() {
    int temp, j, k, min;
    for (j = 0; j < n - 1; j++) {
        min = j;
        for (k = j + 1; k < n; k++)        // finding of the minimum element
            if (*(arr + k) < *(arr + min)) // in the array
                min = k;
        temp = *(arr + min);       // swapping the value
        *(arr + min) = *(arr + j); // and arranging in ascending order
        *(arr + j) = temp;
        printf("\nPass %d: ", j + 1);
        print();
    }
    printf("\nPass %d: ", j + 1);
    print();
}