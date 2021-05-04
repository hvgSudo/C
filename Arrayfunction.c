#include<stdio.h>
int *array(int *, int);
int main()
{
    int i, *var, a[10], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    var = array(a, n);
    for (i = 0; i < n; i++)
    {
        printf("Element %d = %d\t", i+1, var[i]);
    }
    return 0;
}
int *array(int *a, int n)
{
    int i;
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    return (a);
}