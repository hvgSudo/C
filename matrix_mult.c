#include<stdio.h>
int i, j, max = 20;
void multiplication(int m, int n, int a[][max], int p, int q, int b[][max], int mult[][max])
{
    static int l = 0, o = 0, k = 0;
    int add = 0;
    if (l >= m)
        return;
    if (o < q)
    {
        if (k < n)
        {
            mult[l][o] += a[l][k] * b[k][o];
            k += 1;
            multiplication(m, n, a, p, q, b, mult);
        }
        k = 0;
        o += 1;
        multiplication(m, n, a, p, q, b, mult);
    }
    o = 0;
    l += 1;
    multiplication(m, n, a, p, q, b, mult);
}

int main() {
    int a[max][max], b[max][max], mult[max][max];
    int m, n, p, q;
    printf("\nEnter the number of rows in matrix 1: ");
    scanf("%d", &m);
    printf("\nEnter the number of columns in matrix 1: ");
    scanf("%d", &n);
    printf("Enter elements of the matrix 1: ");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("\nEnter the number of rows in matrix 2: ");
    scanf("%d", &p);
    printf("\nEnter the number of columns in matrix 2: ");
    scanf("%d", &q);
    printf("Enter elements of the matrix 2: ");
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
            scanf("%d", &b[i][j]);
    for (i = 0; i < m; i++)
        for (j = 0; j < q; j++)
            mult[i][j] = 0;
    if (n == p)
    {
        if (m > p)
        {
            for (i = 0; i < m; i++)
            {
                printf("\n");
                for (j = 0; j < n; j++)
                    printf("%d  ", a[i][j]);
                printf("\t");
                for (j = 0; j < q; j++)
                    if (i < p)
                        printf("%d  ", b[i][j]);
            }
            multiplication(m, n, a, p, q, b, mult);
            printf("\nProduct: \n");
            for (i = 0; i < m; i++)
            {
                fflush(stdin);
                for (j = 0; j < q; j++)
                    printf("%d  ", mult[i][j]);
                printf("\n");
            }
        }
        else
        {
            for (i = 0; i < p; i++)
            {
                printf("\n");
                for (j = 0; j < n; j++)
                    if (i < m)
                        printf("%d  ", a[i][j]);
                printf("\t");
                for (j = 0; j < q; j++)
                    printf("%d  ", b[i][j]);
            }
            multiplication(m, n, a, p, q, b, mult);
            printf("\nProduct: \n");
            for (i = 0; i < m; i++)
            {
                fflush(stdin);
                for (j = 0; j < q; j++)
                    printf("%d  ", mult[i][j]);
                printf("\n");
            }
        }
    }
    else
    {
        printf("\nMatrix multiplication not possible");
    }
    return 0;
}