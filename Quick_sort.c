#include<stdio.h>
#include<stdlib.h>

int *arr;

void input(int);
void output(int);
int partition(int, int, int);
void quick_sort(int, int, int);
void swap(int*, int*);

int main() {
    int n;
    char ch;
    do{
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);
        arr = (int*)malloc(n * sizeof(int));
        input(n);
        output(n);
        quick_sort(n, 0, n - 1);
        output(n);
        printf("\nDo you want to sort more arrays(y/n): ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');
}

void input(int n) {
    int i;
    printf("\nEnter the %d elements of the array: ", n);
    for ( i = 0; i < n ; i++ )
        scanf("%d", arr + i);
}

void output(int n) {
    int i;
    printf("\nThe array is: ");
    for ( i = 0; i < n; i++) 
        printf("%d ", *(arr + i));
}

void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

//function to split all the elements of the array
int partition(int n, int low, int high){
    int j; 
    int pivot = *(arr + high); // last element of the array
    int i = low - 1;
    for (j = low; j <= high - 1; j++) {
        if (*(arr + j) < pivot) { // if current element is lower than the pivot element
            i++; // increment the index of smaller element
            swap((arr + i), (arr + j)); // swap the values
        }
    }
    swap((arr + i + 1), (arr + high)); // swap the last values
    return (i + 1);
}

void quick_sort(int n, int low, int high) {
    if (low < high) {
        int p = partition(n, low, high); // placing the pivot at right place
        printf("\nPass: ");
        output(n);
        quick_sort(n, low, p - 1); // sort elements before and after
        quick_sort(n, p + 1, high); // partition
    }
}