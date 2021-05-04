#include<stdio.h>

int i, j, d[3][3];

void transpose(int m, int n, int e[][n]) {
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            d[i][j] = e[j][i];
}

int main() {
    int a[3][3], n, m;
    printf("Enter rows: ");
    scanf("%d", &m);
    printf("Enter columns: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < m; i++)
        for (j = 0; i < n; j++)
            scanf("%d", &a[i][j]);
    
    for (i = 0; i < m; i++) {
        printf("\n");
        for (j = 0; j < n; j++) 
            printf(" %d ", a[i][j]);
    }
    transpose(m, n, a);
    for (i = 0; i < m; i++) {
        printf("\n");
        for (j = 0; j < n; j++)
            printf(" %d ", d[i][j]);
    }
}