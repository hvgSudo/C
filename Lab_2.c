#include<stdio.h>

int i;

void main() {
    int n, array[20], element, pos, count, t;
    printf("Enter the size of the array(upto 20): ");
    scanf("%d", &n);
    printf("Enter the array(upto %d): ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("\nEnter the element you want to insert: ");
    scanf("%d", &element);
    printf("\nEnter the position at which you want to insert: ");
    scanf("%d", &pos);
    count = pos;
    for (i = 0; i < n - pos; i++) {
        t = array[pos + 1];
        array[pos + 1] = array[pos];
        array[pos + 2] = t;
        count++;
    }
    array[pos - 1] = element;
    printf("\nThe array is: ");
    for (i = 0; i < count; i++) {
        printf(" %d ", array[i]);
    }
}