#include <stdio.h>

int c = 0;

void print(int n, int array[]) {
    int i;
    c = c + 1;
    printf("\nPass %d: ", c);
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
}

void merging(int n, int array[], int start, int middle, int end) {
    int index_1, index_2, i, b[20];
    for (index_1 = start, index_2 = middle + 1, i = start; index_1 <= middle && index_2 <= end; i++) {
        if (array[index_1] <= array[index_2])
            b[i] = array[index_1++];
        else
            b[i] = array[index_2++];
    }
    while (index_1 <= middle)
        b[i++] = array[index_1++];

    while (index_2 <= end)
        b[i++] = array[index_2++];

    for (i = start; i <= end; i++)
        array[i] = b[i];
    print(n, array);
}

void divide(int n, int array[], int start, int end) {
    int middle;
    if (start < end) {
        middle = (start + end) / 2;
        divide(n, array, start, middle);
        divide(n, array, middle + 1, end);
        merging(n, array, start, middle, end);
    }
    else
        return;
}

int main() {
    int i, n, array[20];
    char ch;
    do {
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &n);
        printf("\nEnter the elements of the array: ");
        for (i = 0; i < n; i++)
            scanf("%d", &array[i]);
        printf("\nBefore sorting");
        printf("\nThe array is: ");
        for (i = 0; i < n; i++)
            printf("%d ", array[i]);
        printf("\n\n");
        divide(n, array, 0, n - 1);
        printf("\n\nAfter sorting");
        printf("\nThe array is: ");
        for (i = 0; i < n; i++)
            printf("%d ", array[i]);
        printf("\nDo you want to start again(y/n): ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');
    return 0;
}