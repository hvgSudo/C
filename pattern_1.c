#include<stdio.h>

int main()
{
    int x, y, n, len, f = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    len = 2 * n - 1;
    for (int j = 0; j < len; j++)
        printf("%d ", n);
    printf("\n");
    for (int i = 0; i < n - 1; i++)
    
    { 
        for (int j = 0; j <= i + 1; j++)
        {
            x = n - j;
            if (x == 1)
                f = f + 1;
            if (x != 0 && f != 2)
            {
                y = x;
                printf("%d ", x);
            }
        }
        for (int j = i; j <= n - i; j++)
            printf("%d ", y);
        for (int j = i; j >= 0; j--)
        {
            x = n - j;
            printf("%d ", x);
        }
        printf("\n");
    }
    for (int j = 0; j < len; j++)
        printf("%d ", n);
    return 0;
}