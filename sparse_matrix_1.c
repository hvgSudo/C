#include<stdio.h>

int main() {
    int a[3][3], i, j, k = 0;
    for (i = 0; i < 3; i++) 
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    /*for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (a[i][j] != 0)
                size = size + 1;*/
    int b[10][3];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            if (a[i][j] != 0) {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    printf("\n");
    for (i = 0; i < k; i++) {
        for (j = 0; j < 3; j++)
            printf("%d  ", b[i][j]);
        printf("\n");
    }
    return 0;
}