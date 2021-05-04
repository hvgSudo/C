#include <stdio.h>

void ascending(int*);
void descending(int*);

int main()
{
    int i, j, b = 0;
    int a[5];
    printf("\nEnter 5 elements - ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    ascending(&a[0]);
    printf("Array in ascending order: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    descending(&a[0]);
    printf("\nArray in descending order: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    return 0;
}

void ascending(int *asc) {
    int i, j, b = 0;
    for (i = 0; i < 5; i++) 
        for (j = i + 1; j < 5; j++) {
            if (*(asc + i) > *(asc + j)) {
                b = *(asc + i);
                *(asc + i) = *(asc + j);
                *(asc + j) = b;
            }
        }
}

void descending(int *desc) {
    int i, j, b = 0;
    for (i = 0; i < 5; i++)
        for (j = i + 1; j < 5; j++) {
            if (*(desc + i) < *(desc + j)) {
                b = *(desc + i);
                *(desc + i) = *(desc + j);
                *(desc + j) = b;
            }
        }
}