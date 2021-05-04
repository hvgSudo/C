#include<stdio.h>
#include<stdlib.h>

int i, n, *array;

void sort();
void linear_search(int);
int binary_search_iterative(int);
int binary_search_recursive(int, int, int, int);

int main() {
    char c;
    int choice, ret, ele;
    int start, end, mid = 0;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    start = 0;
    end = n - 1;
    array = (int*)malloc(n * sizeof(int));
    printf("\nEnter the %d elements of the array: ", n);
    for (i = 0; i < n; i++) 
        scanf("%d", array + i);
    printf("\n\nThe array has been sorted\n");
    sort();
    do {
        printf("\n1. Linear Search");
        printf("\n2. Binary Search Iterative");
        printf("\n3. Binary Search Recursive");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the element you want to search: ");
                scanf("%d", &ele);
                printf("\n\nThe array is: ");
                for (i = 0; i < n; i++)
                    printf("%d ", *(array + i));
                linear_search(ele);
                break;
            case 2:
                printf("\nFor multiple occurrence it gives the index of the first occurring element");
                printf("\nEnter the element you want to search: ");
                scanf("%d", &ele);
                printf("\n\nThe array is: ");
                for (i = 0; i < n; i++)
                    printf("%d ", *(array + i));
                ret = binary_search_iterative(ele);
                if (ret != -1)
                    printf("\n%d found at %d index", ele, ret);
                else
                    printf("\n%d not found in the array", ele);
                break;
            case 3:
                printf("\nFor multiple occurrence it gives the index of the first occurring element");
                printf("\nEnter the element you want to search: ");
                scanf("%d", &ele);
                printf("\n\nThe array is: ");
                for (i = 0; i < n; i++)
                    printf("%d ", *(array + i));
                ret = binary_search_recursive(ele, start, end, mid);
                if (ret != -1)
                    printf("\n%d found at %d index", ele, ret);
                else
                    printf("\n%d not found in the array", ele);
                break;
            default:
                printf("\nWrong choice");
        }
        printf("\n\nDo you want to do it again(y/n): ");
        fflush(stdin);
        scanf("%c", &c);
    }while(c == 'y' || c == 'Y');
    return 0;
}

void sort() {
    int j, temp = 0;
    for (i = 0; i < n; i++) 
        for (j = i + 1; j < n; j++) {
            if (*(array + i) > *(array + j)) {
                temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }
        }
}

void linear_search(int ele) {
    int c = 0;
    for (i = 0; i < n; i++) {
        if (ele == *(array + i)) {
            printf("\n%d found at %d index", ele, i);
            c = c + 1;
        }
    }
    if (i == n && c == 0)
        printf("\n%d not found in the array", ele);
}

int binary_search_iterative(int ele) {
    int start = 0, end = n - 1;
    int mid = 0;
    while (start <= end) {
        mid = (start + end) / 2;
        if (ele == *(array + mid))
            return mid;
        else if (ele > *(array + mid))
            start = mid + 1;
        else
            end  = mid - 1;
    }
    return -1;
}

int binary_search_recursive(int ele, int start, int end, int mid) {
    if (start <= end) {
        mid = (start + end) / 2;
        if (ele == *(array + mid))
            return mid;
        else if (ele > *(array + mid)) {
            start = mid + 1;
            return binary_search_recursive(ele, start, end, mid);
        } else {
            end = mid - 1;
            return binary_search_recursive(ele, start, end, mid);
        }
    }
    return -1;
}