#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int n, i;
    n = 5;
    printf("Enter number of elements: %d\n", n);

    ptr = (int *)malloc(n * sizeof(int));
    printf("\nThe elements of the array are: ");
    for (i = 0; i < n; ++i)
    {
        printf("%d, ", ptr[i]);
    }
    for (i = 0; i < n; ++i)
    {
        ptr[i] = i + 1;
    }

    printf("\nThe elements of the array are: ");
    for (i = 0; i < n; ++i)
    {
        printf("%d, ", ptr[i]);
    }

    return 0;
}